//=========================================================
//HW#: HW4 quicksort
//Your name: Karishma Kapur
//Complier:  g++
//File type: implementation file / client program (.cpp) main & methods
//=========================================================

#include<iostream>

using namespace std;

//PURPOSE: swap the elements in the array
//PARAMETERS: pointers to the elements in the array to be swapped
//ALGORITHM: store the value of the first element into a temporary variable
//put the second element into the first elements location by dereferencing the pointer
//then put the value that was stored in temp into the location of b (dereference b).
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

//PURPOSE: partition the array into where every element below the pivot is less than the pivot value
//and every element above the pivot is above the pivot value
//PARAMETERS: array to loop through and see the elements, as well as the lowest index of the array and the highest index of the array
//ALGORITHM: set the pivot to the highest index of the array, compare each element with the pivot.
//if the element is larger than the pivot, leave it alone. If the element is smaller, swap it with the 
//first element avaliable the swap with (this is kept track of with the swapIndex in the function).
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; //pivot is at the last element of the array. This is the element I will create my partition
	int swapIndex = low - 1; //setting swapIndex 1 below array, so when it's needed, it is set to the right position, by incrementing by 1. (in if statement)
	int currentIndex = low; //setting swapIndex to first element in array, so I can compare every element to pivot

	//while currentIndex (the index I am at currently) is less than the maximum index in the array, keep looping
	while (currentIndex < high)
	{
		//if the element at the currentIndex is less than the pivot value, swap it with swapIndex.
		//swapIndex holds the first position as to where it is possible to swap.
		if (arr[currentIndex] < pivot)
		{
			swapIndex++; //increase your swapIndex, so you are not overwritting another swap you did previously
			swap(arr[swapIndex], arr[currentIndex]); //then swap the values
			
		}//end of if block

		currentIndex++; //increase your currentIndex so that you can compare the next value
	
	} //end of while loop

	//when the currentIndex is equal to the highest possible index in the array, 
	//swap the pivot out with 1 above the swapIndex because 1 above the swapIndex 
	//is guarenteed to be a number greater than pivot, as currentIndex has 
	//already looped through the array and swapped all elements lower than pivot with the swapIndex 
	//and incremented the swapIndex
	swap(arr[swapIndex + 1], arr[high]); 

	//return swapIndex + 1 because this is where the pivot value is located at meaning this is where the partition is located
	return (swapIndex + 1);
}


//PURPOSE: sort the array
//PARAMETERS: array, lowest index, and highest index
//ALGORITHM: recursively call paritition until the array is completely sorted.
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}


//PURPOSE: print all elements of array to screen
//PARAMETERS: array so we can loop through it, and size, so we know how long the array is
//ALGORITHM: loop through the array and at each index i, print the element to the console
void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

//PURPOSE: sort an array in ascending order
//ALGORITHM: call quicksort to sort the array
int main()
{
	int arr[] = { 1, 7, 8, 9, 10, 5 }; //array to be sorted

	int n = sizeof(arr) / sizeof(arr[0]); //size of array

	quickSort(arr, 0, n - 1); //calling quicksort

	cout << "Sorted array: " << endl; //printing to console that the array is sorted

	printArray(arr, n); //printing out the sorted array to console

	return 0;
}