#include"tree.h"
#include<queue>
template<class T>
bool visit(node<T>n) {
    cout << n.data << endl;
    return true;
}

template<class T>
void tree<T>::insertNode(node<T> n) {
	if (this->root == NULL) {
		this->root = new node<T>;
		root->data = n.data;
		root->lchild = NULL;
		root->rchild = NULL;
		root->lTag = 0;
		root->rTag = 0;
		return;
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
            temp->lTag = 0;
            temp->rTag = 0;
            return;
        }
        else {
            q.push(temp->lchild);
        }
        if (temp->rchild == nullptr) {
            temp->rchild = new node<T>;
            temp->rchild->data = n.data;
            temp->rchild->lchild = NULL;
            temp->rchild->rchild = NULL;
            temp->lTag = 0;
            temp->rTag = 0;
            return;
        }
        else {
            q.push(temp->rchild);
        }
    }

}

template<class T>
void tree<T>::treeTraversePreorder(node<T>* r, bool (*visit)(node<T>n)) {
    if (r == NULL)return;
    visit(*r);
    treeTraversePreorder(r->lchild, visit);
    treeTraversePreorder(r->rchild, visit);
}

template<class T>
void tree<T>::treeTraverseMidorder(node<T>* r, bool (*visit)(node<T>n)) {
    if (r == NULL)return;
    treeTraverseMidorder(r->lchild, visit);
    visit(*r);
    treeTraverseMidorder(r->rchild, visit);
}

template<class T>
void tree<T>::treeTraversePostorder(node<T>* r, bool (*visit)(node<T>n)) {
    if (r == NULL)return;
    treeTraversePostorder(r->lchild, visit);
    treeTraversePostorder(r->rchild, visit);
    visit(*r);
}

template<class T>
void tree<T>::inThreadPreorder01() {
    node<T>* temp = NULL;
    inThreadPreorder02(this->root, temp);
}
template<class T>
void tree<T>::inThreadPreorder02(node<T>* r, node<T>*& pre) {
    
    if (r != NULL) {
        if (r->lchild == NULL) {
            r->lchild = pre;
            r->lTag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = r;
            pre->rTag = 1;
        }
        pre = r;
        if(r->lTag == 0)//��ֹ��ת����Ϊ���ִ����r->lchild = pre֮���γ���һ����������������жϣ��ͻ������ѭ��
        inThreadPreorder02(r->lchild, pre);
        if(r->rTag == 0)//ԭ��ͬ��
        inThreadPreorder02(r->rchild, pre);
    }
}

template<class T>
void tree<T>::inThreadPreTra(bool (*visit)(node<T> n)) {
    node<T>* temp = this->root;
    while (temp) {
        visit(*temp);
        if (!temp->lTag) {
            temp = temp->lchild;
        }
        else {
            temp = temp->rchild;
        }
    }

}

template<class T>
void tree<T>::inThreadMidorder01() {
    node<T>* temp = NULL;
    inThreadMidorder02(this->root, temp);
}
template<class T>
void tree<T>::inThreadMidorder02(node<T>* r, node<T>*& pre) {
    //pre�ĳ�ʼֵΪNULL��ԭ���ǣ���������൱������������������Բ������ĵ�һ���ڵ�һ���������ӽڵ㣬��ǰ��һ���ǿա�
    //�ٺ��������Ƿ��һ���ڵ����������������ֻҪִ�й��м䲿�ֵĴ��룬�൱�ڶ�����ڵ�����˱���������Ҫ��pre����Ϊ����������Ľڵ�
    if (r != NULL) {
        inThreadMidorder02(r->lchild, pre);
        if (r->lchild == NULL) {
            r->lchild = pre;
            r->lTag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = r;
            pre->rTag = 1;
        }
        pre = r;
        inThreadMidorder02(r->rchild, pre);
    }
}

template<class T>
void tree<T>::inThreadMidTra(bool (*visit)(node<T> n)) {
    node<T>* temp = this->root;
    if (temp)while (temp->lchild)temp = temp->lchild;
    while (temp) {
        visit(*temp);
        if (temp->rTag)temp = temp->rchild;
        else {
            temp = temp->rchild;
            if (temp)while (temp->lchild && !temp->lTag)temp = temp->lchild;
        }
    }
}

template<class T>
void tree<T>::inThreadPostorder01() {
    node<T>* temp = NULL;
    inThreadPostorder02(this->root, temp);
}
template<class T>
void tree<T>::inThreadPostorder02(node<T>* r, node<T>*& pre) {
    
    if (r != NULL) {
        inThreadPostorder02(r->lchild, pre);
        inThreadPostorder02(r->rchild, pre);
        if (r->lchild == NULL) {
            r->lchild = pre;
            r->lTag = 1;
        }
        if (pre != NULL && pre->rchild == NULL) {
            pre->rchild = r;
            pre->rTag = 1;
        }
        pre = r;
    }
}

template<class T>
node<T>* tree<T>::getParent(node<T>* n) {
    node<T>* temp = NULL;
    std::queue<node<T>*>q;
    q.push(this->root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->lchild == n&&!temp->lTag || temp->rchild == n&&!temp->rTag)return temp;
        if (temp->lchild && !temp->lTag) {
            q.push(temp->lchild);
        }
        if (temp->rchild && !temp->rTag) {
            q.push(temp->rchild);
        }
    }

    return NULL;
}
template<class T>
node<T>* tree<T>::getFirst(node<T>* n) {
    while (n->lchild&&!n->lTag || n->rchild&&!n->rTag) {
        if (n->lchild)n = n->lchild;
        else n = n->rchild;
    }
    return n;
}

template<class T>
void tree<T>::inThreadPostTra(bool (*visit)(node<T> n)) {
    node<T>* temp = this->root;
    if (!temp) return;

    // �ҵ���һ���ڵ�
    while (temp->lchild&&!temp->lTag || temp->rchild&&!temp->rTag) {
        if (temp->lchild)temp = temp->lchild;
        else temp = temp->rchild;
    }

    while (temp) {
        visit(*temp);
        if (temp == this->root)temp = NULL;
        else {
            node<T>* parent = getParent(temp);
            if (temp == parent->rchild || (temp == parent->lchild && (!parent->rchild || parent->rTag)))temp = parent;
            else {
                temp = getFirst(parent->rchild);
            }
        }
    }
}


