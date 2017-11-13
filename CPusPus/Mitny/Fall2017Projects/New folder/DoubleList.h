#ifndef DOUBLELIST_H
#define DOUBLELIST_H

template<typename T>
class DoubleList {
public:
	DoubleList();
	~DoubleList();

	virtual void insert(T * data);
	void deleteNode(T * data);
	void get(T * data);

	void popBack();

	void sort();
	void print();

private:
	unsigned int nodeCount;

	struct node {
	public: T * data;
		node* next;
		node* prev;
	};
	node* head;
	node* tail;
};

#endif

//--------------------------------------------------------------------------------
template<typename T>
DoubleList<T>::DoubleList() {
	head = nullptr;
	tail = nullptr;
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
	cout << "Destructor called.";
}

template<typename T>
void DoubleList<T>::insert(T * data)
{
	node * curr = nullptr;
	node * temp = nullptr;

	//Create node, initialize the contents
	node * n = new node;
	n->next = nullptr;
	n->prev = nullptr;
	n->data = data;

	//Add node to the end
	if (head != nullptr)
	{
		curr = head;
		while (curr->next != nullptr)
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
	node * delPtr = nullptr;;
	node * temp = head;
	node * curr = head;

	while (curr != nullptr && curr->data != data) //search list
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == nullptr) //hit end, unsuccessful
	{
		cout << data << " was not in the list" << endl;
		temp = nullptr;
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
		cout << "The value " << data << "was deleted" << endl;
	}
}

template<typename T>
inline void DoubleList<T>::get(T * data)
{
	node * temp = head;
	node * curr = head;

	while (curr != nullptr && curr->data != data)
	{
		temp = curr;
		curr = curr->next;
	}

	if (curr == nullptr)
	{
		cout << "A node with " << data << " was not in the list" << endl;
	}
	else
	{
		cout << *curr->data;
	}
}

template<typename T>
void DoubleList<T>::popBack()
{
	if (tail != nullptr)
	{
		node * delPtr = nullptr;
		if (nodeCount == 1)
		{
			delPtr = head;
			delPtr->next = nullptr;
			delPtr->prev = nullptr;
			head = nullptr;
			tail->next = nullptr;
			tail->prev = nullptr;
			tail = nullptr;
			nodeCount--;
		}
		else if (nodeCount > 1)
		{
			delPtr = tail;
			tail = tail->prev;
			tail->next = nullptr;
			delPtr->prev = nullptr;
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
	if (head == nullptr)
		return;
	if (head->next == nullptr)
		return;

	bool swapped = true;
	while (swapped)
	{
		swapped = false;

		ptr = head;
		while (ptr->next != nullptr)
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
	while (curr != nullptr)
	{
		cout << "Address:" << &(curr->data) << endl;
		cout << "Value:" << *(curr->data) << endl;
		curr = curr->next;
	}
}