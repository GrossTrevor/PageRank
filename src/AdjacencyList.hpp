#include "AdjacencyList.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::find;

//Creates an empty adjacency list
AdjacencyList::AdjacencyList() {
	adjTo = map<string, vector<string>>();
	adjFrom = map<string, vector<string>>();
}

//Deletes the adjacency list
AdjacencyList::~AdjacencyList() {
	adjTo.clear();
	adjFrom.clear();
}

//Adds a vertex to the inverse adjacency list
void AdjacencyList::addVertexFrom(string vertex) {
	adjFrom[vertex] = vector<string>();
}

//Adds a vertex to the adjacency list
void AdjacencyList::addVertexTo(string vertex) {
	adjTo[vertex] = vector<string>();
}

//Checks if a vertex is in the inverse adjacency list
bool AdjacencyList::inGraphFrom(string vertex) {
	if (adjFrom.find(vertex) == adjFrom.end())
		return false;
	return true;
}

//Checks if a vertex is in the adjacency list
bool AdjacencyList::inGraphTo(string vertex) {
	if (adjTo.find(vertex) == adjTo.end())
		return false;
	return true;
}

//Adds an edge to the inverse adjacency list
void AdjacencyList::addFrom(string from, string to) {

	//Checks if either vertex is not in the graph
	if (!inGraphFrom(from))
		addVertexFrom(from);
	if (!inGraphFrom(to))
		addVertexFrom(to);

	//Checks if the edge already exists, and adds one if not
	if (find(adjFrom[to].begin(), adjFrom[to].end(), to) == adjFrom[to].end())
		adjFrom[to].push_back(from);
}

//Adds an edge to the adjacency list
void AdjacencyList::addTo(string from, string to) {

	//Checks if either vertex is not in the graph
	if (!inGraphTo(from))
		addVertexTo(from);
	if (!inGraphTo(to))
		addVertexTo(to);

	//Checks if the edge already exists, and adds one if not
	if (find(adjTo[from].begin(), adjTo[from].end(), to) == adjTo[from].end())
		adjTo[from].push_back(to);

	addFrom(from, to);
}

//Calculates the page rank for each vertex in the adjacency list
void AdjacencyList::pageRank(int powers) {
	map<string, float> rank;
	map<string, float> tempRank;

	//Initializes the page rank for each vertex...
	for (auto member: adjTo) {

		//...based on the number of vertices in the graph
		rank[member.first] = 1.00f / adjTo.size();
		tempRank[member.first] = 0.00f;
	}

	//Calculates the page rank for each vertex "powers" number of times
	for (int i = 0; i < powers - 1; i++) {
		for (auto member2: adjTo) {
			float sum = 0.00f;

			//Calculates the sum of the page rank of each vertex that points to the current vertex
			for (int j = 0; j < adjFrom[member2.first].size(); j++) {

				//Adds 1 / the number of vertices the current vertex points to * the page rank of the vertex that points to the current vertex
				sum += (1.00f / (adjTo[adjFrom[member2.first][j]].size())) * rank[adjFrom[member2.first][j]];
			}
			tempRank[member2.first] = sum;
		}

		//Sets the page rank of each vertex to the temporary page rank
		for (auto member3: adjTo) {
			rank[member3.first] = tempRank[member3.first];
		}
	}

	//Prints the page rank of each vertex
	for (auto member4: rank)
		cout << member4.first << " " << std::fixed << std::setprecision(2) << member4.second << endl;
}

//Page rank for test.cpp
vector<string> AdjacencyList::testOut(int powers) {
	map<string, float> rank;
	map<string, float> tempRank;
	vector<string> out;

	//Initializes the page rank for each vertex...
	for (auto member: adjTo) {

		//...based on the number of vertices in the graph
		rank[member.first] = 1.00f / adjTo.size();
		tempRank[member.first] = 0.00f;
	}

	//Calculates the page rank for each vertex "powers" number of times
	for (int i = 0; i < powers - 1; i++) {
		for (auto member2: adjTo) {
			float sum = 0.00f;
			for (int j = 0; j < adjFrom[member2.first].size(); j++) {

				//Adds 1 / the number of vertices the current vertex points to * the page rank of the vertex that points to the current vertex
				sum += (1.00f / (adjTo[adjFrom[member2.first][j]].size())) * rank[adjFrom[member2.first][j]];
			}
			tempRank[member2.first] = sum;
		}

		//Sets the page rank of each vertex to the temporary page rank
		for (auto member3 : adjTo) {
			rank[member3.first] = tempRank[member3.first];
		}
	}

	//Prints the page rank of each vertex
	for (auto member4: rank)
		out.push_back(member4.first + " " + std::to_string(roundf(roundf(member4.second * 1000.f) / 10.f) / 100.f).substr(0, 4));

	return out;
}