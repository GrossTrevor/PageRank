#pragma once
#include <map>

class AdjacencyList {
	map<string, vector<string>> adjTo;
	map<string, vector<string>> adjFrom;

public:
	AdjacencyList();
	~AdjacencyList();
	void addVertexFrom(string vertex);
	void addVertexTo(string vertex);
	bool inGraphFrom(string vertex);
	bool inGraphTo(string vertex);
	void addFrom(string from, string to);
	void addTo(string from, string to);
	void pageRank(int powers);
	void print();
};