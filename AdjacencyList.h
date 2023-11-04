#pragma once

class AdjacencyList {
	map<string, vector<string>> graph;

public:
	AdjacencyList();
	~AdjacencyList();
	void addVertex(string vertex);
	void addEdge(string from, string to);
	bool inGraph(string vertex);
	void pageRank(int powers);
	void print();
};