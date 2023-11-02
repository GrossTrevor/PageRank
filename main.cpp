#include <iostream>
#include <string>
#include <vector>
#include "Vertex.h"
#include "Vertex.hpp"
#include "AdjacencyList.h"
#include "AdjacencyList.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
	int lines = 0, powers = 0;
	string from = "", to = "";

	cin >> lines;
	cin >> powers;

	for (int i = 0; i < lines; i++) {
		cin >> from;
		cin >> to;
	}
}