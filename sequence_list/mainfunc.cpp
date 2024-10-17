using namespace std;
#include<iostream>
#include<string>
#include"seqList.h"
#include"operate.cpp"
//#include"load.cpp"//重载函数（非模板函数类型）所在的源文件不可以包含，所以把下面的重载函数放在跟模板函数一个源文件中会导致报错
//类模板中成员函数创建时机是在调用阶段，导致分文件编写时链接不到（编译阶段h文件并不会生成成员函数，所以不会链接到成员函数所在的源文件中，在编译结束运行到调用函数时又没有源文件的信息，导致错误）
//ostream& operator<<(ostream& cout, const student& st) {
//	cout << "age:" << st.age << endl;
//	cout << "name:" << st.name << endl;
//	return cout;
//}
//放这里可以

int main() {
	seqList<student> L;
	L.initList();
	/*L.destroyList();
	L.clearList();
	if (L.listEmpty()) {
		cout << "empty" << endl;
	}
	else {
		cout << "not empty" << endl;
	}
	cout << L.listLength() << endl;*/
	/*int a = 1, b = 2, c = 3, d = 4, e = 5;
	cout << "list:" << endl;
	L.listInsert(1, a);
	L.listInsert(2, b);
	L.listInsert(3, c);
	L.listInsert(4, d);
	L.listInsert(5, e);*/

	student st1(18, "jack");
	student st2(19, "jhon");
	student st3(20, "jason");
	
	L.listInsert(1, st1);
	L.listInsert(2, st3);
	L.listInsert(3, st2);
	
	L.listTraverse(visit);

	/*int num1 = 0;
	int& num2 = num1;*/
	//cout << L.locateElem(num2, compare) << endl;
	/*L.getElem(3, num2);
	cout << "getelem:" << num2 << endl;*/

	/*L.listDelete(2, num2);
	cout << "num2:" << num2 << endl;
	cout << "newlist:" << endl;
	cout << "size:" << L.listLength() << endl;
	L.listTraverse(visit);*/
	//L.priorElelm(3, num2);
	//cout << "num2:" << num2 << endl;
	//L.nextElem(2, num2);
	//cout << "num2:" << num2 << endl;
	/*L.listDelete(3, num2);
	L.listTraverse(visit);*/

	system("pause");
	return 0;
}
