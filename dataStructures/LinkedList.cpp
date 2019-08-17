//Program to implement a LinkedList of integers
#include <iostream>

class Node
{
public:
	int data;
	Node *next;
};

class LinkedList
{

	Node *head;

public:
	LinkedList() : head(NULL) {}
	void push_front(int x);		   // Push an integer at the front of the list
	void push_back(int x);		   // Push an integer at the back of the list
	int pop_front();			   // Pop an integer from the front of the list
	int pop_back();				   // Pop an integer from the back of the list
	void display();				   // Display the contents of the list from front to back
	Node *find(int x);			   // Find an integer in the list and return the pointer to the node
	void push_after(int x, int y); // Find an integer in the list and push the other integer after it
	void delete_item(int x);	   // Find an integer in the list and delete its node
};

void LinkedList::push_front(int x)
{
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = head;
	head = newNode;
	std::cout << "Inserted " << x << " at the front of the list" << std::endl;
}

void LinkedList::push_back(int x)
{
	Node *newNode = new Node;
	newNode->data = x;
	newNode->next = NULL;

	Node *temp = head;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = newNode;
	std::cout << "Inserted " << x << " at the back of the list" << std::endl;
}

int LinkedList::pop_front()
{
	Node *temp = head;
	if (!temp)
	{
		std::cout << "ERROR! List is empty. Cannot pop element from front" << std::endl;
		return -1;
	}
	delete head;
	head = temp->next;
	std::cout << "Removed " << temp->data << " from the front of the list" << std::endl;

	return temp->data;
}

int LinkedList::pop_back()
{
	Node *last = NULL;
	Node *prev = NULL;
	int poppedData = -1;

	if (!head)
	{
		std::cout << "ERROR! List is empty. Cannot pop element from back" << std::endl;
		return -1;
	}
	if (!head->next)
	{
		//There is only one node in the list
		std::cout << "Removed " << head->data << " from the back of the list" << std::endl;
		poppedData = head->data;
		delete head;
		head = NULL;
		return poppedData;
	}

	last = head;
	prev = NULL;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	std::cout << "Removed " << last->data << " from the back of the list" << std::endl;
	poppedData = last->data;
	delete last;
	prev->next = NULL;

	return poppedData;
}
void LinkedList::display()
{
	Node *temp = head;
	if (!temp)
	{
		std::cout << "List is empty" << std::endl;
		return;
	}
	else
	{
		std::cout << "The contents of the list are:\t";
		std::cout << temp->data;
		while (temp->next)
		{
			temp = temp->next;
			std::cout << "\t" << temp->data;
		}
		std::cout << std::endl;
	}
}

Node *LinkedList::find(int x)
{
	if (x == head->data)
	{
		return head;
	}
	Node *temp = head;
	while (temp->next)
	{
		temp = temp->next;
		if (x == temp->data)
		{
			std::cout << "Found " << x << " in the list. Returning node" << std::endl;
			return temp;
		}
	}

	std::cout << "ERROR! " << x << " not found in the list" << std::endl;
	return NULL;
}

void LinkedList::push_after(int x, int y)
{
	Node *temp = find(x);
	if (temp)
	{
		Node *newNode = new Node;
		newNode->data = y;
		newNode->next = temp->next;
		temp->next = newNode;
		std::cout << "Pushed " << y << " after " << x << std::endl;
	}
	else
	{
		std::cout << "ERROR! Target node " << x << "  not found. Push failed." << std::endl;
		return;
	}
}

void LinkedList::delete_item(int x)
{
	Node *temp = find(x);
	Node *prev = head;

	if (temp)
	{
		//Check if it is the only node
		if (!temp->next)
		{
			std::cout << "Removed " << x << " from the list" << std::endl;
			head = NULL;
			return;
		}
		while (prev->next != temp)
		{
			prev = prev->next;
		}

		std::cout << "Removed " << x << " from the list" << std::endl;
		prev->next = temp->next;
		delete temp;
		return;
	}
	else
	{
		std::cout << "ERROR! Target node " << x << " not found. Pop failed." << std::endl;
		return;
	}
}

int main()
{
	//Test all implemented operations in LinkedList
	LinkedList l;
	l.push_front(1);
	l.push_front(2);
	l.push_back(3);
	l.push_after(3, 4);
	l.push_front(5);

	l.display();

	l.delete_item(3);
	l.delete_item(6);

	l.pop_front();

	l.display();

	l.pop_back();
	l.pop_back();
	l.pop_front();
	l.pop_front();
	l.pop_back();

	return 0;
}
/*
Expected Output-
----------------
Inserted 1 at the front of the list
Inserted 2 at the front of the list
Inserted 3 at the back of the list
Found 3 in the list. Returning node
Pushed 4 after 3
Inserted 5 at the front of the list
The contents of the list are:	5	2	1	3	4
Found 3 in the list. Returning node
Removed 3 from the list
ERROR! 6 not found in the list
ERROR! Target node 6 not found. Pop failed.
Removed 5 from the front of the list
The contents of the list are:	2	1	4
Removed 4 from the back of the list
Removed 1 from the back of the list
Removed 2 from the front of the list
ERROR! List is empty. Cannot pop element from front
ERROR! List is empty. Cannot pop element from back
*/
