# Brief Description of the program
UnionFind is a C++ class to detect cycles in graphs.

## Author
Hunter Abraham

# Organization
SetUF.h contains a data structure for each "Node" in the graph

UnionFind.h holds all nodes in the set. It has find(), a method to find the root of some set, beginning at a node x. find() uses
path compression to accelerate computation. 

Graph.h holds containsCycle() as well as a graph data structure. containsCycle() works by detecting if two nodes return the same root, if they do,
then there is a cycle in the graph


A demonstration of UnionFind.h is included in demo.cpp


# Compilation
To compile:
	`$ make`

# Running
To run: 
	`$ demo`

