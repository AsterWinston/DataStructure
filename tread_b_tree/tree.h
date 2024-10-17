#pragma once
#include<iostream>
using namespace std;

template<class T>
class node {
public:
	T data;
	int lTag;
	int rTag;
	node<T>* lchild;
	node<T>* rchild;
	node() {
		this->lchild = NULL;
		this->rchild = NULL;
		this->lTag = 0;
		this->rTag = 0;
	}
	node(T data) {
		this->data = data;
		this->lchild = NULL;
		this->rchild = NULL;
		this->lTag = 0;
		this->rTag = 0;
	}
};
template<class T>
class tree {
public:
	node<T>* root;
	tree() {
		this->root = NULL;
	} 
	void insertNode(node<T> n);//完全二叉树插入法
	void treeTraversePreorder(node<T>* r, bool (*visit)(node<T> n));
	void inThreadPreorder01();
	void inThreadPreorder02(node<T>* r, node<T>* &pre);
	void inThreadPreTra(bool (*visit)(node<T> n));
	void treeTraverseMidorder(node<T>* r, bool (*visit)(node<T> n));
	void inThreadMidorder01();
	void inThreadMidorder02(node<T>* r, node<T>*& pre);
	void inThreadMidTra(bool (*visit)(node<T> n));
	void treeTraversePostorder(node<T>* r, bool (*visit)(node<T> n));
	void inThreadPostorder01();
	void inThreadPostorder02(node<T>* r, node<T>*& pre);
	void inThreadPostTra(bool (*visit)(node<T> n));
	node<T>* getParent(node<T>* n);
	node<T>* getFirst(node<T>* n);
};