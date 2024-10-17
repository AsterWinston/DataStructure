
using namespace std;
#include<iostream>
#include<string>
#include"graphic.h"
#include"operate.cpp"
int main() {
	graphic<int>g;
	g.initGraphic();
	g.insertVertexNode(vertexNode<int>(10));
	g.insertVertexNode(vertexNode<int>(20));
	g.insertVertexNode(vertexNode<int>(30));
	g.insertVertexNode(vertexNode<int>(40));
	g.insertVertexNode(vertexNode<int>(50));
	g.insertVertexNode(vertexNode<int>(60));
	g.insertVertexNode(vertexNode<int>(70));
	g.insertVertexNode(vertexNode<int>(80));
	g.insertVertexNode(vertexNode<int>(90));
	g.insertVertexNode(vertexNode<int>(100));
	g.insertEdgeNode(edgeNode(0, 1, 10));
	g.insertEdgeNode(edgeNode(0, 2, 50));
	g.insertEdgeNode(edgeNode(0, 3, 30));
	g.insertEdgeNode(edgeNode(0, 4, 90));
	g.insertEdgeNode(edgeNode(0, 6, 30));
	g.insertEdgeNode(edgeNode(1, 2, 70));
	g.insertEdgeNode(edgeNode(1, 4, 10));
	g.insertEdgeNode(edgeNode(1, 5, 30));
	g.insertEdgeNode(edgeNode(2, 6, 10));
	g.insertEdgeNode(edgeNode(3, 7, 20));
	g.insertEdgeNode(edgeNode(4, 8, 30));
	g.insertEdgeNode(edgeNode(6, 9, 50));


	g.traverseEdgeNode(visit);
	g.traverseVertexNode(visit);
	//BFS(g,0);
	//Dijkstra(g, 0);
	//int** path = Floyd(g);
	//printpath(path, 0, 4);
	graphic<int> g_new = prim(g, 9);
	//g_new.traverseVertexNode(visit);
	g_new.traverseEdgeNode(visit);

	g_new = kruskal(g);
	//g_new.traverseVertexNode(visit);
	g_new.traverseEdgeNode(visit);

	system("pause");
	return 0;
}
