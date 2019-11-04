
#include <vector>
#include <list>
#include <utility>
#include <iostream>
using std::list;
using std::make_pair;
using std::pair;
using std::vector;
/*
 * Basic graph representation of adjacency list, using stl vector and list.
 */
class Graph {

private:
	vector<list<pair<int, int>>> adjacencyList;
	int num_of_vertices;
	int num_of_negatives;
	bool isNegativeWeights;

public:
	enum GResult
	{
		OK,
		EdgeNotFound,
		NotAcyclicError,
		NotConnectedError,
		InvalidFileError,
		BadArgumentError,
		BadIndexError,
	};
	/* Maintenance Methods */

	Graph(int num_of_vertices=0);
	~Graph() = default;

	GResult addEdge(const int i,const int j,const int weight);
	GResult removeEdge(const int i,const int j);

	void displayGraph();

	GResult makeGraph(int num_of_vertices, vector<pair<int, int>> edges);
	GResult makeGraphFromFile(char* path);

	/* Functionality Methods */

	bool isCyclic();
	bool isBipartite();
	GResult runBFS();
	GResult runDFS();
	GResult getGSCC();
	GResult runTopologicOrder();
};
