
using namespace std;
#include<iostream>
#include<string>
#include"stack.h"
#include"operate.cpp"

int main() {
	stack<int>s;
	s.initStack();
	//s.destroyStack();
	//s.clearStack();
	
	s.push(10);
	s.push(20);
	s.push(30);
	s.push(40);
	s.push(50);
	s.push(60);
	s.push(70);
	s.push(80);
	s.push(90);
	s.push(100);
	s.push(110);
	s.push(120);
	s.push(130);
	s.push(140);
	s.push(150);
	s.push(160);
	cout << "stacklength:" << s.stackLength() << endl;
	cout << "stackCapacity:" << s.stackCapacity() << endl;
	cout << "old:" << endl;
	s.stackTraverse(visit);

	cout << "pop:" << endl;
	int num1 = 0;
	int& num2 = num1;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;
	s.pop(num2);
	cout << num2 << endl;

	cout << "new:" << endl;
	s.stackTraverse(visit);

	cout << "newcapacity:" << s.stackCapacity() << endl;
	cout << "newsize:" << s.stackLength() << endl;
	system("pause");
	return 0;
}
