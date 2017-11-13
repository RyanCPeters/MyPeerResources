//----------------------------------------------------------------------------
//  Title: List
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \List\List.cpp
//
//	Description: This class allows the user to create a doubly linked list
//				 containing objects of the type "Autobot". The user can add
//				 a node to the end of the list using the addNode method. They
//				 can also delete a node by passing an autobot into the
//				 deleteNode method. The user can also print the list starting
//				 from the beiginning or starting from the end, by using the
//				 printListForwards and printListBackwards methods. The list
//				 can be sorted from smallest to greatest by using the
//				 ascendingBubbleSort method, and it can be sorted from
//				 greatest to least by using the descendingBubbleSort method.
//				 Both of these methods sort in terms of the autobots'
//				 powerlevels. Lastly, the user can perform a linear search
//				 for an autobot that has a specific powerlevel by using the
//				 linearSearchForAutobot method.
//
//  Programmer: Mitchell Nye
// 
//  Date: 10/15/2017
//
//  Version: 1.0
//
//	Environment: MS Windows 10
//  
//  Hardware: Intel I7-6600U CPU
//
//  Software: Visual Studio Community 2017
//
//	History Log: 10/15/2017 MN completed version 1.0
//
//----------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>

#include "List.h"
#include "Autobot.h"

using namespace std;

List::List() 
{
	head = NULL;
	tail = NULL;

	curr = NULL;
	temp = NULL;
}

List::~List() 
{
	curr = head;
	temp = head;
	while (curr) {
		temp = curr;
		curr = curr->next;
		delete temp;
	}

	cout << "Destructor called.";
}

//----------------------------------------------------------------------------
// addNode adds a node to the end of the current list.
//----------------------------------------------------------------------------

void List::addNode(Autobot addAutobot)
{
	node* n = new node;
	n->next = NULL;
	n->prev = NULL;
	n->autobot = addAutobot;

	if (head != NULL)
	{
		curr = head; //start iterating at the head
		while (curr->next != NULL) //go to the end of the list
		{
			curr = curr->next;
		}
		curr->next = n; //node at end points to new node
		n->prev = curr; //new node points to previous end node
	}
	else
	{
		head = n;
	}
	tail = n;
}

//----------------------------------------------------------------------------
// deleteNode removes the first node that matches the autobot passed in.
//----------------------------------------------------------------------------
void List::deleteNode(Autobot delAutobot)
{
	node* delPtr = NULL;
	temp = head;
	curr = head;

	while (curr != NULL && curr->autobot != delAutobot) //search list
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL) //hit end, unsuccessful
	{
		cout << delAutobot << " was not in the list" << endl;
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
		cout << "The value " << delAutobot << "was deleted" << endl;
	}
}

//----------------------------------------------------------------------------
// printListForwards will print the list starting with the head
//----------------------------------------------------------------------------
void List::printListForwards()
{
	curr = head;
	while (curr != NULL)
	{
		cout << curr->autobot << endl;
		curr = curr->next;
	}
}

//----------------------------------------------------------------------------
// printListForwards will print the list starting with the tail
//----------------------------------------------------------------------------
void List::printListBackwards()
{
	curr = tail;
	while (curr != NULL)
	{
		cout << curr->autobot << endl;
		curr = curr->prev;
	}
}

//----------------------------------------------------------------------------
// descendingBubbleSort will sort the data from greatest to least based on
// powerlevel of an autobot. It uses the bubble sort method and a temporary
// autobot to retain the values that need to be moved. It starts at the
// tail and goes in reverse.
//----------------------------------------------------------------------------
void List::descendingBubbleSort() //Big O: 5 + 8n^2 -> O(n^2)
{
	node* ptr;
	Autobot temp1 = Autobot();

	if (head == NULL)
		return;
	if (head->next == NULL)
		return;

	bool swapped = true;
	while (swapped)
	{
		swapped = false; //2n

		ptr = tail;
		while (ptr->prev != NULL) //8n
		{
			if (ptr->autobot.getPowerLevel() > ptr->prev->autobot.getPowerLevel())
			{
				swapped = true;

				temp1 = ptr->autobot;
				ptr->autobot = ptr->prev->autobot;
				ptr->prev->autobot = temp1;
			}
			ptr = ptr->prev;
		}
	}
	ptr = NULL;
	delete ptr;
}

//----------------------------------------------------------------------------
// ascendingBubbleSort will sort the data from least to greatest based on
// powerlevel of an autobot. It uses the bubble sort method and a temporary
// autobot to retain the values that need to be moved. It starts at the
// head proceeds towards the tail.
//----------------------------------------------------------------------------
void List::ascendingBubbleSort() //Big O: 5 + 8n^2 -> O(n^2)
{
	node* ptr;
	Autobot temp1 = Autobot();

	if (head == NULL)
		return;
	if (head->next == NULL)
		return;

	bool swapped = true;
	while (swapped)
	{
		swapped = false; //2n

		ptr = head;
		while (ptr->next != NULL) //4n
		{
			if (ptr->autobot.getPowerLevel() > ptr->next->autobot.getPowerLevel())
			{
				swapped = true;

				temp1 = ptr->autobot;
				ptr->autobot = ptr->next->autobot;
				ptr->next->autobot = temp1;
			}
			ptr = ptr->next;
		}
	}
	ptr = NULL;
	delete ptr;
}

//----------------------------------------------------------------------------
// linearSearchForAutobot will search for an autobot at the requested
// powerlevel and will print out the data of the first autobot that it finds.
//----------------------------------------------------------------------------
void List::linearSearchForAutobot(int powerLevel) //Big O: 2(n) + 3 -> O(n)
{
	temp = head;
	curr = head;

	while (curr != NULL && curr->autobot.getPowerLevel() != powerLevel) //2n
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == NULL)
	{
		cout << "An autobot with a power level of " << powerLevel << " was not in the list" << endl;
	}
	else
	{
		cout << curr->autobot;
	}
}
