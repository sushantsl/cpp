//Program to implement a Simple Queue of integers using array. Queue size decreases as item is dequeued. 
#include <iostream>

#define MAXSIZE 5

class Queue
{
	int a[MAXSIZE];
	int front;
	int rear;
public:
	Queue():front(0), rear(-1){}
	bool isEmpty();			// Check if Queue is empty. Return true if empty, false otherwise
	void enqueue(int x);		// Insert integer into the the rear of the queue
	int dequeue();			// Remove integer from the front of the queue
	void display();			// Display the contents of the queue
};

bool Queue::isEmpty()
{
	return((front > rear) ? true : false);
}
void Queue::enqueue(int x)
{
	if(rear == MAXSIZE-1)
	{
		std::cout<<"Queue is full. Cannot add more items"<<std::endl;
	}
	else
	{
		a[++rear] = x;
		std::cout<<"Inserted "<<x<<" into the queue."<<std::endl;
	}
}
int Queue::dequeue()
{
	if(isEmpty())
	{
		std::cout<<"ERROR! Cannot dequeue. Queue is empty!"<<std::endl;
		return -1;
	}
	else
	{
		int value = a[front];
                std::cout<<"Removed "<<value<<" from the queue"<<std::endl;
                front++;
                return value;
	}
}
void Queue::display()
{
	std::cout<<"The contents of the queue are: ";
	for(int i=front; i <= rear; ++i)
	{
		std::cout<<a[i]<<"\t";
	}
	std::cout<<std::endl;	
}
int main()
{
	Queue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.display();

	q.enqueue(6);

	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();
	q.dequeue();

return 0;
}
/*
Expected Output-
----------------
Inserted 1 into the queue.
Inserted 2 into the queue.
Inserted 3 into the queue.
Inserted 4 into the queue.
Inserted 5 into the queue.
The contents of the queue are: 1	2	3	4	5	
Queue is full. Cannot add more items
Removed 1 from the queue
Removed 2 from the queue
Removed 3 from the queue
Removed 4 from the queue
Removed 5 from the queue
ERROR! Cannot dequeue. Queue is empty!
*/
