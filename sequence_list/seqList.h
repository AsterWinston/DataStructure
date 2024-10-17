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
	//操作结果：创建一个空表
	void destroyList();
	//初始条件：线性表已经存在
	//操作结果：销毁线性表
	void clearList();
	//初始条件：线性表已经存在
	//操作结果：将线性表置为空表
	bool listEmpty();
	//初始条件：线性表已经存在
	//操作结果：若为空表，则返回true，否则返回false
	int listLength();
	//初始条件：线性表已经存在
	//操作结果：返回线性表中数据元素个数
	void getElem(int i, Elem& e);
	//初始条件：线性表已经存在
	//操作结果：用e返回线性表中第i个元素的值
	int locateElem(Elem& e, bool (*compare)(Elem e1, Elem e2));
	//初始条件：线性表已经存在
	//操作结果：返回线性表中第一个与e满足关系compare()的数据元素的位序，若这样的数据元素不存在，则返回0
	void priorElelm(Elem cur_e, Elem& pre_e);
	//初始条件：线性表已经存在
	//操作结果：若cur_e是线性表中的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义
	void nextElem(Elem cur_e, Elem& next_e);
	//初始条件：线性表已经存在
	//操作结果：若cur_e是线性表中的数据元素，且不是最后一个，则用next_e返回他的后继，否则操作失败，next_e无定义
	void listInsert(int i, Elem e);
	//初始条件：线性表已经存在
	//操作结果：在线性表中第i个位置之前插入新的数据元素e，线性表的长度加一
	void listDelete(int i, Elem& e);
	//初始条件：线性表已经存在
	//操作结果：删除线性表中第i个数据元素，并用e返回其值，线性表的长度减一
	void listTraverse(bool (visit)(Elem e));
	//初始条件：线性表已经存在
	//操作结果：依次对线性表中的每个元素调用函数visit()，一旦visit()失败，则操作失败
};

ostream& operator<<(ostream& cout, const student& st);
