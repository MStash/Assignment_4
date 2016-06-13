// -------------------------------------------------------------------------------------------
// CODE FILENAME: Stahley-assn4-funcs.cpp 
//
// DESCRIPTION:   RStahley function file for Assignment 4
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  River Stahley
// -------------------------------------------------------------------------------------------

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "StahleyStash-assn4-common.h"
#include "Stahley-assn4-funcs.h"

//*****************************************************************************
//  FUNCTION:	  Menu
//  DESCRIPTION:  Processes menu choice, if valid calls RunTests until user
//				  chooses to exit
//  INPUT:        Parameters:	firstList - first array
//								secondList - second array
//  OUTPUT: 	  Return value: none
//  CALLS TO:	  MenuSelect, ValidateSelect, RunTests
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void Menu (int* firstList, int* secondList)
{
	char choice[2];
	bool valid = false,
		 runTest = true;
	
	int firstSort,
		secondSort;
	
	while (runTest)
	{
		// call MenuSelect
		
		MenuSelect (choice);
		
		// if user choices "EE" exit program
		
		if (choice[0] == 'E' && choice[1] == 'E') 
		{
			cout << endl;
			cout << "Exiting program!" << endl;
			runTest = false;
		}
		
		else
		{
			// call ValidateSelect
			
			valid = ValidateSelect (choice[0], firstSort);
			
			if (valid)
			{
				valid = ValidateSelect (choice[1], secondSort);
				
			}
			
			// call RunTests
			
			if (valid)
			{
				RunTests (firstSort, secondSort, firstList, secondList);
			}
		}
	}
	
	return;	
}

//*****************************************************************************
//  FUNCTION:	  MenuSelect
//  DESCRIPTION:  Displays the sort menu, allowing the user to select
//		  two sorting methods
//  INPUT:        Parameters:	selection - menu choice
//  OUTPUT: 	  Return value: none
//  CALLS TO:	  none
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void MenuSelect (char* selection)
{
	string menuChoice;	// menu selection
	bool valid;		// for input validation
	
	while (!valid)
	{
		// Display sort menu
	
		cout << "Choose two sorts you wish to compare:" << endl;
		cout << setw(23) << "B = Bubble Sort" << endl;
		cout << setw(26) << "I = Insertion Sort" << endl;
		cout << setw(22) << "M = Merge Sort" << endl;
		cout << setw(22) << "Q = Quick Sort" << endl;
		cout << setw(24) << "E = Exit Program" << endl;
		cout << endl;
		
		// prompt user for two letter choices
		
		cout << "Enter two letter choices (or EE to exit)" << " ";
		cin >> menuChoice;
		
		// display error if input is not two letters
		
		if (menuChoice.length() != DOUBLE)
		{
			cout << "Error - invalid input!" << endl;
			valid = false;
		}
		
		// convert input to upper case
		
		else
		{
			selection[0] = toupper(menuChoice[0]);
			selection[1] = toupper(menuChoice[1]);
			valid = true;
		}
	}	
}

//*****************************************************************************
//  FUNCTION:	  ValidateSelect
//  DESCRIPTION:  Validates menu choice
//  INPUT:        Parameters:	choice - menu choice
//							    sortSelection - sorting function
//  OUTPUT: 	  Return value: valid - true if valid, false if not
//  CALLS TO:	  none
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

bool ValidateSelect (char choice, int &sortSelection) 
{
	bool valid = true;
	
	switch (choice) 
	{
		case 'B': 
			sortSelection = BUBBLE;
			break;
		case 'I': 
			sortSelection = INSERTION;
			break;
		case 'M': 
			sortSelection = MERGE;
			break;
		case 'Q': 
			sortSelection = QUICK;
			break;
		default:
			cout << endl;
			cout << "Error - invalid input!" << endl; 
			cout << "Please enter two letter "
				 << "combinations of B, I, M, Q or E" << endl << endl;
			valid = false;
	}
	
	return valid;
}

//*****************************************************************************
//  FUNCTION:	  RunTests
//  DESCRIPTION:  Runs the selected sorts from the menu and validates the sorts
//  INPUT:        Parameters:	firstSort - sort function #1
//								secondSort - sort function #2
//							    firstList - first array
//								secondList - second array 
//  OUTPUT: 	  Return value: None 
//  CALLS TO:	  GenerateRandomArray, VerifySorted, CalculateAverage, 
//				  DisplayResults, BubbleSort, QuickSort, InsertionSort, 
//				  MergeSort
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void RunTests (int firstSort, int secondSort, int* firstList, int* secondList)
{
	sortFunction firstSortTest = sortFunctionArray[firstSort],
				 secondSortTest = sortFunctionArray[secondSort];
	
	int num,	// number of sort runs
	count = 0,	// counter
	startTime, endTime, runTime;	// for calculating runtime
	float avg1, avg2;	// for calculating average runtime
	
	// prompt user for number of sort runs
	
	cout << endl;
	cout << "Enter the number of times to repeat each sort (1 or more): ";
	cin >> num;
	cout << endl;
	
	// validate user input is 1 or more
	
	while (num <= 0)
	{
		cout << "ERROR - invalid input" << endl << endl;
		cout << "Enter the number of times to repeat each sort (1 or more): ";
		cin >> num;
	}
	
	int firstSortTotal[num];
	int secondSortTotal[num];
	
	for (int i = 0; i < num; i++)
	{
		// increment count
			
		count++;
			
		// start sorting
		
		cout << "Starting sort #" << count << "..." << endl;
		
		// call GenerateRandomArray
		
		GenerateRandomArray (firstList, secondList);
		
		// calculate runtime
		
		startTime = clock();
		firstSortTest (firstList, LOW_INDEX, HIGH_INDEX);
		endTime = clock();
		runTime = endTime - startTime;
		firstSortTotal[i] = runTime;
			
		cout << setw(18) << TEST_NAME[firstSort] << " time " << runTime << endl;
		
		startTime = clock();
		secondSortTest (secondList, LOW_INDEX, HIGH_INDEX);
		endTime = clock();
		runTime = endTime - startTime;
		secondSortTotal[i] = runTime;
			
		cout << setw(18) << TEST_NAME[secondSort] << " time " << runTime << endl;
		
		// verify both arrays were sorted properly
		
		bool verify = VerifySorted (firstList, secondList);
	
		if (verify == false)
		{
			system ("PAUSE");
			return;
		}
	}
		
		// call CalculateAverage
		
		avg1 = CalculateAverage (firstSortTotal, num);
		avg2 = CalculateAverage (secondSortTotal, num);	
		
		// call DisplayResults
		
		cout << endl;
		DisplayResults (TEST_NAME[firstSort], TEST_NAME[secondSort], avg1, avg2);
		
		cout << endl;
		system ("PAUSE");
		cout << endl;						
}

//*****************************************************************************
//  FUNCTION:	  BubbleSort
//  DESCRIPTION:  Sorts an array using the bubble sort
//  INPUT:        Parameters: list - random integer array 
//							  low - low array index
//							  high - high array index
//  OUTPUT:		  Return Value:	none
//  CALLS TO:	  None
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void BubbleSort (int* list, int low, int high)
{
	int swap;	// value swap
	int index;	// array index
	
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		for (index = 0; index < ARRAY_SIZE - i; index++)
		{
			if (list[index] > list[index + 1])
			{
				swap = list[index];
				list[index] = list[index + 1];
				list[index + 1] = swap;
			}
		}
	}
	
	return;
}

//*****************************************************************************
//  FUNCTION:	  QuickSort
//  DESCRIPTION:  Sorts an array using the quick sort
//  INPUT:        Parameters: list - random integer array 
//							  low - low array index
//							  high - high array index
//	OUTPUT:		  Return Value: none
//  CALLS TO:	  None
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void QuickSort (int* list, int low, int high)
{
	int i = low;	// low index
	int j = high;	// high index
	int swap;	// value swap
	int pivot = list[(low + high) / DOUBLE];	// pivot
	
	while (i <= j)
	{
		while (list[i] < pivot)
		{
			i++;
		}
		
		while (list[j] > pivot)
		{
			j--;
		}
		
		if (i <= j)
		{
			swap = list[i];
			list[i] = list[j];
			list[j] = swap;
			i++;
			j--;
		}
	}
	
	// recursive calls
	
	if (low < j)
	{
		QuickSort (list, low, j);
	}
	
	if (i < high)
	{
		QuickSort (list, i, high);
	}
	
	return;
}

//*****************************************************************************
//  FUNCTION:	  VerifySorted
//  DESCRIPTION:  Verifies the sort algorithm has correctly sorted the array
//  INPUT:        Parameters: sortedArray - sorted array 1
//							  sortedArray2 - sorted array 2
//  OUTPUT: 	  Return value: bool true for is verified, false if not 
//  CALLS TO:	  None
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

bool VerifySorted (int* sortedArray, int* sortedArray2)
{
	bool sorted = true;
	
	// determine if the array is sorted in ascending order 
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		// array is not sorted - exit the program
		
		if (sortedArray[i] > sortedArray[i + 1])
		{
			cout << endl << endl;
			cout << "Sorting Error! The program will terminate!" << endl;
			sorted = false;
		}
		
		if (sortedArray2[i] > sortedArray2[i + 1])
		{
			cout << endl << endl;
			cout << "Sorting Error! The program will terminate!" << endl;
			sorted = false;
		}
		
		// else return true
		
		cout << setw(23) << "Sorts validated" << endl;
		sorted = true;
		return sorted;
	}
}

//*****************************************************************************
//  FUNCTION:	  DestroyArray
//  DESCRIPTION:  Deallocates memory assigned to the array
//  INPUT:        Parameters:	list - random integer array
//  OUTPUT: 	  Return value:	none 
//  CALLS TO:	  None
//  IMPLEMENTED BY: Stahley
//*****************************************************************************

void DestroyArray (int* list)
{
	// set all array elements to zero
	
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		list[i] = 0;
	}
	
	// deallocate memory assigned to array
	
	free (list);
}
