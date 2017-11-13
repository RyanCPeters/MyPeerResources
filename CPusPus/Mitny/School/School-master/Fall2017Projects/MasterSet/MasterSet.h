//----------------------------------------------------------------------------
//  Title: MasterSet
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \MasterSet\MasterSet.h
//
//	Description: This class inherits from the DoubleList class to create Set
//				 functionality. The implementation is included in the .h file
//				 because the compiler wouldn't know what to do with the .cpp
//				 at runtime (it being a template class).
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
#include "DoubleList.h"
#include <stddef.h>

#ifndef MASTERSET_H
#define MASTERSET_H

template <typename T>
class MasterSet : public DoubleList<T> {
public:
	void insertSet(T * data);
	void printWithKeys();
	void getCount(T * data);
	void sortSet();
	void getTopThree();
	~MasterSet();


	typedef typename DoubleList<T>::node node1;
};
#endif



template<typename T>
MasterSet<T>::~MasterSet()
{
	typename DoubleList<T>::node * curr = this->head;
	typename DoubleList<T>::node * temp = this->head;
	while (curr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}
	std::cout << "Destructor called.";
}

template<typename T>
void MasterSet<T>::insertSet(T * data)
{
	//Check the list for existing data:

	node1 * temp = this->head;
	typename DoubleList<T>::node * curr = this->head;

	while ((curr != NULL) && (curr->data != data))
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr != NULL) 
	{
		curr->counter++; //found node with equal key, up count, don't add new node.
	}
	else
	{
		curr = NULL;
		typename DoubleList<T>::node * temp = NULL;

		//Create node, initialize the contents
		typename DoubleList<T>::node * n = new typename DoubleList<T>::node;
		n->next = NULL;
		n->prev = NULL;
		n->data = data;
		n->counter = 1;

		//Add node to the end
		if (this->head != NULL)
		{
			curr = (this->head);
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
			this->head = n;
		}
		this->tail = n;
		this->nodeCount++;
	}
}

template<typename T>
void MasterSet<T>::printWithKeys()
{
	typename DoubleList<T>::node * curr = this->head;
	while (curr != NULL)
	{
		std::cout << "Key:" << &(curr->data) << std::endl;
		std::cout << "Value:" << *(curr->data) << std::endl;
		std::cout << "Count:" << curr->counter << std::endl << std::endl;
		curr = curr->next;
	}
}

template<typename T>
void MasterSet<T>::getCount(T * data)
{
	typename DoubleList<T>::node * temp = this->head;
	typename DoubleList<T>::node * curr = this->head;

	while (curr != NULL && curr->data != data)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		std::cout << "A node with a key of " << data << " was not in the list" << std::endl;
	}
	else
	{
		std::cout << "Count of " << *curr->data << " is " << curr->counter;
	}
}

template<typename T>
void MasterSet<T>::sortSet() //sorts by count
{
	typename DoubleList<T>::node * ptr;
	T * tempPtr;
	int temp = 0;

	if (this->head == NULL)
		return;
	if (this->head->next == NULL)
		return;

	bool swapped = true;
	while (swapped)
	{
		swapped = false;

		ptr = this->head;
		while (ptr->next != NULL)
		{
			if (ptr->counter < (ptr->next)->counter)
			{
				swapped = true;

				tempPtr = ptr->data;
				ptr->data = ptr->next->data;
				ptr->next->data = tempPtr;

				temp = ptr->counter;
				ptr->counter = ptr->next->counter;
				ptr->next->counter = temp;
			}
			ptr = ptr->next;
		}
	}
}

template<typename T>
void MasterSet<T>::getTopThree()
{
	sortSet();

	typename DoubleList<T>::node * curr = this->head;
	int countToPrint = 0;

	std::cout << "\nTop 3:" << std::endl;
	while (countToPrint <= 2)
	{
		std::cout << "Key:" << &(curr->data) << std::endl;
		std::cout << "Value:" << *(curr->data) << std::endl;
		std::cout << "Count:" << curr->counter << std::endl << std::endl;
		curr = curr->next;

		countToPrint++;
	}
}
