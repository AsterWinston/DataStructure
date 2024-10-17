#pragma once
#include<iostream>
using namespace std;


template<class T>
class node {
public:

	node() {

	}
	node(T num) {
		this->data = num;
	}

	T data;
	node<T>* next;
};
template<class T>
class Queue {
public:
	node<T>* front;
	node<T>* rear;
public:
	Queue() {
		this->front = NULL;
		this->rear = NULL;
	}
	bool initQueue();
	bool destroyQueue();
	bool clearQueue();
	bool QueueEmpty();
	int QueueLenth();
	bool getHead(node<T>& n);//返回队头元素
	bool push(node<T>n);
	bool pop(node<T>& n);
	bool QueueTraverse(bool (*visit)(node<T> n));
};