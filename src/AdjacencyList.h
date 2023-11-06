#pragma once
#include <map>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using std::string;
using std::vector;
using std::map;

//Declaration of the AdjacencyList class
class AdjacencyList {
	map<string, vector<string>> adjTo;
	map<string, vector<string>> adjFrom;

public:
	AdjacencyList();
	~AdjacencyList();
	void addVertexFrom(std::string vertex);
	void addVertexTo(string vertex);
	bool inGraphFrom(string vertex);
	bool inGraphTo(string vertex);
	void addFrom(string from, string to);
	void addTo(string from, string to);
	void pageRank(int powers);
	vector<string> testOut(int powers);
};