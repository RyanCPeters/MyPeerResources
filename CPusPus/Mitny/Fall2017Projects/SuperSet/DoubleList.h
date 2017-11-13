#ifndef DOUBLELIST_H
#define DOUBLELIST_H

#include <stdlib.h>

template<class T>
class DoubleList {
public:
	DoubleList();
	~DoubleList();

	void pushBack(T data);
	void popBack();

	void sort();
	void print();

private:
	unsigned int nodeCount;

	struct node {
		T data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
};

#endif