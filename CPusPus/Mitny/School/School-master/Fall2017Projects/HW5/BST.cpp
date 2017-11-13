//----------------------------------------------------------------------------
//  Title: BST
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \BST\BST.cpp
//
//	Description: This class contains the implementation of the BST class. It
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

#include "BST.h"

bool BST::isEmpty() const
{
	return root == NULL;
}

BST::BST()
{
	root = NULL;
}

BST::~BST()
{
	deleteTree(this->root);
}


void BST::insert(int data)
{
	node* n = new node;
	node* parent;
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	parent = NULL;

	if (isEmpty()) 
		root = n;
	else
	{
		node* curr;
		curr = root;
		while (curr)
		{
			parent = curr;
			if (n->data > curr->data)
				curr = curr->right;
			else
				curr = curr->left;
		}

		if (n->data < parent->data)
			parent->left = n;
		else
			parent->right = n;
	}
}

void BST::deleteTree(node * n)
{
	node * del = NULL;
	if (n != NULL)
	{
		if (n->left)
			postOrder(n->left);
		if (n->right)
			postOrder(n->right);

		del = n;
		
		std::cout << " " << n->data << " ";
		delete del;
	}
	else return;
}

void BST::preOrder(node * n)
{
	if (n != NULL)
	{
		std::cout << " " << n->data << " ";
		if (n->left) 
			preOrder(n->left);
		if (n->right) 
			preOrder(n->right);
	}
	else return;
}

void BST::inOrder(node * n)
{
	if (n != NULL)
	{
		if (n->left)
			inOrder(n->left);

		std::cout << " " << n->data << " ";

		if (n->right) 
			inOrder(n->right);
	}
	else return;
}

void BST::postOrder(node * n)
{
	if (n != NULL)
	{
		if (n->left)
			postOrder(n->left);
		if (n->right)
			postOrder(n->right);

		std::cout << " " << n->data << " ";
	}
	else return;
}

void BST::breathFirst(node * n)
{
	std::cout << " ";
	std::queue<node*> myQ;

	myQ.push(n);
	while (!myQ.empty())
	{
		n = myQ.front();
		myQ.pop();
		std::cout << n->data << "  ";

		if (n->left != NULL)
			myQ.push(n->left);

		if (n->right != NULL)
			myQ.push(n->right);
	}
}