//#include "DoubleList.h"

//template<class T>
//DoubleList<T>::DoubleList() {
//	head = NULL;
//	tail = NULL;
//}
//
//template<class T>
//DoubleList<T>::~DoubleList()
//{
//}
//
//template<class T>
//void DoubleList<T>::pushBack(T data)
//{
//	node * curr = NULL;
//	node * temp = NULL;
//
//	//Create node, initialize the contents
//	node * n = new node;
//	n->next = NULL;
//	n->prev = NULL;
//	n->data = data;
//
//	//Add node to the end
//	if (head != NULL)
//	{
//		curr = head;
//		while (curr->next != NULL)
//		{
//			curr = curr->next;
//		}
//		curr->next = n;
//		n->prev = curr;
//	}
//	//New node is only node that exists, add
//	else 
//	{
//		head = n;
//	}
//	tail = n;
//	nodeCount++;
//}
//
//template<class T>
//void DoubleList<T>::popBack()
//{
//	if (tail != NULL)
//	{
//		node * delPtr = NULL;
//		if (nodeCount == 1)
//		{
//			delPtr = head;
//			delPtr->next = NULL;
//			delPtr->prev = NULL;
//			nodeCount--;
//		}
//		else if (nodeCount > 1)
//		{
//			delPtr = tail;
//			tail = tail->prev;
//			tail->next = NULL;
//			delPtr->prev = NULL;
//			nodeCount--;
//		}
//		delete delPtr;
//	}
//}
//
//template<class T>
//void DoubleList<T>::sort()
//{
//
//}
//
//template<class T>
//void DoubleList<T>::print()
//{
//	node * curr = head;
//	while (curr != NULL)
//	{
//		cout << curr->data << endl;
//		curr = curr->next;
//	}
//}
