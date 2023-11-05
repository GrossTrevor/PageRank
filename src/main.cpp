#include <iostream>
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

	cin >> lines;
	cin >> powers;

	AdjacencyList graph;

	for (int i = 0; i < lines; i++) {
		cin >> from;
		cin >> to;
		graph.addTo(from, to);
	}
	graph.pageRank(powers);
}