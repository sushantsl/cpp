// Program to perform Quick Sort over an integer array
#include<iostream>

#define MAXSIZE 10 
// Function to swap values at i and j of an integer array
void swap(int a[], int i, int j)
{
	int temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}
// Function to return the split position after partitioning integer array 
int partition(int a[], int left, int right)
{
	int p = a[left];
	int i = left;
	int j = right+1;

	while(i < j)
	{
		while(a[i] <= p)
		{
			i++;
		}
		while(a[j] > p)
		{
			j--;
		}
		swap(a, i, j);
	}
	//Undo last swap when i >= j
	swap(a, i, j);

	swap(a, left, j);
	
	return j;
}

// Function to recursively sort an integer array using a pivot
void quickSort(int a[], int left, int right)
{
	if(left < right)
	{
		int split = partition(a, left, right);
		quickSort(a, left, split-1);
		quickSort(a, split+1, right); 
	}
}
// Function to display contents of integer array a[]
void display(int a[])
{
    for (int i=0; i < MAXSIZE; ++i)
    {
	    std::cout<<"\t"<<a[i];
    }
}
 
int main()
{
    int a[MAXSIZE] = {5,3,4,0,2,6,9,8,1,7};
 
    std::cout<<"Contents of array before sort: ";
    display(a);
    std::cout<<std::endl;
 
    quickSort(a, 0, MAXSIZE-1);
 
    std::cout<<"Contents of array after sort: ";
    display(a); 
    std::cout<<std::endl;

return 0;
}
/*
Expected Output-
----------------
Contents of array before sort: 	5	3	4	0	2	6	9	8	1	7
Contents of array after sort: 	0	1	2	3	4	5	6	7	8	9
*/
