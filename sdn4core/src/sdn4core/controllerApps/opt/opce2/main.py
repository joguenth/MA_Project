import sys

from configuration import *
from scenario import *

if "numpy" in sys.modules:
	del sys.modules["numpy"]

from GD import *


import xml.etree.ElementTree as et

def construct_topo_xml(network_name):
	PREFIX = "{http://graphml.graphdrawing.org/xmlns}"
	root = et.parse(NETWORK_NAME + '.xml').getroot()
	graph = root.find(PREFIX + 'graph')
	NODE_SIZE = len(graph.findall(PREFIX + 'node'))

	#PREFIX = "{http://graphml.graphdrawing.org/xmlns}"
	#root = et.parse('/root/DynTssdn/SDN4CoRE/src/sdn4core/controllerApps/opt/' +network_name + '.xml').getroot()
	#graph = root.find(PREFIX + 'graph')
		
	size = len(graph.findall(PREFIX + 'node'))
	topo = [[0 for _ in range(size)] for _ in range(size)]

	for edge in graph.findall(PREFIX + 'edge'):
		src, dest = int(edge.get('source')), int(edge.get('target'))
		topo[src][dest] = 1
		topo[dest][src] = 1

	return topo
    
def convert_adj2dict(G):

	size = len(G)

	g = {}

	for i in range(size):
		g[i] = {}
		for j in range(size):
			if i != j:
				if G[i][j]:
					g[i][j] = {}

	return g

def optimize(demands, assigments):

	D = [Demand((d[1], d[2]), d[3], d[4], d[5]) for d in demands] # d[0] is index and automatically converted

	A = [(a[0], a[1]) for a in assigments]

	G_adj = construct_topo_xml(NETWORK_NAME) # in configuration file

	G = PhysicalNetwork(convert_adj2dict(G_adj), D, CUTOFF)

	p = GD(G, D, A) 

	p.prepare()
	p.solve()

	diag = p.get_diagnose()
	
	#p.diagnose()

	refresh()
	p.prob.cleanup(100)
	p.prob.end()
	del p

	return diag

