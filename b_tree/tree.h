#pragma once
#include<iostream>
#define branch 5

template<class T>
class elememt {
public:
	T data;//or T* data;
	int key;
	elememt() {

	}
	elememt(T data, int key) {
		this->data = data;
		this->key = key;
	}
};

template<class T>
class node {
public:
	elememt e[branch - 1];
	node<T>* child[branch];
	int num;
	node() {

	}
	node(node n) {
		for (int i = 0; i < branch; i++) {
			child[i] = NULL;
		}
		this->num = 0;
	}
};