#include <iostream>

#define MAXSIZE 10

// Function to perform binary search on a sorted integer array. Returns position of key if found, -1 otherwise
int binarySearch(int a[], int left, int right, int key)
{
	while(left <= right)
	{
		int mid = (left+right)/2;
		if(key == a[mid])
		{
			return mid;
		}
		else if(key < a[mid])
		{
			right = mid-1;	
		}
		else
		{
			left = mid+1;
		}	
	}
	//Element not found
	return -1;
}	
int main()
{
	int a[MAXSIZE] = {0,1,2,3,4,5,6,7,8,9};
	
	int result = binarySearch(a, 0, MAXSIZE-1, 7);
	if(result != -1)
	{
		std::cout<<"Search successful. 7 found at position "<<result+1<<std::endl;  
	}
	else
	{
		std::cout<<"Search failed. 7 not found in the array!"<<std::endl;
	}
	
	result = binarySearch(a, 0, MAXSIZE-1, 15);
	if(result != -1)
        {
                std::cout<<"Search successful. 15 found at position "<<result+1<<std::endl; 
        }
        else
        {
                std::cout<<"Search failed. 15 not found in the array!"<<std::endl;
        }
return 0;
}
/*
Expected Output-
----------------
Search successful. 7 found at position 8
Search failed. 15 not found in the array!
*/
