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
	bool initStack();//�����ջ
	bool destroyStack();//����ջ��ʹ��ջ���ٴ���
	bool clearStack();//��ջ�ÿ�
	bool stackEmpty();//��ջ�գ��򷵻��棬���򷵻ؼ�
	int stackLength();
	bool getTop(T&elem);//��ջ���գ�����elem����ջ��Ԫ�أ��������棬���򷵻ؼ�
	bool push(T elem);//����elem
	bool pop(T& elem);//��ջ���գ���ɾ��ջ��Ԫ�أ�����elem����
	bool stackTraverse(bool (*visit)(T elem));//��ջ�׵�ջ������
	int stackCapacity();
};
