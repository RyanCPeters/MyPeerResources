//----------------------------------------------------------------------------
//  Title: BSTDriver
//			
//  File: C:\Users\mitchell.nye\Documents\Visual Studio 2017\Projects
//		    \BST\BSTDriver.cpp
//
//	Description: This driver tests the functionality of the BST class.
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
#include <vector>
#include "BST.h"
#include <iostream>

using namespace std;

int main() {

	vector<int> testingData = {132,756,459,533,219,48,679,680,935,384,520,831,35,54,530,672,8,384,67,418,687,589,931,847,
							   527,92,654,416,702,911,763,263,48,737,329,633,757,992,366,248,983,723,754,652,73,632,885,
							   273,437,767,478,238,275,360,167,487,898,910,61,905,505,517,320,987,494,267,91,948,74,501,
							   385,278,914,530,465,941,51,762,771,828,126,16,689,869,630,737,726,1000,889,234,307,352,
							   514,592,846,413,842,270,416,538,468};

	BST bigTree = BST();
	BST leftUnbalanced = BST();
	BST rightUnbalanced = BST();
	BST symmetrical = BST();

	for(const auto i: testingData)bigTree.insert(i);
	cout << "Demonstrating traversals on bigTree:";
	cout << "\nPre-Order" << endl;
	bigTree.preOrder(bigTree.root);
	cout << "\nPost-Order" << endl;
	bigTree.postOrder(bigTree.root);
	cout << "\nIn-Order" << endl;
	bigTree.inOrder(bigTree.root);
	cout << "\nBreadth-First" << endl;
	bigTree.breathFirst(bigTree.root);

	cout << endl << endl;

	leftUnbalanced.insert(80);
	leftUnbalanced.insert(90);
	leftUnbalanced.insert(70);
	leftUnbalanced.insert(85);
	leftUnbalanced.insert(100);

	leftUnbalanced.insert(60);
	leftUnbalanced.insert(65);
	leftUnbalanced.insert(50);
	leftUnbalanced.insert(67);
	leftUnbalanced.insert(63);

	leftUnbalanced.insert(55);
	leftUnbalanced.insert(40);
	leftUnbalanced.insert(57);
	leftUnbalanced.insert(45);
	leftUnbalanced.insert(30);

	rightUnbalanced.insert(30);
	rightUnbalanced.insert(20);
	rightUnbalanced.insert(40);
	rightUnbalanced.insert(10);
	rightUnbalanced.insert(25);

	rightUnbalanced.insert(50);
	rightUnbalanced.insert(45);
	rightUnbalanced.insert(60);
	rightUnbalanced.insert(43);
	rightUnbalanced.insert(47);

	rightUnbalanced.insert(55);
	rightUnbalanced.insert(70);
	rightUnbalanced.insert(54);
	rightUnbalanced.insert(65);
	rightUnbalanced.insert(80);

	symmetrical.insert(50);
	symmetrical.insert(40);
	symmetrical.insert(60);
	symmetrical.insert(30);
	symmetrical.insert(45);

	symmetrical.insert(55);
	symmetrical.insert(70);
	symmetrical.insert(20);
	symmetrical.insert(35);
	symmetrical.insert(43);

	symmetrical.insert(47);
	symmetrical.insert(53);
	symmetrical.insert(57);
	symmetrical.insert(65);
	symmetrical.insert(80);




	cout << "Demonstrating traversals on left unbalanced tree:";
	cout << "\nPre-Order" << endl;
	leftUnbalanced.preOrder(leftUnbalanced.root);
	cout << "\nPost-Order" << endl;
	leftUnbalanced.postOrder(leftUnbalanced.root);
	cout << "\nIn-Order" << endl;
	leftUnbalanced.inOrder(leftUnbalanced.root);
	cout << "\nBreadth-First" << endl;
	leftUnbalanced.breathFirst(leftUnbalanced.root);

	cout << "\n\n\nDemonstrating traversals on right unbalanced tree:";
	cout << "\nPre-Order" << endl;
	rightUnbalanced.preOrder(rightUnbalanced.root);
	cout << "\nPost-Order" << endl;
	rightUnbalanced.postOrder(rightUnbalanced.root);
	cout << "\nIn-Order" << endl;
	rightUnbalanced.inOrder(rightUnbalanced.root);
	cout << "\nBreadth-First" << endl;
	rightUnbalanced.breathFirst(rightUnbalanced.root);

	cout << "\n\n\nDemonstrating traversals on symmetrical tree:";
	cout << "\nPre-Order" << endl;
	symmetrical.preOrder(symmetrical.root);
	cout << "\nPost-Order" << endl;
	symmetrical.postOrder(symmetrical.root);
	cout << "\nIn-Order" << endl;
	symmetrical.inOrder(symmetrical.root);
	cout << "\nBreadth-First" << endl;
	symmetrical.breathFirst(symmetrical.root);

	cout << "\n\nDemonstrating the tree destructor:";
	cout << "\nLeft unbalanced" << endl;
	leftUnbalanced.~BST();
	cout << "\nRight unbalanced" << endl;
	rightUnbalanced.~BST();
	cout << "\nSymmetrical" << endl;
	symmetrical.~BST();


	cin.get();
	cin.get();
	return 0;
}