#include "Graph.h"

int main()
{
	Graph* g = createGraph();

	Vertex* v1 = createVertex('1');
	Vertex* v2 = createVertex('2');
	Vertex* v3 = createVertex('3');
	Vertex* v4 = createVertex('4');
	Vertex* v5 = createVertex('5');

	addVertex(g, v1);
	addVertex(g, v2);
	addVertex(g, v3);
	addVertex(g, v4);
	addVertex(g, v5);

	addEdge(v1, createEdge(v1, v2, 0));
	addEdge(v1, createEdge(v1, v3, 0));
	addEdge(v1, createEdge(v1, v4, 0));
	addEdge(v1, createEdge(v1, v5, 0));

	addEdge(v2, createEdge(v2, v1, 0));
	addEdge(v2, createEdge(v2, v3, 0));
	addEdge(v2, createEdge(v2, v5, 0));

	addEdge(v3, createEdge(v3, v1, 0));
	addEdge(v3, createEdge(v3, v2, 0));

	addEdge(v4, createEdge(v4, v1, 0));
	addEdge(v4, createEdge(v4, v5, 0));

	addEdge(v5, createEdge(v5, v1, 0));
	addEdge(v5, createEdge(v5, v2, 0));
	addEdge(v5, createEdge(v5, v4, 0));

	printGraph(g);

	destroyGraph(g);

	return 0;
}