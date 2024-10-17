#pragma once
#include<iostream>
using namespace std;
//ÓÐÏòÍ¼
class edgeNode {
public:
	int head;
	int tail;
	int weight = 0;
	edgeNode* nextIn;
	edgeNode* nextOut;
	edgeNode() {
		this->nextIn = NULL;
		this->nextOut = NULL;
	}
	edgeNode(int head, int tail, int weight) {
		this->head = head;
		this->tail = tail;
		this->weight = weight;
		this->nextIn = NULL;
		this->nextOut = NULL;
	}
};

template<class T>
class vertexNode {
public:
	T data;
	edgeNode* firstIn;
	edgeNode* firstOut;
	vertexNode() {
		this->firstIn = NULL;
		this->firstOut = NULL;
	}
	vertexNode(T t) {
		this->data = t;
		this->firstIn = NULL;
		this->firstOut = NULL;
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
	bool initGraphic();
	bool insertVertexNode(vertexNode<T>v);
	bool insertEdgeNode(edgeNode e);
	void traverseVertex();
	void traverseEdge();
	bool deleteVertex(vertexNode<T> v);

	int searchVertex(vertexNode<T>& v);
	bool deleteEdge(edgeNode e);
	void traverseDFS(bool (*visit)(vertexNode<T>n));
	void traverseBFS(bool (*visit)(vertexNode<T>n));
	void traverseCursion(int pos, bool (*visit)(vertexNode<T>n), int* flag);

	bool searchEdge(edgeNode& e);
	int getVertexCount();
	int getEdgeCount();
};


