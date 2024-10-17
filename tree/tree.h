#pragma once
#include<iostream>
using namespace std;

template<class T>
class node {
public:
	node() {

	}
	node(T t) {
		this->data = t;
	}
	node<T>* lchild;
	T data;
	node<T>* rchild;
};

template<class T>
class tree {
public:
	node<T>* root;
	tree() {
		this->root = NULL;
	}
	bool treeClear();
	bool deleteTree(node<T>*n);
	bool insertNode(node<T>n);
	void treeTraverse(bool (*visit)(node<T> n));
	bool deleteNode(node<T>n);
	node<T>* searchNodeBFS(node<T>n);
	node<T>* searchNodeDFS(node<T>n);
	node<T>* searchNode(node<T>n, node<T>* root);
	node<T>* searchParentNode(node<T>* n, int& flag);
	int getCount();
	int getHeight(node<T>*R);
};