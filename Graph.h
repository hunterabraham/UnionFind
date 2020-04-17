#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
#include <utility>
#include <iostream>
#include "UnionFind.h"
template<typename T> using Edge = std::pair<T, T>;

template<typename T>class Graph {
	using Edge = std::pair<T, T>;
	
	private:
		std::vector<T> vertices;
		
		std::vector<Edge> edges;
	
	public:
		Graph(std::vector<T> v, std::vector<Edge> e):
			vertices(v), edges(e) {
		}
		
		void addEdge(Edge e) {
			edges.push_back(e);
		}
		;
		
		bool containsCycle();
};

template<typename T> bool Graph<T>::containsCycle() {
	UnionFind<T> uFind(vertices);
	for (Edge &e : edges) {
		SetUF<T> &xRoot = uFind.find(e.first);
		SetUF<T> &yRoot = uFind.find(e.second);
		if (xRoot == yRoot)
			return true;
		uFind.unionOp(xRoot, yRoot);
	}
	return false;
}



#endif
