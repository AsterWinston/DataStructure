
#include<iostream>
using namespace std;
#include<string>
#include"queue.h"
#include"operate.cpp"

int main() {
	Queue<int>q;
	q.initQueue();

	node<int>n1(10);
	node<int>n2(20);
	node<int>n3(30);

	q.push(n1);
	q.push(n2);
	q.push(n3);
	
	cout << "length:" << q.QueueLenth() << endl;
	node<int>& n4 = n1;
	q.getHead(n4);
	cout << "front elem:" << n4.data << endl;
	q.QueueTraverse(visit);
	q.pop(n4);
	q.QueueTraverse(visit);

	//q.clearQueue();
	//q.QueueTraverse(visit);
	//if (q.QueueEmpty())cout << "queue is empty" << endl;
	//else cout << "queue is not empty" << endl;

	system("pause");
	return 0;
}
