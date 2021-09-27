/*
Source code of quicksort algorithm. This algorithm can be break down into following steps:
	1. Select an random element, usually called pivot.
	2. Place that pivot element at its correct position relative to other elements in terms of 
	   increasing or decreasing order.
	3. Repeat step 1 recursively on subsequences formed after placing pivot at its place.
	4. Return when size of array reduces to 1 since no element left to place.

	Ex. Let's consider an arr = {23,3,4,15,34,9,14,30} we wanna sort.

Step 1. We are gonna pick last element as pivot and call our custom function to set its position
	    correctly. Our function should place the pivot in increasing order for now. Lets see one 
	    such iteration. Loop through array with two indexs: i and j. Swap arr[i],arr[j] and 
	    increment i whenever arr[j] < pvt and i and j are different.

	pvt = 30  
	iter 1: arr = {23,2,4,15,1,9,14,3}   i = 0, j = 0  no-swap
	iter 1: arr = {2,23,4,15,1,9,14,3}   i = 0->1, j = 1  swap
	iter 1: arr = {2,23,4,15,1,9,14,3}   i = 1, j = 2  no-swap
	iter 1: arr = {2,23,4,15,1,9,14,3}   i = 1, j = 3  no-swap
	iter 1: arr = {2,1,4,15,23,9,14,3}   i = 1->2, j = 4  swap
	iter 1: arr = {2,1,4,15,23,9,14,3}   i = 2, j = 5  no-swap
	iter 1: arr = {2,1,4,15,23,9,14,3}   i = 2, j = 6  no-swap
	
Step 2:	In the end, we'll just swap arr[i] and pvt(arr[last]) so our arr finally look like 
		arr = {2,1,3,15,23,9,14,4}. Pivot is correctly placed.

Step 3: Call our quicksort function again with two subsequences formed by pivot 
		i.e., arr[first,p] and arr[p,last]

Step 4: Return when last-first < 1

Below is implementation of above logic.

*/

#include <iostream>


using namespace std;
		
//func to set pivot at its correct pos											   			
int setPivot(int* arr, int l, int h){              
	int pvt = *(arr + h -1), i = l, j = l;       
	while (j < (h-1)){
		if(*(arr + j) < pvt){
			if (i != j){
				*(arr + i) += *(arr + j);
				*(arr + j) = *(arr + i) - *(arr + j);
				*(arr + i) -= *(arr + j);
			}
			i++;
		}
		j++;
	}
	*(arr + h -1) = *(arr + i);
	*(arr + i) = pvt;
	return i; 
}

// function to be called on our resulting arr sequneces
void quickSort(int* arr, int low, int high){
	if ((high - low) > 1){
		int p = setPivot(arr, low, high); 
		quickSort(arr, low, p);   // called for subsequence lower than pivot 
		quickSort(arr, p+1, high);  // called for subsequence higher than pivot
	}
}


int main(int argc, char const *argv[])
{
	int size = 11;
	int arr[size];
	for (int i = 0; i < size; ++i)
	{
		cin>>arr[i];
	}
	quickSort(arr, 0, size);
	for (int i = 0; i < size; ++i)
	{
		cout<<arr[i]<<' ';
	}
	return 0;
}