#include"stack.h"

template<class T>
bool stack<T>::initStack() {
	this->base = this->top = new T[initSize];
	if (!this->base) {
		cout << "init error" << endl;
		return false;
	}
	this->capacity = initSize;
	this->size = 0;
	cout << "init success" << endl;
	return true;
}

template<class T>
bool stack<T>::destroyStack() {
	if (this->base == NULL) {
		cout << "destroy error" << endl;
		return 0;
	}
	//free(this->base);
	delete[] this->base;
	this->base = this->top = NULL;
	this->capacity = this->size = 0;
	cout << "destroy success" << endl;
	return 1;
}

template<class T>
bool stack<T>::clearStack() {
	if (this->base == NULL) {
		cout << "clear error" << endl;
		return 0;
	}
	delete[] this->base;
	this->base = this->top = NULL;
	this->base = this->top = new T[initSize];
	if (this->base == NULL)return 0;
	this->capacity = initSize;
	this->size = 0;
	cout << "clear success" << endl;
	return 1;
}

template<class T>
bool stack<T>::stackEmpty() {
	if (this->size == 0)return 1;
	return 0;
}

template<class T>
int stack<T>::stackLength() {
	return this->size;
}

template<class T>
bool stack<T>::getTop(T& elem) {
	if (this->base == NULL)return 0;
	if (this->base == this->top)return 0;
	top--;
	elem = *top;
	top++;
	return 1;
}

template<class T>
bool stack<T>::push(T elem) {
	if (this->base == NULL)return 0;
	if (this->size >= this->capacity) {
		T* delStack = this->base;
		T* newbase, *newtop;
		newbase = newtop = new T[this->capacity + 10];
		if (newbase == NULL)return 0;
		this->capacity += 10;
		while (this->base!=this->top)
		{
			*newtop = *base;
			newtop++;
			base++;
		}
		delete[] delStack;
		this->base = newbase;
		this->top = newtop;
	}
	*top = elem;
	top++;
	this->size++;
	cout << "push success" << endl;
	return 1;
}

template<class T>
bool stack<T>::pop(T& elem) {
	if (this->base == NULL)return 0;
	if (this->base == this->top)return 0;
	if (this->capacity - this->size >= 9) {
		this->capacity -= 10;
		T* newbase, * newtop;
		newbase = newtop = new T[capacity - 10];
		T* delStack = this->base;
		top--;
		elem = *top;
		while (this->base != this->top) {
			*newtop = *base;
			newtop++;
			base++;
		}
		this->base = newbase;
		this->top = newtop;
		delete[] delStack;
		this->size--;
		return 1;
	}
	top--;
	elem = *top;
	this->size--;
	return 1;
}

template<class T>
bool stack<T>::stackTraverse(bool (*visit)(T elem)) {
	if (this->base == NULL)return 0;
	T* temp = this->base;
	while(temp != top) {
		visit(*temp);
		temp++;
	}
	return 1;
}

template<class T>
bool visit(T elem) {
	cout << elem << endl;
	return 1;
}

template<class T>
int stack<T>::stackCapacity() {
	return this->capacity;
}