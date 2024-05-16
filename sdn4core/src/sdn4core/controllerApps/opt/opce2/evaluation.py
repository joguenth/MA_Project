from math import sqrt, log10
from statistics import mean
from os import listdir
import re
import operator

from collections import defaultdict
from tools import *
from GO import *
from GOF import *
from terms import PhysicalNetwork, ServiceOverlay
from configuration import *

def get_cost(report):
	cost = 0

	if not report:
		cost = 0

	if "cost" in report:
		cost += report["cost"]

	for k, v in report.items():
		if isinstance(v, dict):
			cost += get_cost(v)
	
	return cost

def failure_ratio(report, model, size):

	#print print_report(report)

	if model == "GOF":
		return FRACTION
	elif model == "GO":
		return 100.0
	elif model == "MLSP-R":
		if "heuristic" not in report:
			return FRACTION		
		return len(report["heuristic"]["deployed_services"])*100.0/size
	elif model == "MLSP+POBS":
		# Fully optimized
		if "MLSP" not in report:
			return FRACTION
		return (len(report["MLSP"]["deployed_services"]) - len(report["POBS"]["backup_services"]))*100.0/size
	elif model == "RDDP+BSRP":
		return len(report["BSRP"]["nonbackup_services"])*100.0/size

def process_report(model, node_size, service_size, iteration="", experiment=EXPERIMENT_TYPE):

	BASE = "/home/doganalp/Workspace/ergenc19resrouting/experiments/v2_results/result/intensiveness/"
	pattern = "(%s)_%s_G_%d_O_%d_%s"
	p = pattern %(model, experiment, node_size, service_size, iteration)

	if p + ".rp" in listdir(BASE):
		report = load_report(BASE + p)
	else:
		return None

	#cost = get_cost(report)
	cost = failure_ratio(report, model, service_size)

	return cost

def process_reports(experiment=EXPERIMENT_TYPE, models=OPTIM_TYPE):

	data = {}

	for o in models:
		model_result = {"mean": [], "conf_int": []}
		# Assuming either PARAM_NODES or PARAM_SERVICES is a list
		for v in PARAM_NODES:
			for s in PARAM_SERVICES:
				res = []
				for i in range(1, ITERATION):
					cost = process_report(o, v, s, i, experiment)
					if cost:
						res.append(cost)
				if res:
					model_result["mean"].append(mean(res)) 
					model_result["conf_int"].append(conf_int(res))
		data[o] = model_result

	return data

'''
# Work-around for threshold calculation
# TODO: Implement result processing for data-intensiveness threshold
def process_reports_T(experiment=EXPERIMENT_TYPE, models=OPTIM_TYPE):

	data = {}

	for o in models:
		model_result = {"mean": [], "conf_int": []}
		# Assuming either PARAM_NODES or PARAM_SERVICES is a list
		for t in PARAM_THRESHOLD:
			res = []
			for i in range(1, ITERATION):
				BASE = "/home/doganalp/Workspace/ergenc19resrouting/experiments/v2_results/result/intensiveness/"
				pattern = "(%s)_%s_G_%d_O_%d_t_%s_%d"
				p = pattern %(o, experiment, 10, 8, t, i)
				
				if p + ".rp" in listdir(BASE):
					report = load_report(BASE + p)
				else:
					continue

				#cost = get_cost(report)
				cost = failure_ratio(report, o, 8)
				if cost:
					res.append(cost)
			if res:
				model_result["mean"].append(mean(res)) 
				model_result["conf_int"].append(conf_int(res)/10)
		data[o] = model_result
	return data
'''

def preprocess_chart(data):

	x = PARAM_SERVICES
	#x = PARAM_NODES
	#x = [0.5, 1.0, 1.5, 2.0, 2.5]
	#xlb = "Number of demands"
	xlb = "Data-intensiveness threhold"
	#xlb = "Number of nodes"
	ylb = "Latency cost"
	#ylb = "Probability of service failure (%)"
	#ylb = "Solution time (h)"

	y = [(v["mean"], TRANS[k], v["conf_int"]) for k, v in data.items()]
	
	create_chart(x, xlb, y, ylb, "./results/intens_cost", err=True)

d = process_reports()
preprocess_chart(d)




