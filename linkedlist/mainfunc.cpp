using namespace std;
#include<iostream>
#include<string>
#include"linList.h"
#include"operate.cpp"
//#include"load.cpp"

int main() {
	linList<int>L;
	L.initList();
	node<int>n1;
	n1.d = 10;
	node<int>n2;
	n2.d = 20;
	node<int>& n3 = n2;
	L.pushBack(n1);
	L.pushFront(n1);
	L.insertBack(n1, n2);
	L.insertFront(n1, n2);
	cout << "pos:" << L.searchnode(n2) << endl;
	L.searchnode(1, n3);
	cout << "value:" << n3.d << endl;
	cout << "old:" << endl;
	L.listTraverse(visit);
	L.deleteFront();
	cout << "new1:" << endl;
	L.listTraverse(visit);
	L.deleteBack();
	cout << "new2:" << endl;
	L.listTraverse(visit); 
	L.deletenode(n2);
	cout << "new3:" << endl;
	L.listTraverse(visit);
	L.deleteBack();
	L.deleteBack();
	cout << "size:" << L.listLength() << endl;
	cout << "listempty:" << L.listEmpty() << endl;

	system("pause");
	return 0;
}
