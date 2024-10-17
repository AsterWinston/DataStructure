#include"search.h"

int BT::BSTInsert(BTNode*&root, int key) {
	if (root == NULL) {
		root = new BTNode;
		root->lchild = NULL;
		root->rchild = NULL;
		return 1;
	}
	else {
		if (key == root->key)return 0;
		else if (key < root->key)return BSTInsert(root->lchild, key);
		else return BSTInsert(root->rchild, key);
	}
}
