
using namespace std;
#include<iostream>
#include<string>
#include"tree.h"
#include"operate.cpp"

int main() {
	tree<int>t;
	t.treeClear();
	node<int>n1(10);
	t.insertNode(n1);
	node<int>n2(20);
	t.insertNode(n2);
	node<int>n3(30);
	t.insertNode(n3);
	node<int>n4(40);
	t.insertNode(n4);
	node<int>n5(50);
	t.insertNode(n5);
	
	t.treeTraverse(visit);

	node<int>n6(60);
	//t.deleteNode(n2);
	t.deleteNode(n1);
	t.deleteNode(n3);
	t.deleteNode(n4);
	t.deleteNode(n5);
	
	t.treeTraverse(visit);
	cout << "count:" << t.getCount() << endl;
	cout << "height:" << t.getHeight(t.root) << endl;
	system("pause");
	return 0;
}
