from collections import defaultdict
from statistics import stdev
from math import sqrt

import os
import random
import pprint
import pickle
import re

from configuration import *

def modify_iterator(path, margin):
	pattern =  r"(?P<rest>.*)_(?P<iterator>\d+).rp"

	for f in os.listdir(path):
		params = re.match(pattern, f)

		if params:
			i = int(params.group("iterator"))
			new_name = "%s_%d.rp" %(params.group("rest"), i + margin)
			os.rename(path + f, path + new_name)

def conf_int(lst):
	return 1.96*stdev(lst)/sqrt(len(lst))

def exclusive_random(bound, exclude=[]):
	'''
		Returns a random integer in [0, bound) that does not exist in exclude
		Inputs:
			bound (int)
			exclude (list(int))
	'''
	v = random.randint(0, bound - 1)

	if len(exclude) == bound:
		return None

	return v if v not in exclude else exclusive_random(bound, exclude)

def get_this(tup, itr, is_in=True):
	'''
		Return the element in tup which does (or not) exists in itr
	'''
	if (tup[0] in itr) == (tup[1] in itr):
		return None
	if is_in:
		return tup[0] if tup[0] in itr else tup[1]
	else:
		return tup[1] if tup[0] in itr else tup[0]

def write(text, fname=SUMMARY_FILE_NAME):
	if os.path.exists(SUMMARY_FILE_NAME):
		os.remove(SUMMARY_FILE_NAME)

	f = open(SUMMARY_FILE_NAME, "w")
	f.write(text)
	f.close()

def append(text, fname=SUMMARY_FILE_NAME):
	f = open(fname, "a")
	f.write(text)
	f.close()

def index_translator(indices, redundant=0):
	index = redundant
	index_size = len(indices)

	for i in range(index_size):
		x = indices[i][0]
		if x != 0:
			for j in range(i+1, index_size):
				x *= indices[j][1]
		index += x

	return index

