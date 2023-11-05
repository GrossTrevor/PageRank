#include "AdjacencyList.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::map;
using std::find;

AdjacencyList::AdjacencyList() {
}

AdjacencyList::~AdjacencyList() {
}

void AdjacencyList::addVertexFrom(string name) {
	adjFrom[name] = vector<string>();
}

void AdjacencyList::addVertexTo(string name) {
	adjTo[name] = vector<string>();
}

bool AdjacencyList::inGraphFrom(string vertex) {
	if (adjFrom.find(vertex) == adjFrom.end())
		return false;
	return true;
}

bool AdjacencyList::inGraphTo(string vertex) {
	if (adjTo.find(vertex) == adjTo.end())
		return false;
	return true;
}

void AdjacencyList::addFrom(string from, string to) {
	if (!inGraphFrom(from))
		addVertexFrom(from);
	if (!inGraphFrom(to))
		addVertexFrom(to);

	if (find(adjFrom[to].begin(), adjFrom[to].end(), to) == adjFrom[to].end())
		adjFrom[to].push_back(from);
}

void AdjacencyList::addTo(string from, string to) {
	if (!inGraphTo(from))
		addVertexTo(from);
	if (!inGraphTo(to))
		addVertexTo(to);

	if (find(adjTo[from].begin(), adjTo[from].end(), to) == adjTo[from].end())
		adjTo[from].push_back(to);

	addFrom(from, to);
}

void AdjacencyList::pageRank(int powers) {
	map<string, float> rank;
	map<string, float> tempRank;

	for (auto member: adjTo) {
		rank[member] = 1.00f / adjTo.size();
	}

	for (int i = 0; i < powers; i++) {
		for (auto member2: adjTo) {
			float sum = 0.00f;
			for (int j = 0; j < adjFrom[member2.first].size(), j++) {
				sum += (1.00f / (adjTo[adjFrom[member2.first][j]].size())) * rank[adjFrom[member2.first][j]];
			}
			tempRank[member2.first] = sum;
		}
		for (auto member3: adjTo) {
			rank[member3.first] = tempRank[member3.first];
		}
	}

	for (auto member4: rank)
		cout << member4.first << " " << std::fixed << std::setprecision(2) << member4.second << endl;
}