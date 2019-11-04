#include "Graph.h"


//Implemetations: 
Graph::Graph(int num_of_vertices) {
	this->num_of_vertices = num_of_vertices;
	this->num_of_negatives = 0;
	this->isNegativeWeights = false;
	this->adjacencyList = vector<list<pair<int, int>>>(num_of_vertices);
}

/*
 * Add the edge:
 * (i)--[weight]-->(j)
 */
Graph::GResult Graph::addEdge(const int i,const int j, const int weight) {
	if (i >= this->num_of_vertices || j >= this->num_of_vertices)return BadIndexError;

	this->adjacencyList[i].push_back(make_pair(j, weight));
	this->num_of_vertices++;
	if (weight < 0) {
		this->isNegativeWeights = true;
		this->num_of_negatives++;
	}
	return OK;
}
/*
 * Remove the edge (i,j)
 */
Graph::GResult Graph::removeEdge(const int i,const int j) {
	if (i >= this->num_of_vertices || j >= this->num_of_vertices)return BadIndexError;
	pair<int, int> edge;
	bool isFound = false;
	for (auto e : this->adjacencyList[i]) {
		if (e.first == j) {
			edge = e;
			isFound = true;
			break;
		}
	}
	if (!isFound)
		return EdgeNotFound;

	this->adjacencyList[i].remove(edge);
	//Deal with negatives:
	this->num_of_vertices--;
	if (edge.second < 0) {
		this->num_of_negatives++;
		if (this->num_of_negatives == 0)
			this->isNegativeWeights = false;
	}
	return OK;
}
/*
 * Print the adjacency list
 */
void Graph::displayGraph() {
	for (std::size_t i = 1; i < adjacencyList.size(); ++i) {
		printf("adjacencyList[%d] ", i);
		list< pair<int, int> >::iterator itr = adjacencyList[i].begin();
		while (itr != adjacencyList[i].end()) {
			printf(" -> %d(%d)", (*itr).first, (*itr).second);
			++itr;
		}
		printf("\n");
	}
}

Graph::GResult Graph::makeGraph(int num_of_vertices, vector<pair<int, int>> edges)
{
	if (num_of_vertices != this->num_of_vertices) return BadArgumentError;

	return OK;
}
