using namespace std;
#include<iostream>
#include<string>
#include"seqList.h"
#include"operate.cpp"
//#include"load.cpp"//���غ�������ģ�庯�����ͣ����ڵ�Դ�ļ������԰��������԰���������غ������ڸ�ģ�庯��һ��Դ�ļ��лᵼ�±���
//��ģ���г�Ա��������ʱ�����ڵ��ý׶Σ����·��ļ���дʱ���Ӳ���������׶�h�ļ����������ɳ�Ա���������Բ������ӵ���Ա�������ڵ�Դ�ļ��У��ڱ���������е����ú���ʱ��û��Դ�ļ�����Ϣ�����´���
//ostream& operator<<(ostream& cout, const student& st) {
//	cout << "age:" << st.age << endl;
//	cout << "name:" << st.name << endl;
//	return cout;
//}
//���������

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
