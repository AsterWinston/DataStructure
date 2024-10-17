
using namespace std;
#include<iostream>
#include<string>
#include"tree.h"
#include"operate.cpp"

int main() {
	node<int>n1(10);
	node<int>n2(20);
	node<int>n3(30);
	node<int>n4(40);
	node<int>n5(50);
	node<int>n6(60);
	tree<int>t;
	t.insertNode(n1);
	t.insertNode(n2);
	t.insertNode(n3);
	t.insertNode(n4);
	t.insertNode(n5);
	t.insertNode(n6);

	//t.treeTraversePreorder(t.root, visit);
	//t.inThreadPreorder01();
	//t.inThreadPreTra(visit);
	//t.treeTraverseMidorder(t.root, visit);
	//t.inThreadMidorder01();
	//t.inThreadMidTra(visit);
	t.treeTraversePostorder(t.root, visit);
	t.inThreadPostorder01();
	t.inThreadPostTra(visit);

	system("pause");
	return 0;
}
