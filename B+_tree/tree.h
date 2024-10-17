#pragma once
#include<stdio.h>
#define branch 5

struct record {
	int data;
};
struct element {
	union pointer {
		struct record* poin_record;
		struct node* poin_child;
	};
	enum poin_Type {
		record, child
	}poin_type;

};
struct node {
	struct element ele[branch];
	struct node* next;
};