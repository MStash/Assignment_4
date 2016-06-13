// -------------------------------------------------------------------------------------------
// CODE FILENAME: StahleyStash-Assn4-main.cpp
//
// DESCRIPTION:   This program compares the sort times of two selected sorts. The sort types
//				  are selected, then the number of times to run the tests is selected. The
//			      tests will then run, and the average times for all the sorts will be 
//				  displayed upon completion
//
// FUNCTIONS:	  GenerateRandomArray - Initializes an array with random integers
//
//				  RandomNumber - Creates a random number between the constant min and max 
//								 values
//
//				  CalculateAverage - Calculates the average time for the number of clocks 
//									 ticks with the number of runs
//
//				  DisplayResults - Displays the results of the sorting tests
//
//				  InsertionSort - Performs a insertion sort on an array
//
//				  MergeSort - Performs a merge sort on an array
//
//				  Merge - Performs the merge as part of the merge sort
//
//				  Menu - Processes menu choice, if valid calls RunTests until user chooses
//						 to exit
//
//				  MenuSelect - Displays the sort menu, allowing the user to select two 
//							   sorting methods
//
//				  ValidateSelect - Validates menu choice
//
//				  RunTests - Runs the selected sorts from the menu and validates the sorts
//
//				  BubbleSort - Sorts an array using the bubble sort
//
//				  QuickSort - Sorts an array using the quick sort
//
//				  VerifySorted - Verifies the sort algorithm has correctly sorted the array
//
//				  DestroyArray - Deallocates memory assigned to the array
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  River Stahley & Matt Stash
// -------------------------------------------------------------------------------------------

#include "Stash-assn4-funcs.h"
#include "Stahley-assn4-funcs.h"
#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// -------------------------------------------------------------------------------------------
// FUNCTION: 	  main
//
// DESCRIPTION:   Initializes the arrays, then displays the sort selection menu. Upon 
//				  completion of the tests, the arrays are then destroyed. 
//							   
// CALLS TO: 	  Menu, DestroyArray
// -------------------------------------------------------------------------------------------
int main() {

	int* firstArray = new int[ARRAY_SIZE];
	int* secondArray = new int[ARRAY_SIZE];
	
	Menu(firstArray, secondArray);
	
	DestroyArray(firstArray);
	DestroyArray(secondArray);

	return 0;
}
