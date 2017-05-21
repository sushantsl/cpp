#include <iostream>

#define MAXSIZE 5

//Function two swap values at indexes i and j of integer array a[]
void swap(int a[],int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//Function to perform insertion sort over integer array a[]
void insertionSort(int a[])
{
	for(int i=0; i< MAXSIZE; ++i)
	{
		for(int j=i; j>0; j--)
		{
			if(a[j] < a[j-1])
			{
				//Swap with every previous element that is smaller 
				swap(a,j,j-1);
			}
			else
			{
				//No need to swap more
				break;
			}
		}
	}		
}

//Function to display contents of intger array a[]
void display(int a[])
{
	for(int i=0; i<MAXSIZE; ++i)
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

	insertionSort(a);	

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
