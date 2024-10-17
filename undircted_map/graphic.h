#pragma once
#include<iostream>
using namespace std;

//class edgeNode;
class edgeNode {
public:
	int weight;
	int t1;
	int t2;
	edgeNode* t1_next;
	edgeNode* t2_next;

	edgeNode() {
		this->t1_next = NULL;
		this->t2_next = NULL;
	}
	edgeNode(int t1, int t2, int weight) {
		this->t1 = t1;
		this->t2 = t2;
		this->weight = weight;
		this->t1_next = NULL;
		this->t2_next = NULL;
	}
};

template<class T>
class vertexNode {
public:
	T data;
	edgeNode* firstEdge;
	vertexNode() {

	}
	vertexNode(T data) {
		this->data = data;
		this->firstEdge = NULL;
	}
	bool operator==(vertexNode<T> n) {
		if (n.data == this->data && n.firstEdge == this->firstEdge)return 1;
		return 0;
	}
};

template<class T>
class graphic {
public:
	vertexNode<T>* arr;
	int capacity;
	int size;
	graphic() {
		this->arr = NULL;
		this->capacity = 0;
		this->size = 0;
	}

public:
	void initGraphic();
	void insertVertexNode(vertexNode<T> v);
	void insertEdgeNode(edgeNode e);
	void traverseVertexNode(void (*visit)(vertexNode<T> v));
	void traverseEdgeNode(void (*visit)(edgeNode e));
	int getIndex(vertexNode<T> v);
	int getEdgeCount();
};


void visit(edgeNode e);
void printpath(int** path, int i, int j);
void shellSort(edgeNode* arr, int n);
void Union(int* arr, int x, int y);
int Find(int* arr, int x);

template<class T>
void BFS(graphic<T> g, int index);

template<class T>
void Dijkstra(graphic<T> g, int index);

template<class T>
int** Floyd(graphic<T> g);

template<class T>
graphic<T> prim(graphic<T> g, int index);

template<class T>
graphic<T> kruskal(graphic<T> g);