#include"tree.h"
#include<queue>
template<class T>
bool tree<T>::treeClear() {
    if (this->root == NULL)return true;
    return deleteTree(this->root);
}
template<class T>

bool tree<T>::deleteTree(node<T>*n) {
    if (n == nullptr) {
        return true;
    }
    // 递归释放左子树
    if (n->lchild != nullptr) {
        deleteTree(n->lchild);
    }

    // 递归释放右子树
    if (n->rchild != nullptr) {
        deleteTree(n->rchild);
    }
    // 释放当前节点
    delete n;
    this->root = nullptr;
    return true;
}

template<class T>
bool tree<T>::insertNode(node<T>n) {
    if (this->root == nullptr) {
        this->root = new node<T>;
        this->root->data = n.data;
        return true;
    }
    std::queue<node<T>*> q;
    q.push(this->root);
    while (!q.empty()) {
        node<T>* temp = q.front();
        q.pop();
        if (temp->lchild == nullptr) {
            temp->lchild = new node<T>;
            temp->lchild->data = n.data;
            temp->lchild->lchild = NULL;
            temp->lchild->rchild = NULL;
            return true;
        }
        else {
            q.push(temp->lchild);
        }
        if (temp->rchild == nullptr) {
            temp->rchild = new node<T>;
            temp->rchild->data = n.data;
            temp->rchild->lchild = NULL;
            temp->rchild->rchild = NULL;
            return true;
        }
        else {
            q.push(temp->rchild);
        }
    }
    return false;
    
}

template<class T>
void tree<T>::treeTraverse(bool (*visit)(node<T> n)) {
    inorderTraversal(this->root, visit);
}

template<class T>
void inorderTraversal(node<T>* root, bool (*visit)(node<T> n)) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->lchild, visit);
    if (!visit(*root)) {
        return;
    }
    inorderTraversal(root->rchild, visit);
}

template<class T>
bool visit(node<T>n) {
    cout << n.data << endl;
    return true;
}

template<class T>
node<T>* tree<T>::searchNodeBFS(node<T>n) {
    if (this->root == NULL)return NULL;
    std::queue<node<T>*>q;
    q.push(this->root);
    node<T>* temp = NULL;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data == n.data)return temp;
        if (temp->lchild != NULL)q.push(temp->lchild);
        if (temp->rchild != NULL)q.push(temp->rchild);
    }
    return NULL;
}

template<class T>
node<T>* tree<T>::searchNodeDFS(node<T>n) {
    if (this->root == NULL)return NULL;
    return searchNode(n, this->root);
}

template<class T>
node<T>* tree<T>::searchNode(node<T>n, node<T>* root) {
    if (root == NULL)return NULL;
    if (root->data == n.data)return root;
    node<T>* temp = NULL;
    if ((temp = searchNode(n, root->lchild)) != NULL)return temp;
    if ((temp = searchNode(n, root->rchild)) != NULL)return temp;
    return temp;
}



template<class T>
node<T>* tree<T>::searchParentNode(node<T>*n, int& flag) {
    if (this->root == NULL)return NULL;
    node<T>* temp = NULL;
    std::queue<node<T>*>q;
    q.push(this->root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->lchild != NULL) {
            if (temp->lchild == n) {
                flag = 1;
                return temp;
            }
            q.push(temp->lchild);
        }
        if (temp->rchild != NULL) {
            if (temp->rchild == n) {
                flag = 2;
                return temp;
            }
            q.push(temp->rchild);
        }
    }
    return NULL;
}

template<class T>
bool tree<T>::deleteNode(node<T>n) {
    if (this->root == NULL)return false;
    node<T>* temp = searchNodeBFS(n);
    if (temp == NULL)return false;
    int flag = 0;
    node<T>* parent = searchParentNode(temp, flag);
    if (temp->lchild == NULL && temp->rchild == NULL) {
        if (parent == NULL) {
            this->root = NULL;
            return true;
        }
        if (flag == 1) {
            parent->lchild = NULL;
            delete temp;
            return true;
        }
        else {
            parent->rchild = NULL;
            delete temp;
            return true;
        }
    }
    else if (temp->lchild == NULL || temp->rchild == NULL) {
        if (parent == NULL) {
            if (temp->lchild == NULL) {
                this->root = temp->rchild;
                delete temp;
                return true;
            }
            else {
                this->root = temp->lchild;
                delete temp;
                return true;
            }
        }
        if (temp->lchild == NULL) {
            if (flag == 1) {
                parent->lchild = temp->rchild;
                delete temp;
                return true;
            }
            else {
                parent->rchild = temp->rchild;
                delete temp;
                return true;
            }
        }
        else {
            if (flag == 1) {
                parent->lchild == temp->lchild;
                delete temp;
                return true;
            }
            else {
                parent->rchild = temp->lchild;
                delete temp;
                return true;
            }

        }
    }
    else {
        node<T>* left = temp->rchild;
        while (left->lchild) left = left->lchild;
        int newFlag = 0;
        node<T>* leftParent = searchParentNode(left, newFlag);
        temp->data = left->data;
        if (newFlag == 1) {
            leftParent->lchild = left->rchild;
            delete left;
            return true;
        }
        else {
            leftParent->rchild = left->rchild;
            delete left;
            return true;
        }
    }
 
    return false;
}

template<class T>
int tree<T>::getCount() {
    if (this->root == NULL) {
        return 0;
    }
    int count = 0;
    node<T>* temp = NULL;
    std::queue<node<T>*>q;
    q.push(this->root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        count++;
        if (temp->lchild!=NULL) {
            q.push(temp->lchild);
        }
        if (temp->rchild!=NULL) {
            q.push(temp->rchild);
        }
    }
    return count;
}

template<class T>
int tree<T>::getHeight(node<T>*R) {
    if (R == NULL)return 0;
    if (R->lchild == NULL && R->rchild == NULL)return 1;
    int h1 = 0, h2 = 0;
    return (h1 = getHeight(R->lchild)) > (h2 = getHeight(R->rchild)) ? h1 + 1 : h2 + 1;
}
