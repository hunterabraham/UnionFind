#include <iostream>
#include <vector>
#include "Graph.h"
#include "UnionFind.h"
using namespace std;


class Student {
	friend ostream& operator<<(ostream &strm, const Student &stud) {
		return strm << "student(" << stud.id << ", " << stud.name << ")";
	}
	
	friend bool operator==(const Student &lhs, const Student &rhs) {
		return lhs.id == rhs.id;
	}
	
	friend bool operator!=(const Student &lhs, const Student &rhs) {
		return !(lhs == rhs);
	}
	
	public:
		Student() = default;
		Student(int id, string name):
			id(id), name(name) {
		}
	private:
		int id;
		string name;
};

int main() {
	Student marc(0, "Marc");
	Student kyle(1, "Kyle");
	Student hemant(2, "Hemant");
	Student shanmathi(3, "Shanmathi");
	Student kate(4, "Kate");
	vector<Student> vertices { marc, kyle, hemant, shanmathi, kate };
	vector<Edge<Student>> edges { { marc, kyle }, { marc, hemant }, { kyle,shanmathi }, { kyle, kate } };
	Graph<Student> graph(vertices, edges); //No cycle
	if(graph.containsCycle())
		cout << "The graph contains a cycle" << endl;
	else
		cout << "The graph does not contain a cycle" << endl;
	
	cout << "Adding an edge to the current graph" << endl;
	graph.addEdge( { hemant, shanmathi }); //cycle
	
	if(graph.containsCycle())
		cout << "The graph contains a cycle" << endl;
	else
		cout << "The graph does not contain a cycle" << endl;/* * Add your graph examples below */

}



