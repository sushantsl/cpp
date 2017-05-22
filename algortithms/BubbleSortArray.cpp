#include <iostream>

#define MAXSIZE 5

// Function to swap values at indexes i and j of integer array a[]
void swap(int a[],int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

// Function to perform bubble sort over integer array a[]
void bubbleSort(int a[])
{
	for(int i=0; i < MAXSIZE-1; ++i)
	{
		for(int j=i+1; j < MAXSIZE; ++j)
		{
			if(a[j] < a[i])
			{
				swap(a, i ,j);
			}
		}
	}		
}

// Function to display contents of integer array a[]
void display(int a[])
{
	for(int i=0; i < MAXSIZE; ++i)
	{
		std::cout<<"\t"<<a[i];
	}
}

int main()
{
	int a[MAXSIZE] = {5,7,1,4,2};

	std::cout<<"Contents of array before sort: ";
	display(a);
	std::cout<<std::endl;

	bubbleSort(a);	

	std::cout<<"Contents of array after sort: ";
  display(a);
  std::cout<<std::endl;

return 0;
}
/*
Expected Output-
----------------
Contents of array before sort: 	5	7	1	4	2
Contents of array after sort: 	1	2	4	5	7
*/
