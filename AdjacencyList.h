#pragma once
#include "Vertex.h"

class AdjacencyList {
	vector<Vertex*> vertices;
	vector<vector<Vertex*>> edges;


public:
	AdjacencyList();
	~AdjacencyList();
	void addVertex(Vertex* vertex);
	void addEdge(Vertex* from, Vertex* to);
	bool inGraph(Vertex* vertex);
	void pageRank(int powers);
	void print();
};