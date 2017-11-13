//----------------------------------------------------------------------------
//  Title: DoubleList
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \MasterSet\DoubleList.h
//
//	Description: This class contains the implementation of a doubley linked
//				 list.
//
//  Programmer: Mitchell Nye
// 
//  Date: 11/5/2017
//
//  Version: 1.0
//
//	Environment: MS Windows 10
//  
//  Hardware: Intel I7-6600U CPU
//
//  Software: Visual Studio Community 2017
//
//	History Log: 11/5/2017	MN completed version 1.0
//
//----------------------------------------------------------------------------

#include <iostream>
#include <stddef.h>

#ifndef DOUBLELIST_H
#define DOUBLELIST_H

struct node;

template<typename T>
class DoubleList {
public:
	DoubleList();
	virtual ~DoubleList();

	virtual void insert(T * data);
	void deleteNode(T * data);
	void get(T * data);

	void popBack();

	void sort();
	void print();

	unsigned int nodeCount;

	  struct node {
		T * data;
		node* next;
		node* prev;
		int counter;
	};
	node* head;
	node* tail;
};

#endif

//--------------------------------------------------------------------------------

template<typename T>
DoubleList<T>::DoubleList() {
	head = NULL;
	tail = NULL;
	nodeCount = 0;
}

template<typename T>
DoubleList<T>::~DoubleList()
{
	node * curr = head;
	node * temp = head;
	while (curr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	std::cout << "Destructor called.";
}

template<typename T>
void DoubleList<T>::insert(T * data)
{
	node * curr = NULL;
	node * temp = NULL;

	//Create node, initialize the contents
	node * n = new node;
	n->next = NULL;
	n->prev = NULL;
	n->data = data;
	n->counter = 1;

	//Add node to the end
	if (head != NULL)
	{
		curr = head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = n;
		n->prev = curr;
	}
	//New node is only node that exists, add
	else
	{
		head = n;
	}
	tail = n;
	nodeCount++;
}

template<typename T>
inline void DoubleList<T>::deleteNode(T * data)
{
	node * delPtr = NULL;
	node * temp = head;
	node * curr = head;

	while (curr != NULL && curr->data != data) //search list
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) //hit end, unsuccessful
	{
		std::cout << data << " was not in the list" << std::endl;
		temp = NULL;
		delete delPtr;
	}

	else //we found the match (temp was trailing curr)
	{
		delPtr = curr;
		curr = curr->next;

		if (delPtr == head) {
			curr->prev = temp->prev; //new head prev point to NULL
			head = head->next; //set new head
		}
		else if (delPtr == tail)
		{
			tail = delPtr->prev;
		}
		else
		{
			curr->prev = temp; //point to node before deleted node
		}

		temp->next = curr; //node that came bofore del will point to node 
						   //after deleted node
		delete delPtr;
		std::cout << "The value " << data << "was deleted" << std::endl;
	}
}

template<typename T>
inline void DoubleList<T>::get(T * data)
{
	node * temp = head;
	node * curr = head;

	while (curr != NULL && curr->data != data)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		std::cout << "A node with " << data << " was not in the list" << std::endl;
	}
	else
	{
		std::cout << *curr->data;
	}
}

template<typename T>
void DoubleList<T>::popBack()
{
	if (tail != NULL)
	{
		node * delPtr = NULL;
		if (nodeCount == 1)
		{
			delPtr = head;
			delPtr->next = NULL;
			delPtr->prev = NULL;
			head = NULL;
			tail->next = NULL;
			tail->prev = NULL;
			tail = NULL;
			nodeCount--;
		}
		else if (nodeCount > 1)
		{
			delPtr = tail;
			tail = tail->prev;
			tail->next = NULL;
			delPtr->prev = NULL;
			nodeCount--;
		}
		delete delPtr;
	}
}

template<typename T>
void DoubleList<T>::sort()
{
	node * ptr;
	T * tempPtr;
	if (head == NULL)
		return;
	if (head->next == NULL)
		return;

	bool swapped = true;
	while (swapped)
	{
		swapped = false;

		ptr = head;
		while (ptr->next != NULL)
		{
			if (*(ptr->data) > *((ptr->next)->data))
			{
				swapped = true;

				tempPtr = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tempPtr;
			}
			ptr = ptr->next;
		}
	}
}

template<typename T>
void DoubleList<T>::print()
{
	node * curr = head;
	while (curr != NULL)
	{
		std::cout << "Address:" << &(curr->data) << std::endl;
		std::cout << "Value:" << *(curr->data) << std::endl;
		curr = curr->next;
	}
}