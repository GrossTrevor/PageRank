#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include "AdjacencyList.h"
#include "AdjacencyList.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;

int main() {
	int lines = 0, powers = 0;
	string from = "", to = "";

	//Read in the number of lines and the number of powers
	cin >> lines;
	cin >> powers;

	//Create graph object
	AdjacencyList graph;

	//Read in the lines and add them to the graph
	for (int i = 0; i < lines; i++) {
		cin >> from;
		cin >> to;
		graph.addTo(from, to);
	}

	//Calculate the page ranks and print them
	graph.pageRank(powers);
}