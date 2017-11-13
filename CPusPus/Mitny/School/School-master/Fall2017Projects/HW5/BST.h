//----------------------------------------------------------------------------
//  Title: BST
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \BST\BST.h
//
//	Description: This class contains the members of the BST class. It
//				 is used to store integers in a binary search tree. It can
//				 insert items in a sorted manner, and the tree can be
//				 traversed via "pre-order", "post-order", "in-order", and
//				 "breadth-first". It also contains a delete method that is
//				 called by the destructor to prevent memory leaks.
//
//  Programmer: Mitchell Nye
// 
//  Date: 11/12/2017
//
//  Version: 1.0
//
//	Environment: MS Windows 10
//  
//  Hardware: Intel I7-6600U CPU
//
//  Software: Visual Studio Community 2017
//
//	History Log: 11/12/2017	MN completed version 1.0
//
//----------------------------------------------------------------------------

#ifndef BST_H
#define BST_H

#include <stdlib.h>
#include <iostream>
#include <queue>

class BST {
private:
	struct node
	{
		node* left;
		node* right;
		int data;
	};

public:
	node* root;

	BST();
	~BST();

	void insert(int);
	void deleteTree(node * n);

	void preOrder(node* n);
	void inOrder(node* n);
	void postOrder(node* n);
	void breathFirst(node* n);

	bool isEmpty() const;
};
#endif