import xml.etree.ElementTree as et

# FILE PATHS
NETWORK_INPUT_DIR = "./../inputs/networks/"
OVERLAY_INPUT_DIR = "./../inputs/overlays/"
RESULT_DIR = "./results/"

SUMMARY_FILE_NAME = RESULT_DIR + "summary.txt"

# FIGURE PARAMETERS
# SCENARIO PARAMETERS

NETWORK_NAME = "getnet"

LINK_CAPACITY = 100.0		
 	

MAX_TRAFFIC_DEMAND = 3.0
MAX_RESOURCE_DEMAND = 2.0

CUTOFF = 8

PREFIX = "{http://graphml.graphdrawing.org/xmlns}"
root = et.parse(NETWORK_NAME + '.xml').getroot()
graph = root.find(PREFIX + 'graph')
NODE_SIZE = len(graph.findall(PREFIX + 'node'))

#PREFIX = "{http://graphml.graphdrawing.org/xmlns}"
#root = et.parse('/root/DynTssdn/SDN4CoRE/src/sdn4core/controllerApps/opt/' +NETWORK_NAME + '.xml').getroot()
#graph = root.find(PREFIX + 'graph')
#NODE_SIZE = len(graph.findall(PREFIX + 'node'))

    

# CAMPAIGN PARAMS
SERVICE_SIZE = 8
AVG_LINKS = 2.5
LINK_GEN_COEFF = AVG_LINKS/NODE_SIZE

FRACTION = 1e-8
DEPLOYED_L_BOUND = 1.0 - FRACTION
DEPLOYED_U_BOUND = 1.0 + FRACTION

INTENS_THRESHOLD = 1.5

#OPTIMUM_TOLERANCE = 1e-8
OPTIMUM_TOLERANCE = 1e-3
VALUE_TOLERANCE = 1e-8
THREADS = 50

FAIL_STATUS = [103, 114, 1222, 1217]

ITERATION = 2
TIME_LIMIT = 3600*24*5

DIVERSITY_FACTOR = 2

SERVICE_TYPE = range(8)

