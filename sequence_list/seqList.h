#pragma once
#include<iostream>
using namespace std;
#define initCapacity 10



class student {
public:
	friend ostream& operator<<(ostream& cout, const student& st);
	student() {

	}
	student(int age, string name) {
		this->age = age;
		this->name = name;
	}
	bool operator==(const student& st) {
		return this->age == st.age && this->name == st.name;
	}
private:
	string name;
	int age;

};

template<class Elem>
class seqList {
private:
	Elem* list;
	int capacity;
	int size;
public:
	seqList();
	
public:
	void initList();
	//�������������һ���ձ�
	void destroyList();
	//��ʼ���������Ա��Ѿ�����
	//����������������Ա�
	void clearList();
	//��ʼ���������Ա��Ѿ�����
	//��������������Ա���Ϊ�ձ�
	bool listEmpty();
	//��ʼ���������Ա��Ѿ�����
	//�����������Ϊ�ձ��򷵻�true�����򷵻�false
	int listLength();
	//��ʼ���������Ա��Ѿ�����
	//����������������Ա�������Ԫ�ظ���
	void getElem(int i, Elem& e);
	//��ʼ���������Ա��Ѿ�����
	//�����������e�������Ա��е�i��Ԫ�ص�ֵ
	int locateElem(Elem& e, bool (*compare)(Elem e1, Elem e2));
	//��ʼ���������Ա��Ѿ�����
	//����������������Ա��е�һ����e�����ϵcompare()������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�0
	void priorElelm(Elem cur_e, Elem& pre_e);
	//��ʼ���������Ա��Ѿ�����
	//�����������cur_e�����Ա��е�����Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶���
	void nextElem(Elem cur_e, Elem& next_e);
	//��ʼ���������Ա��Ѿ�����
	//�����������cur_e�����Ա��е�����Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣��������ʧ�ܣ�next_e�޶���
	void listInsert(int i, Elem e);
	//��ʼ���������Ա��Ѿ�����
	//��������������Ա��е�i��λ��֮ǰ�����µ�����Ԫ��e�����Ա�ĳ��ȼ�һ
	void listDelete(int i, Elem& e);
	//��ʼ���������Ա��Ѿ�����
	//���������ɾ�����Ա��е�i������Ԫ�أ�����e������ֵ�����Ա�ĳ��ȼ�һ
	void listTraverse(bool (visit)(Elem e));
	//��ʼ���������Ա��Ѿ�����
	//������������ζ����Ա��е�ÿ��Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
};

ostream& operator<<(ostream& cout, const student& st);
