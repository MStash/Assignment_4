// -------------------------------------------------------------------------------------------
// CODE FILENAME: Stash-assn4-funcs.cpp 
//
// DESCRIPTION:   MStash function file for Assignment 4
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  Matt Stash
// -------------------------------------------------------------------------------------------

#include "StahleyStash-assn4-common.h"
#include "Stash-assn4-funcs.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  GenerateRandomArray
//
// DESCRIPTION:   Initializes an array with random integers
//							   
// INPUT:		  int unsortedList[] - The list being initialized
//
// CALLS TO:	  RandomNumber
// -------------------------------------------------------------------------------------------
void GenerateRandomArray(int* firstList, int* secondList) {
	
	srand(time(0));							// seeds random number generator
	
	int temp,								// temp number
		count = 0;							// index
	
	while (count < ARRAY_SIZE) {
		
		temp = RandomNumber();
		
		firstList[count] = temp;
		secondList[count] = temp;
		
		count++;
	}
	return;
}

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  RandomNumber
//
// DESCRIPTION:   Creates a random number between the constant min and max values
// -------------------------------------------------------------------------------------------
int RandomNumber() {
	
	return rand() % MAX_VALUE + MIN_VALUE;
} 

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  CalculateAverage
//
// DESCRIPTION:   Calculates the average time for the number of clocks ticks with the number 
//				  of runs
// -------------------------------------------------------------------------------------------
float CalculateAverage(int clockTicks[], int numRuns) {
	
	int total = 0;
	
	for (int i = 0; i < numRuns; i++) {
		
		total += clockTicks[i];
	}
	
	return (float) total / numRuns;
}

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  DisplayResults
//
// DESCRIPTION:   Displays the results of the sorting tests
//
// INPUT:		  string firstTest - String title for the first sort tested
//				  string secondTest - String title for the second sort tested
//				  int firstAvg - 
// -------------------------------------------------------------------------------------------
void DisplayResults(string firstTest, string secondTest, float firstAvg, float secondAvg) {
	
	cout << setprecision(7);
	cout << "SORTING RESULTS" << endl;
	cout << setw(15) << setfill('-') << "-" << setfill(' ') << endl;
	cout << setw(20) << firstTest << " " <<
						firstAvg << " clock ticks on average" << endl;
	cout << setw(20) << secondTest << " " <<
						secondAvg << " clock ticks on average" << endl << endl;
	
	return;
}

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  InsertionSort
//
// DESCRIPTION:   Performs a insertion sort on an array
//
// INPUT:		  int* unsortedArray - Pointer to a unsorted array
//				  int low - Low index of the array
//				  int high - High index of the array
// -------------------------------------------------------------------------------------------
void InsertionSort(int* unsortedArray, int low, int high) {

	int remainTop,		// remaining top index
		temp;			// temp num
	
	for (int i = low; i <= high; i++) {
		
		remainTop = i;
		
		while (remainTop > low && unsortedArray[remainTop] < unsortedArray[remainTop - 1]) {
			
			temp = unsortedArray[remainTop];
			unsortedArray[remainTop] = unsortedArray[remainTop - 1];
			unsortedArray[remainTop - 1] = temp;
			
			remainTop--;
		}
	}
	return;
}

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  MergeSort
//
// DESCRIPTION:   Performs a merge sort on an array
//
// INPUT:		  int* unsortedArray - Pointer to a unsorted array
//				  int low - Low index of the array
//				  int high - High index of the array
// -------------------------------------------------------------------------------------------
void MergeSort(int* unsortedArray, int low, int high) {
	
	int middle;			// middle index
	
	if (low < high) {
				
		middle = (low + high) / 2;
		
		MergeSort(unsortedArray, low, middle);
				
		MergeSort(unsortedArray, middle + 1, high);
				
		Merge(unsortedArray, low, middle, high);
	}
	return;
}

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  Merge
//
// DESCRIPTION:   Performs the merge as part of the merge sort
// 
// INPUT:		  int* unsortedArray - Pointer to a unsorted array
//				  int low - Low index of the array
//				  int middle - Middle index of the array
//				  int high - High index of the array
// -------------------------------------------------------------------------------------------
void Merge(int* unsortedArray, int low, int middle, int high) {
	
	int insert,								// insertion value
		left = low,							// left index
		temp = low,							// temp index
		right = middle + 1;					// right index
	static int tempList[ARRAY_SIZE];		// temp array

	while (left <= middle && right <= high) {
		
		if (unsortedArray[left] <= unsortedArray[right]) {
			
			tempList[temp] = unsortedArray[left];
			left++;
			
		} else {
			
			tempList[temp] = unsortedArray[right];
			right++;
		}
		temp++;
	}
	
	if (left > middle) {
		
		for (insert = right; insert <= high; insert++) {
		
			tempList[temp] = unsortedArray[insert];
			temp++;
		}

	} else {
		
		for (insert = left; insert <= middle; insert++) {
			
			tempList[temp] = unsortedArray[insert];
			temp++;
		}
	}
	
	for (insert = low; insert <= high; insert++) {
		
		unsortedArray[insert] = tempList[insert];
	}
}
