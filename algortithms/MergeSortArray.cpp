// Program to perform Merge Sort over an integer array
#include<iostream>

#define MAXSIZE 10 

// Function to break down given array into halves and merge them in sorted order
void merge(int a[], int left, int mid, int right)
{
    int i = 0;	//Index for first sub-array
    int j = 0;  //Index for second sub-array
    int k = 0;  //Index for merged array
    
    int sizeB = mid - left + 1;
    int sizeC = right - mid;
 
    // Create sub-arrays
    int b[sizeB];
    int c[sizeC];
 
    // Populate sub-arrays
    for (i = 0; i < sizeB; ++i)
        b[i] = a[left + i];
    for (j = 0; j < sizeC; ++j)
        c[j] = a[mid + 1+ j];
 
    // Merge the sub-arrays back into main array
    i = 0; 	
    j = 0;	
    k = left;
    while (i < sizeB && j < sizeC)
    {
        if (b[i] <= c[j])
        {
            a[k] = b[i];
            i++;
        }
        else
        {
            a[k] = c[j];
            j++;
        }
        k++;
    }
 
    // Copy left-over elements to main array, if any
    while (i < sizeB)
    {
        a[k] = b[i];
        i++;
        k++;
    }
    while (j < sizeC)
    {
        a[k] = c[j];
        j++;
        k++;
    }
}

// Function to sort a given integer array in ascending order 
void mergeSort(int a[], int left, int right)
{
    if (left < right)
    {
        int mid = left+(right-left)/2;
 
        //Recursively sort first and second halves
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);
 
	      //Recursively merge sub-arrays into main array
        merge(a, left, mid, right);
    }
}
 
// Function to display contents of integer array a[]
void display(int a[])
{
    for (int i=0; i < MAXSIZE; i++)
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
 
    mergeSort(a, 0, MAXSIZE-1);
 
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
