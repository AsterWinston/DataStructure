#include"seqList.h"

//ostream& operator<<(ostream& cout, const student& st) {
//	cout << "age:" << st.age << endl;
//	cout << "name:" << st.name << endl;
//	return cout;
//}
//lnk1169+lnk2005
template<class Elem>
seqList<Elem>::seqList() {
	this->capacity = initCapacity;
	this->size = 0;
	this->list = NULL;
}

template<class Elem>
void seqList<Elem>::initList() {
	this->size = 0;
	this->capacity = initCapacity;
	this->list = NULL;
	this->list = new Elem[initCapacity];
	if (this->list == NULL) {
		this->capacity = 0;
	}
}

template<class Elem>
void seqList<Elem>::destroyList() {
	if (this->list == NULL) {
		this->size = 0;
		this->capacity = 0;
		return;
	}

	//free(this->list);
	delete[] this->list;
	this->list = NULL;
	this->size = 0;
	this->capacity = 0;
}

template<class Elem>
void seqList<Elem>::clearList() {
	if (this->list == NULL) {
		this->size = 0;
		this->capacity = 0;
		return;
	}

	this->size = 0;
	this->capacity = initCapacity;
	delete[] this->list;
	this->list = NULL;
	this->list = new Elem[initCapacity];
	if (this->list == NULL) {
		this->capacity = 0;
	}
}

template<class Elem>
bool seqList<Elem>::listEmpty() {
	if (this->capacity == 0)return true;
	return false;
}

template<class Elem>
int seqList<Elem>::listLength() {
	return this->size;
}

template<class Elem>
void seqList<Elem>::getElem(int i, Elem& e) {
	if (i<1 || i>size)return;
	e = (this->list)[i - 1];
}

template<class Elem>
int seqList<Elem>::locateElem(Elem& e, bool (*compare)(Elem e1, Elem e2)) {
	for (int i = 0; i < this->size; i++) {
		if (compare((this->list)[i], e)) {
			return i + 1;
		}
	}
	return 0;
}

template<class Elem>
void seqList<Elem>::priorElelm(Elem cur_e, Elem& pre_e) {
	for (int i = 1; i < this->size; i++) {
		if ((this->list)[i] == cur_e) {
			pre_e = (this->list)[i - 1];
		}
	}
}

template<class Elem>
void seqList<Elem>::nextElem(Elem cur_e, Elem& next_e) {
	for (int i = 0; i < this->size - 1; i++) {
		if ((this->list)[i] == cur_e)
		{
			next_e = (this->list)[i + 1];
		}
	}
}

template<class Elem>
void seqList<Elem>::listInsert(int i, Elem e) {
	if (i<1 || i>size + 1)return;
	if (this->size >= this->capacity) {
		capacity += 10;
		Elem* oldlist = this->list;
		this->list = NULL;
		this->list = new Elem[capacity];
		if (this->list == NULL) {
			this->size = 0;
			this->capacity = 0;
			return;
		}
		for (int j = 0; j < this->size; j++) {
			(this->list)[j] = oldlist[j];
		}
		free(oldlist);
	}
	for (int pos = this->size; pos >= i; pos--) {
		(this->list)[pos] = (this->list)[pos - 1];
	}
	(this->list)[i - 1] = e;
	this->size++;
}

template<class Elem>
void seqList<Elem>::listDelete(int i, Elem& e) {
	if (i<1 || i>size)return;
	e = (this->list)[i - 1];
	for (int pos = i - 1; pos < this->size - 1; pos++) {
		(this->list)[pos] = (this->list)[pos + 1];
	}
	this->size--;
}

template<class Elem>
void seqList<Elem>::listTraverse(bool (visit)(Elem e)) {
	for (int i = 0; i < this->size; i++) {
		if (!visit((this->list)[i])) {
			cout << "visit error" << endl;
			return;
		}
	}
}

template<class Elem>
bool compare(Elem e1, Elem e2) {
	return e1 == e2;
}

template<class Elem>
bool visit(Elem e) {
	cout << e;
	return true;
}

//ostream& operator<<(ostream& cout, const student& st) {
//	cout << "age:" << st.age << endl;
//	cout << "name:" << st.name << endl;
//	return cout;
//}
//lnk1169+lnk2005


