from os import listdir
from collections import defaultdict
import networkx as nx
import random
import operator
import time

import itertools
from configuration import *
from terms import *

def generate_nx_network(V, E, typ):
	'''
		Generates networkx networks
		Input:
			V (int):	Number of nodes
			E (float):	Edge density
			typ (str):	"scale-free", "mesh", or "random"
		Ouput:
			G (networkx object)
	'''
	if typ == "scale-free":
		G = nx.barabasi_albert_graph(V, E)	# scale-free network
	elif typ == "mesh":
		G = nx.gnp_random_graph(V, 1)	# mesh network
	else:
		G = nx.gnp_random_graph(V, E)	# random network

	return G

def generate_network(V, E, D, typ="random", cutoff=CUTOFF):
	'''
		Generates a physical topology
		Input:
			V (int):		Number of nodes
			E (float):		Edge density
			typ (str):		"scale-free", "mesh", or "random"
			cutoff (int):	Maximum path length
		Ouput:
			G (PhysicalNetwork)
	'''
	Gx = generate_nx_network(V, E, typ)
	G = PhysicalNetwork(dict(Gx.adj), D, cutoff)
	print Gx.adj
	return G

def generate_demands(D, V, max_traffic=MAX_TRAFFIC_DEMAND, max_latency=CUTOFF):
	'''
		Generates service overlay
		Input:
			S (int):					Number of services
			max_resource (float):		Maximum resource demand for services
			max_traffic (float):		Maximum traffic demand for demands
			max_latency (int):			Maximum latency requirement
		Ouput:
			O (ServiceOverlay)
	'''

	hosts = []

	while D > 0:

		talker, listener = random.randint(0, V - 1), random.randint(0, V - 1)

		if talker != listener and (talker, listener) not in hosts:
			hosts.append((talker, listener))
			D -= 1

	demands = [Demand(p, random.choice(SERVICE_TYPE), round(random.uniform(0.0, max_traffic), 2), random.randint(2, max_latency)) for p in hosts]

	return demands

def generate_scenario(V, E, D, typ):
	'''
		Generates a topology and a sevice overlay
	'''	
	D = generate_demands(D, V)
	G = generate_network(V, E, D, typ)

	refresh()
	return (G, D)

