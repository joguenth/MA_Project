from cplex.exceptions import CplexError, CplexSolverError
from tools import index_translator
from terms import *
import cplex
import multiprocessing as mp
import itertools
import time
import pickle

from configuration import *

i_shared = mp.Value('i', 0)
lock = mp.Lock()

class GD(object):

	def __init__(self, G=None, D=None, A=None):
		self.x_dp = ["x_%d_%d" %(demand.index, path.index) for (demand, path) in itertools.product(D, G.P)]
		self.g_es = ["g_%d_%d" %(edge.index, service) for (edge, service) in itertools.product(G.E, SERVICE_TYPE)]
		self.g_es_size = len(self.g_es)
		self.x_dp_size = len(self.x_dp)
		self.G = G
		self.D = D
		self.A = A

		self.rows = []
		self.rhs = []
		self.sense = ""
		self.objective = []

		self.prob = cplex.Cplex()

		self.names = []

		self.type = "basic"

		self.z_size = 0
		self.Z = []
		self.z_transition = {}

		self.solved = 0
		self.solution_time = 0.0

		self.paths_per_hosts = self.G.group_paths() 

	def traffic_demand_constraint(self):

		for demand in self.D:
			var, mult = [], []
			hosts = (demand.talker, demand.listener)
			paths = self.paths_per_hosts[hosts]

			for path in paths:
		 		var.append(index_translator([(demand.index, 0), (path.index, self.G.path_size)]))
				mult.append(1)
				#print path
			#print paths
			#print var

			self.rows.append([var, mult])
			self.rhs.append(1)
			self.sense += "E"

	def link_capacity_constraint(self):

		for edge in self.G.E:
			var, mult = [], []
			link = (edge.outgoing, edge.incoming)
			link_reverse = link[::-1]
			for demand in self.D:
				hosts = (demand.talker, demand.listener)
				paths = self.paths_per_hosts[hosts]
				for path in paths:
					if link in path.edges or link_reverse in path.edges:
				 		var.append(index_translator([(demand.index, 0), (path.index, self.G.path_size)]))
						mult.append(demand.data)
			if var:
				self.rows.append([var, mult])
				self.rhs.append(edge.capacity)
				self.sense += "L"

	def gate_opening_constraint(self):

		for edge in self.G.E:
			var, mult = [], []
			for service_type in SERVICE_TYPE:
				var.append(index_translator([(edge.index, 0), (service_type, len(SERVICE_TYPE))], self.x_dp_size))
				mult.append(1)
			self.rows.append([var, mult])
			self.rhs.append(1)
			self.sense += "E"

	def latency_constraint(self):
		
		z_index = self.x_dp_size + self.g_es_size

		for demand in self.D:
			hosts = (demand.talker, demand.listener)
			paths = self.paths_per_hosts[hosts]

			for path in paths:

				var, mult = [], []
				x_dp_index = index_translator([(demand.index, 0), (path.index, self.G.path_size)])

				total_edge_delays = 0.0

				for edge in path.edges:
					# linearization terms

					e = self.G.get_edge(edge)

					g_es_index = index_translator([(e.index, 0), (demand.service_type, len(SERVICE_TYPE))], redundant=self.x_dp_size)

					xg_tuple = (x_dp_index, g_es_index)

					if xg_tuple not in self.z_transition:

						self.z_transition[xg_tuple] = z_index
						self.Z.append("z_%d" %(z_index))
						
						self.rows += [[[z_index, x_dp_index], [1.0, -1.0]],
							[[z_index, g_es_index], [1.0, -1.0]],
							[[z_index, g_es_index, x_dp_index], [1.0, -1.0, -1.0]]]
						self.rhs += [0, 0, -1.0]
						self.sense += "LLG"

						z_index += 1

					total_edge_delays += e.latency + 0.5

					var.append(self.z_transition[xg_tuple])
					mult.append(-0.5)

				var.append(x_dp_index)
				mult.append(total_edge_delays)

			self.rows.append([var, mult])
			self.rhs.append(demand.latency)
			self.sense += "L"

		self.z_size = len(self.Z)

	def gate_congestion_constraint(self):

		for edge in self.G.E:
			link = (edge.outgoing, edge.incoming)

			for service_type in SERVICE_TYPE:
				g_es_index = index_translator([(edge.index, 0), (service_type, len(SERVICE_TYPE))], redundant=self.x_dp_size)
				var, mult = [], []
				for demand in self.D:
					if demand.service_type == service_type:
						hosts = (demand.talker, demand.listener)
						paths = self.paths_per_hosts[hosts]
						for path in paths:
							if link in path.edges:
								x_dp_index = index_translator([(demand.index, 0), (path.index, self.G.path_size)])
								var.append(x_dp_index)
								mult.append(-demand.data * 1.0 / LINK_CAPACITY)

				var.append(g_es_index)
				mult.append(1)

				self.rows.append([var, mult])
				self.rhs.append(0)
				self.sense += "G"

	def assignment_constraint(self):

		for d_index, p_index in self.A:
			x_dp_index = index_translator([(d_index, 0), (p_index, self.G.path_size)])
			self.rows.append([[x_dp_index], [1]])
			self.rhs.append(1)
			self.sense += "G"

	def minimize_path_length_objective(self):
		# Latency minimization objective
		for path in self.G.P:
			self.objective.append(path.cost)

		self.objective = self.objective*len(self.D)
		self.objective += [0]*(self.g_es_size + self.z_size)
		self.prob.objective.set_sense(self.prob.objective.sense.minimize)

	def minimize_latency_objective(self):
		
		self.objective = [0 for _ in range(self.x_dp_size + self.g_es_size + self.z_size)]

		for demand in self.D:
			hosts = (demand.talker, demand.listener)
			paths = self.paths_per_hosts[hosts]

			for path in paths:

				var, mult = [], []
				x_dp_index = index_translator([(demand.index, 0), (path.index, self.G.path_size)])

				total_edge_delays = 0.0

				for edge in path.edges:

					e = self.G.get_edge(edge)

					g_es_index = index_translator([(e.index, 0), (demand.service_type, len(SERVICE_TYPE))], redundant=self.x_dp_size)

					xg_tuple = (x_dp_index, g_es_index)

					total_edge_delays += e.latency + 0.5

					self.objective[self.z_transition[xg_tuple]] = -0.5

				self.objective[x_dp_index] = total_edge_delays

		self.prob.objective.set_sense(self.prob.objective.sense.minimize)

	def add_constraints(self):
		print "Variable preparation starting..."
		self.traffic_demand_constraint()
		print "(1) Traffic demand constraint set added: ", len(self.rows)
		self.link_capacity_constraint()
		print "(2) Link capacity constraint set added: ", len(self.rows)
		self.gate_opening_constraint()
		print "(3) Gate opening constraint set added: ", len(self.rows)
		self.latency_constraint()
		print "(4) Latency constraint set added: ", len(self.rows)
		self.gate_congestion_constraint()
		print "(5) Gate congestion constraint set added: ", len(self.rows)
		self.assignment_constraint()
		print "(6) Assignment constraint set added: ", len(self.rows)
		self.minimize_latency_objective()
		#self.minimize_path_length_objective()
		print "Objective set."

		i_shared.value = 0
		refresh()

	def load(self):
		l_bound = [0]*(self.x_dp_size + self.g_es_size + self.z_size)
		u_bound = [1]*self.x_dp_size + [1.0002]*self.g_es_size + [1.0002]*self.z_size
		typ = "B"*self.x_dp_size + "C"*(self.g_es_size + self.z_size) 
		self.names = self.x_dp + self.g_es + self.Z
		self.prob.variables.add(obj=self.objective, lb=l_bound, ub=u_bound, types=typ, names=self.names)
		self.prob.linear_constraints.add(lin_expr=self.rows, senses=self.sense, rhs=self.rhs)

	def prepare(self):
		'''
			Create all constraints and load them into CPLEX object
		'''
		start = time.time()
		self.add_constraints()
		print "Constraints added in %f seconds." %(time.time() - start)

		start = time.time() 
		self.load()
		print "Load took %f seconds." %(time.time() - start)

	def solve(self):
		start = time.time()
		self.prob.parameters.timelimit.set(TIME_LIMIT)
		self.prob.parameters.threads.set(THREADS)
		self.prob.parameters.mip.tolerances.mipgap.set(OPTIMUM_TOLERANCE)

		try:		
			self.prob.solve()
			self.solved = 1
		except Exception as e:
			print e
		finally:
			self.solution_time = time.time() - start
			
		return self.prob

	def is_solved(self):
		print "Status: ", str(self.prob.solution.get_status()) 
		return self.solved and (self.prob.solution.get_status() not in FAIL_STATUS)

	def diagnose(self):

		constraint_size = self.prob.linear_constraints.get_num()
		var_size = self.prob.variables.get_num()

		slack = self.prob.solution.get_linear_slacks()
		x = self.prob.solution.get_values()

		for i in range(self.x_dp_size, self.x_dp_size + self.g_es_size):
			if x[i] > 1e-8:
				e_index, s_index = map(int, self.g_es[i - self.x_dp_size].split("_")[1:])
				print self.G.E[e_index]
				print self.g_es[i - self.x_dp_size] + ": " + str(x[i]) 

		print("-----")
		for i in range(self.x_dp_size):
			if x[i] > 1e-8:
				d_index, p_index = map(int, self.x_dp[i].split("_")[1:])
				print self.G.P[p_index]
				print self.x_dp[i] + ": " + str(x[i]) 

	def get_diagnose(self):

		constraint_size = self.prob.linear_constraints.get_num()
		var_size = self.prob.variables.get_num()

		slack = self.prob.solution.get_linear_slacks()
		x = self.prob.solution.get_values()
		
		gate_config=[]
		for i in range(self.x_dp_size, self.x_dp_size + self.g_es_size):
			if x[i] > 1e-8:
				e_index, s_index = map(int, self.g_es[i - self.x_dp_size].split("_")[1:])
				gcl = str(self.G.E[e_index])+ ": "+ str(self.g_es[i - self.x_dp_size]) + ": " + str(x[i]) 
				gate_config.append(gcl)

		path_assignment = []

		for i in range(self.x_dp_size):
			if x[i] > 1e-8:
				d_index, p_index = map(int, self.x_dp[i].split("_")[1:])
				path_assignment.append((d_index, x[i], self.G.P[p_index].path, p_index, gate_config))

		return path_assignment

	def print_constraints(self):
		for i in range(len(self.rows)):
			var = self.rows[i][0]
			mult = self.rows[i][1]
			print "%d => " %(i+1), 
			for j in range(len(var)):
				if type(var[j]) == int:
					print "%f.%s + " %(mult[j], self.names[var[j]]),  
				else:
					print "%f.%s + " %(mult[j], var[j]),  
			print "%s %f" %(self.sense[i], self.rhs[i])
		
