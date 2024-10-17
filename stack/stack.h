#pragma once
#define initSize 10
#include<iostream>
using namespace std;

template<class T>
class stack {
public:
	T* base;
	T* top;
	int capacity;
	int size;
	stack() {
		this->base = NULL;
		this->size = NULL;
		this->size = 0;
		this->capacity = 0;
	}
	bool initStack();//构造空栈
	bool destroyStack();//销毁栈，使得栈不再存在
	bool clearStack();//把栈置空
	bool stackEmpty();//若栈空，则返回真，否则返回假
	int stackLength();
	bool getTop(T&elem);//若栈不空，则用elem返回栈顶元素，并返回真，否则返回假
	bool push(T elem);//插入elem
	bool pop(T& elem);//若栈不空，则删除栈顶元素，并用elem返回
	bool stackTraverse(bool (*visit)(T elem));//从栈底到栈顶遍历
	int stackCapacity();
};
