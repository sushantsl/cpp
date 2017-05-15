//Program to implement a Circular Queue of integers using array. Rear wraps around. Queue can hold MAXSIZE-1 elements.  
#include <iostream>

#define MAXSIZE 5

class CircularQueue
{
	int a[MAXSIZE];
	int front;
	int rear;
	int count;
public:
	CircularQueue():front(0), rear(-1),count(0){}
	bool isEmpty();			// Check if Circular Queue is empty. Return true if empty, false otherwise
    bool isFull();			// Check if Circular Queue is full. Return true if full, false otherwise
	void enqueue(int x);    // Insert integer at the rear of the Circular Queue
	int dequeue();			// Remove integer from the front of the Circular Queue
	void display();			// Display the contents of the Circular Queue
};

bool CircularQueue::isEmpty()
{
	return ((count == 0) ? true : false);
}
bool CircularQueue::isFull()
{
	return ((count == MAXSIZE-1) ? true : false);
}
void CircularQueue::enqueue(int x)
{
	if(isFull())
	{
		std::cout<<"ERROR! Circular Queue is full. Cannot add more items"<<std::endl;
		return;
	}
	rear = (rear+1) % MAXSIZE;
	a[rear] = x;
	count++;
	std::cout<<"Inserted "<<x<<" into the queue."<<std::endl;
}
int CircularQueue::dequeue()
{
	if(isEmpty())
	{
		std::cout<<"ERROR! Cannot dequeue. Circular Queue is empty!"<<std::endl;
		return -1;
	}
	
	int value = a[front];
	std::cout<<"Removed "<<value<<" from the queue"<<std::endl;
	front = (front+1) % MAXSIZE;
	count--;
	return value;
}
void CircularQueue::display()
{
	std::cout<<"The contents of the queue are: ";
	for(int i = 0; i < count; ++i)
	{
		std::cout<<a[(front+i) % MAXSIZE]<<"\t";
	}
	std::cout<<std::endl;	

}
int main()
{
	CircularQueue q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);

	q.display();
	q.dequeue();
	q.display();
	q.enqueue(6);

	q.display();
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
ERROR! Circular Queue is full. Cannot add more items
The contents of the queue are: 1	2	3	4	
Removed 1 from the queue
The contents of the queue are: 2	3	4	
Inserted 6 into the queue.
The contents of the queue are: 2	3	4	6	
Removed 2 from the queue
Removed 3 from the queue
Removed 4 from the queue
Removed 6 from the queue
ERROR! Cannot dequeue. Circular Queue is empty!
*/
