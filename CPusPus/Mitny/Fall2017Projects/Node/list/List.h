//----------------------------------------------------------------------------
//  Title: List
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \List\List.h
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

#ifndef LIST_H
#define LIST_H

#include "Autobot.h"

class List {

public:
	List();
	~List();

	void addNode(Autobot addAutobot);
	void deleteNode(Autobot delAutobot);
	void printListForwards();
	void printListBackwards();
	void descendingBubbleSort();
	void ascendingBubbleSort();
	void linearSearchForAutobot(int powerLevel);

private:
	//----------------------------------------------------------------------------
	// This struct contains the building blocks (nodes) that will be used in
	// the linked list. Next will point to the next node and prev to the previous.
	//----------------------------------------------------------------------------
	struct node {
		Autobot autobot;
		node* next;
		node* prev;
	};

	node* head;
	node* tail;
	node* curr;
	node* temp;
};

#endif