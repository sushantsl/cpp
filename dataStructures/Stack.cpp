//Program to push and pop elements from a Stack of integers using array
#include <iostream>

#define MAXSIZE 5

class Stack{
	int a[MAXSIZE];
	int top;
public:
	Stack(): top(-1){}
	bool isEmpty();		// Check is stack is empty. Return true if empty, false if not
	int pop();		// Pop the top integer from the stack
	void push(int x);	// Push an integer on top of the stack
	void peek();		// View the top of the stack without removing the integer
};

bool Stack::isEmpty()
{
	return ((top == -1) ? true : false);
}
int Stack::pop()
{
        if(!isEmpty())
	{
		int value = a[top];
		top--;
		std::cout<<"Popped "<<value<<std::endl;
		return value; 
	}
	else
	{
		std::cout<<"ERROR! Stack Underflow. No items available to pop!"<<std::endl;
		return -1;
	}
		
}
void Stack::push(int x)
{
	if(top == MAXSIZE-1)
	{
		std::cout<<"ERROR! Stack Overflow. Item " << x <<" not pushed"<<std::endl;
	}
	else
	{
		a[++top]=x;
		std::cout<<"Pushed "<<x<<std::endl;  
	}		
}
void Stack::peek()
{
	if(!isEmpty())
		std::cout<<"Top of stack is "<<a[top]<<std::endl;
	else
		std::cout<<"Stack is empty!"<<std::endl;
}
int main()
{
	Stack s;
	s.push(1);	
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	
	s.peek();

	s.push(6);
	s.pop();
        s.pop();		
	s.pop();
	s.pop();
	s.pop();
	s.pop();	

return 0;
}
/*
Expected Output-
----------------
Pushed 1
Pushed 2
Pushed 3
Pushed 4
Pushed 5
Top of stack is 5
ERROR! Stack Overflow. Item 6 not pushed
Popped 5
Popped 4
Popped 3
Popped 2
Popped 1
ERROR! Stack Underflow. No items available to pop!
*/
