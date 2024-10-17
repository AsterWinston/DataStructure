#pragma once
#include<iostream>
using namespace std;

template<class data>
class node {
public:
	data d;
	node<data>* next;
	
};

template<class data>
class linList {
private:
	node<data>* head;
	int size;
public:
	void initList();
	void pushBack(node<data> n);
	void pushFront(node<data> n);
	void insertBack(node<data> n1, node<data> n2);
	void insertFront(node<data> n1, node<data> n2);
	void deleteFront();
	void deleteBack();
	void deletenode(node<data> n);
	int searchnode(node<data> n);//返回位序
	void searchnode(int pos, node<data>& n);//返回指定位序的节点
	void listTraverse(bool (*visit)(node<data> n));
	int listLength();
	bool listEmpty();
};

//template<class data>
//ostream& operator<<(ostream& cout, const node<data>& n) {
//	cout << n.d << endl;
//	return cout;
//}
//
//template<class data>
//bool visit(node<data> n) {
//	cout << n;
//	return true;
//}
//
//template<class data>
//void linList<data>::initList() {
//	this->head = new node<data>;
//	if (this->head == NULL)return;
//	this->head->next = NULL;
//	this->size = 0;
//	cout << "init success" << endl;
//}
//
//template<class data>
//void linList<data>::pushBack(node<data>n) {
//	if (this->head == NULL)return;
//	node<data>* pnow = this->head;
//	for (int i = 0; i < this->size; i++) {
//		pnow = pnow->next;
//	}
//	node<data>* pnew = new node<data>;
//	if (pnew == NULL)return;
//	pnew->d = n.d;
//	pnow->next = pnew;
//	pnew->next = NULL;
//	this->size++;
//	cout << n.d << endl;
//	cout << "pushback success" << endl;
//}
//
//template<class data>
//void linList<data>::pushFront(node<data>n) {
//	if (this->head == NULL)return;
//	node<data>* pnew = new node<data>;
//	if (pnew == NULL)return;
//	pnew->d = n.d;
//	pnew->next = this->head->next;
//	this->head->next = pnew;
//	this->size++;
//	cout << n.d << endl;
//	cout << "pushfront success" << endl;
//}
//
//template<class data>
//void linList<data>::insertBack(node<data> n1, node<data> n2) {
//	if (this->head == NULL)return;
//	node<data>* pnow = this->head;
//	for (int i = 0; i < this->size; i++) {
//		pnow = pnow->next;
//		if (pnow->d == n1.d) {
//			node<data>* pnew = new node<data>;
//			if (pnew == NULL)return;
//			pnew->d = n2.d;
//			pnew->next = pnow->next;
//			pnow->next = pnew;
//			this->size++;
//			cout << n2.d << endl;
//			cout << "insertback success" << endl;
//			return;
//		}
//	}
//
//}
//
//template<class data>
//void linList<data>::listTraverse(bool (*visit)(node<data> n)) {
//	if (this->head == NULL)return;
//	node<data>* pnow = this->head;
//	for (int i = 0; i < this->size; i++) {
//		pnow = pnow->next;
//		visit(*pnow);
//	}
//}

