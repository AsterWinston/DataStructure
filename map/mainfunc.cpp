
using namespace std;
#include<iostream>
#include<string>
#include"graphic.h"
#include"operate.cpp"

int main() {
	graphic<int>g;
	g.initGraphic();
	vertexNode<int>v1(10);
	vertexNode<int>v2(20);
	vertexNode<int>v3(30);
	vertexNode<int>v4(40);
	vertexNode<int>v5(50);
	vertexNode<int>v6(60);
	vertexNode<int>v7(70);
	vertexNode<int>v8(80);
	g.insertVertexNode(v1);
	g.insertVertexNode(v2);
	g.insertVertexNode(v3);
	g.insertVertexNode(v4);
	g.insertVertexNode(v5);
	g.insertVertexNode(v6);
	g.insertVertexNode(v7);
	g.insertVertexNode(v8);
	edgeNode e1(0, 1, 1);
	edgeNode e2(0, 2, 2);
	edgeNode e3(0, 3, 3);
	edgeNode e4(6, 4, 4);
	edgeNode e5(1, 2, 5);
	edgeNode e6(7, 3, 6);
	edgeNode e7(1, 4, 7);
	edgeNode e8(5, 3, 8);
	edgeNode e9(2, 4, 9);
	edgeNode e10(3, 4, 10);
	g.insertEdgeNode(e1);
	g.insertEdgeNode(e2);
	g.insertEdgeNode(e3);
	g.insertEdgeNode(e4);
	g.insertEdgeNode(e5);
	g.insertEdgeNode(e6);
	g.insertEdgeNode(e7);
	g.insertEdgeNode(e8);
	g.insertEdgeNode(e9);
	g.insertEdgeNode(e10);
	//e1.head = 1;
	//e1.tail = 1;
	//g.insertEdgeNode(e1);
	//g.traverseEdge();
	//g.deleteVertex(v1);
	//g.deleteVertex(v1);
	//cout << "old:" << endl;
	//g.traverseEdge();
	//cout << "new:" << endl;
	//g.deleteEdge(e1);
	//g.deleteEdge(e3);
	//g.deleteEdge(e5);
	//g.deleteEdge(e5);
	//g.traverseEdge();
	//g.traverseVertex();

	cout << "BFS:" << endl;
	g.traverseBFS(visit);
	cout << "edge:" << endl;
	g.traverseEdge();
	cout << "vertex:" << endl;
	g.traverseVertex();
	cout << "DFS:" << endl;
	g.traverseDFS(visit);

	system("pause");
	return 0;
}
