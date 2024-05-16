import multiprocessing as mp
import networkx as nx
import operator
import pickle

from collections import defaultdict

from configuration import *

def generate_path(args):
	'''
		Path generation function for parallel compute
		Input:
			args (tuple):	Includes PhysicalNetwork object, source and destination node IDs,
							path generation function, and cutoff value
		Output:
			paths (list(MPath))  
	'''
	G, src, dst, typ, cutoff = args
	paths = [MPath(p) for p in list(PhysicalNetwork.functions[typ](nx.Graph(G), src, dst, cutoff=cutoff))]
	return paths

def refresh():
	'''
		Refreshes id counters
	'''
	Demand.i = 0
	Path.i = 0
	Node.i = 0
	Edge.i = 0 
	MPath.v.value = 0	

class Node:
	def __init__(self, ind):
		self.index = ind

	def __eq__(self, other): 
		return self.index == other.index

	def __hash__(self):
	    return hash(self.index)

	def __str__(self):
		return "Node %df" %(self.index)

class Demand:
	i = 0
	def __init__(self, hosts, service_type, data=0.0, latency=100):
		self.talker = hosts[0]
		self.listener = hosts[1]
		self.data = data
		self.service_type = service_type

		self.latency = latency
		self.index = Demand.i
		Demand.i += 1	

	def __eq__(self, other): 
		return self.index == other.index and self.data == other.data and self.talker == other.talker and self.listener == other.listener

	def __hash__(self):
	    return hash((self.index, self.data, self.latency, self.talker, self.listener))

	def __str__(self):
		return "Demand %d from %d to %d for data %f" %(self.index, self.talker, self.listener, self.data)

class Path(object):
	i = 0
	def __init__(self, path):
		self.path = path
		self.talker = path[0]
		self.listener = path[-1]
		self.edges = zip(path, path[1:]) if path else []
		self.cost = len(path) - 1
		self.index = Path.i
		self.capacity = 0
		Path.i += 1	

	def __eq__(self, other): 
		return self.index == other.index and self.talker == self.talker and self.listener == self.listener

	def __hash__(self):
	    return hash((self.index, self.listener, self.talker))

	def __str__(self):
		return str(self.index) + " => " + str(self.path)

class MPath(Path):
	v = mp.Value('i', 0)
	lock = mp.Lock()

	def __init__(self, path):
		super(MPath, self).__init__(path)
		with MPath.lock:
			self.index = MPath.v.value
			MPath.v.value += 1

class Edge:
	i = 0
	def __init__(self, hosts=(), capacity=LINK_CAPACITY, latency=1.0):
		self.capacity = capacity
		self.outgoing = hosts[0]
		self.incoming = hosts[1]
		self.index = Edge.i
		self.latency = latency
		Edge.i += 1	

	def __str__(self):
		return "Edge %d: %d -> %d" %(self.index, self.outgoing, self.incoming)

class PhysicalNetwork:
	functions = {
		"all_paths": nx.all_simple_paths,
		"shortest_paths": nx.all_shortest_paths
	}

	def __init__(self, G=[], D=[], path_cutoff=0):
		self.G = G
		self.g = [] # Adjacency matrix for network
		self.E = [] # Edges
		self.P = [] # Paths
		self.D = D

		self.node_size = len(G)
		self.cutoff = path_cutoff
		
		if G:
			#self.generate_paths(path_cutoff)
			self.generate_paths_threadless(path_cutoff)
			self.convert_adjacency() 

		self.edge_size = len(self.E)
		self.path_size = len(self.P)

		self.type = "generated"

	def convert_adjacency(self):
		'''
			Creates an adjacency matrix and creates link objects
		'''
		self.g = [[0 for _ in range(self.node_size)] for _ in range(self.node_size)]

		edges = []

		for k,v in self.G.items():
			for k1,v1 in v.items():
				self.g[k][k1] = 1	
				edges.append((k, k1))

		self.E = [Edge(e) for e in set(edges)]
		self.edge_size = len(self.E)

	def generate_paths(self, cutoff, typ='all_paths'):
		'''
			Multicore path generation
			Input:
				cutoff (int):	Maximum path length
				typ (str):		One of path generation functions in PhysicalNetwork.functions
		'''	
		args = [(self.G, demand.talker, demand.listener, typ, cutoff) for demand in self.D]
		# Distribute path generation between each host to different cores
		pool = mp.Pool()
		for paths in pool.map(generate_path, args):
			self.P += paths

		self.P.sort(key=operator.attrgetter('index'))

		pool.close()
		pool.join()   

	def generate_paths_threadless(self, cutoff, typ='all_paths'):

		generated_pairs = []

		for demand in self.D:
			pair = (demand.talker, demand.listener)

			if pair in generated_pairs:
				continue

			self.P += [Path(p) for p in list(PhysicalNetwork.functions[typ](nx.Graph(self.G), demand.talker, demand.listener, cutoff=cutoff))]
			generated_pairs.append(pair)

		self.P.sort(key=operator.attrgetter('index'))

	def group_paths(self):
		'''
			Groups paths w.r.t. end-hosts
			Output:
				groups (dict{(tuple(int)): list(Path)})
		'''
		groups = defaultdict(lambda: []) # per src-dest pairs

		for p in self.P:
			#print p 
			hosts = (p.talker, p.listener)
			groups[hosts].append(p)
		return groups

	def get_edge(self, hosts):
		for e in self.E:
			if hosts == (e.outgoing, e.incoming):
				return e
		return None

