#include "Graph.h"
#include <iostream>

int main() {
	int a = 0;
	Graph g(3);
	std::cout << "Hello!" << std::endl;

	Graph::GResult result;

	result = g.addEdge(1, 2, 0);
	result = g.addEdge(1, 3, 0);
	result = g.addEdge(4, 5, 0);

	g.displayGraph();

	std::cin >> a;
	return 0;

}