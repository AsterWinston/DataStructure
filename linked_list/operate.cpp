#include"linList.h"

template<class data>
void linList<data>::initList() {
	this->head = new node<data>;
	if (this->head == NULL)return;
	this->head->next = NULL;
	this->size = 0;
	cout << "init success" << endl;
}

template<class data>
void linList<data>::pushBack(node<data>n) {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	for (int i = 0; i < this->size; i++) {
		pnow = pnow->next;
	}
	node<data>* pnew = new node<data>;
	if (pnew == NULL)return;
	pnew->d = n.d;
	pnow->next = pnew;
	pnew->next = NULL;
	this->size++;
	cout << n.d << endl;
	cout << "pushback success" << endl;
}

template<class data>
void linList<data>::pushFront(node<data>n) {
	if (this->head == NULL)return;
	node<data>* pnew = new node<data>;
	if (pnew == NULL)return;
	pnew->d = n.d;
	pnew->next = this->head->next;
	this->head->next = pnew;
	this->size++;
	cout << n.d << endl;
	cout << "pushfront success" << endl;
}

template<class data>
void linList<data>::insertBack(node<data> n1, node<data> n2) {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	for (int i = 0; i < this->size; i++) {
		pnow = pnow->next;
		if (pnow->d == n1.d) {
			node<data>* pnew = new node<data>;
			if (pnew == NULL)return;
			pnew->d = n2.d;
			pnew->next = pnow->next;
			pnow->next = pnew;
			this->size++;
			cout << n2.d << endl;
			cout << "insertback success" << endl;
			return;
		}
	}

}

template<class data>
void linList<data>::listTraverse(bool (*visit)(node<data> n)) {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	for (int i = 0; i < this->size; i++) {
		pnow = pnow->next;
		visit(*pnow);
	}
}

template<class data>
ostream& operator<<(ostream& cout, const node<data>& n) {
	cout << n.d << endl;
	return cout;
}

template<class data>
bool visit(node<data> n) {
	cout << n;
	return true;
}

template<class data>
void linList<data>::insertFront(node<data> n1, node<data> n2) {
	if (this->head == NULL)return;
	node<data>*pnow = this->head;
	for (int i = 0; i < this->size - 1; i++) {
		pnow = pnow->next;
		if (pnow->next->d == n1.d) {
			node<data>*pnew = new node<data>;
			if (pnew == NULL)return;
			pnew->d = n2.d;
			pnew->next = pnow->next;
			pnow->next = pnew;
			this->size++;
			cout << n2.d << endl;
			cout << "insertfront success" << endl;
			return;
		}
	}
}

template<class data>
void linList<data>::deleteFront() {
	if (this->head == NULL||this->head->next==NULL)return;
	node<data>* pnow = this->head->next;
	this->head->next = pnow->next;
	//free(pnow);
	delete pnow;
	this->size--;
}

template<class data>
void linList<data>::deleteBack() {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	node<data>* ppre = pnow;
	while (pnow->next) {
		ppre = pnow;
		pnow = pnow->next;
	}
	ppre->next = NULL;
	delete pnow;
	this->size--;
}

template<class data>
void linList<data>::deletenode(node<data> n) {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	node<data>* delnode = NULL;
	for (int i = 0; i < this->size - 1; i++) {
		pnow = pnow->next;
		if (pnow->next->d == n.d) {
			delnode = pnow->next;
			pnow->next = delnode->next;
			delete delnode;
			this->size--;
			break;
		}

	}
}

template<class data>
int linList<data>::searchnode(node<data> n) {
	if (this->head == NULL)return 0;
	node<data>* pnow = this->head;
	int pos = 0;
	while (pnow->next) {
		pnow = pnow->next;
		pos++;
		if (pnow->d == n.d)break;
	}
	return pos;
}

template<class data>
void linList<data>::searchnode(int pos, node<data>& n) {
	if (this->head == NULL)return;
	node<data>* pnow = this->head;
	if (pos > this->size)return;
	for (int i = 0; i < pos; i++) {
		pnow = pnow->next;
	}
	n.d = pnow->d;
}

template<class data>
int linList<data>::listLength() {
	return this->size;
}

template<class data>
bool linList<data>::listEmpty() {
	if (this->size == 0)return true;
	return false;
}