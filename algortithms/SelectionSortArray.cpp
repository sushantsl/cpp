#include <iostream>

#define MAXSIZE 5

//Function two swap values at indexes i and j of integer array a[]
void swap(int a[],int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

//Function to perform selection sort over integer arrat a[]
void selectionSort(int a[])
{
	for(int i=0; i < MAXSIZE; ++i)
	{	
		//Choose i as the index with minimum value
		int min = i;
		for(int j=i+1; j < MAXSIZE ; ++j)
		{
			if(a[j] < a[min])
			{
				//If there is an element that is smaller than value at min, swap 
				min = j;	
			}
			swap(a, i, min);
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

	selectionSort(a);	

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
