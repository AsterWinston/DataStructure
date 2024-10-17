
using namespace std;
#include<iostream>
#include<string>
#include"search.h"

int main() {
	BT t;
	t.BSTInsert(t.root, 10);
	t.BSTInsert(t.root, 1);
	t.BSTInsert(t.root, 20);
	system("pause");
	return 0;
}
