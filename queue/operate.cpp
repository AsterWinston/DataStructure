#include"queue.h"

template<class T>
bool Queue<T>::initQueue() {
	this->front = NULL;
	this->rear = NULL;
	cout << "init success" << endl;
	return 1;
}

template<class T>
bool Queue<T>::destroyQueue() {
	node<T>* temp = NULL;
	if (this->front == NULL) {
		cout << "destory error" << endl;
		return 0;
	}
	while (this->front!=this->rear)
	{
		temp = front;
		front = front->next;
		delete temp;
	}
	delete rear;
	front = rear = NULL;
	cout << "destroy success" << endl;
	return 1;
}

template<class T>
bool Queue<T>::clearQueue() {
	return destroyQueue();
}

template<class T>
bool Queue<T>::QueueEmpty() {
	if (front == NULL)return 1;
	return 0;
}

template<class T>
int Queue<T>::QueueLenth() {
	int length = 0;
	if (this->front == NULL)return 0;
	node<T>* temp = this->front;
	while (temp != rear) {
		length++;
		temp = temp->next;
	}
	return length + 1;
}

template<class T>
bool Queue<T>::getHead(node<T>& n) {
	if (front == NULL) {
		cout << "get error" << endl;
		return 0;
	}
	n = *front;
	cout << "get success" << endl;
	return 1;
}

template<class T>
bool Queue<T>::push(node<T>n) {
	if (front == NULL) {
		node<T>* temp = new node<T>;
		if (temp == NULL)return 0;
		temp->data = n.data;
		front = rear = temp;
		cout << "push success" << endl;
		return 1;
	}
	node<T>* temp = new node<T>;
	if (temp == NULL)return 0;
	temp->data = n.data;
	rear->next = temp;
	rear = temp;
	temp->next = NULL;
	cout << "push success" << endl; 
	return 1;
}

template<class T>
bool Queue<T>::pop(node<T>& n) {
	if (front == NULL) {
		cout << "pop error" << endl;
		return 0;
	}
	if (front == rear) {
		delete front;
		front = rear = NULL;
		return 1;
	}
	n.data = front->data;
	node<T>* temp = front;
	front = front->next;
	delete temp;
	cout << "pop success" << endl;
	return 1;
}

template<class T>
bool Queue<T>::QueueTraverse(bool (*visit)(node<T> n)) {
	if (front == NULL) {
		cout << "traverse error" << endl;
		return 0;
	}
	node<T>* temp = front;
	while (temp != rear) {
		visit(*temp);
		temp = temp->next;
	}
	visit(*temp);
	cout << "traverse success" << endl;
	return 1;
}

template<class T>
bool visit(node<T> n) {
	cout << n.data << endl;
	return 1;
}