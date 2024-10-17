#pragma once
#include<iostream>
using namespace std;
class BTNode {
public:
	int key;
	BTNode* lchild;
	BTNode* rchild;
};
class BT {
public:
	BTNode* root;
	BT() {
		this->root = NULL;
	}
	int BSTInsert(BTNode *&root, int key);
};
