// -------------------------------------------------------------------------------------------
// CODE FILENAME: StahleyStash-assn4-common.h 
//
// DESCRIPTION:   RStahley & MStash global constants and structures for assignment 4
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  Matt Stash
// -------------------------------------------------------------------------------------------

#ifndef COMMON_H
#define COMMON_H
#include <string>
#include <cstdlib>
#include "Stahley-assn4-funcs.h"
#include "Stash-assn4-funcs.h"

using namespace std;

const int ARRAY_SIZE = 100000,					// size of array of random unsorted ints
		  MIN_VALUE = 1,						// min value of int in unsorted int array
		  MAX_VALUE = 30000,					// max value of int in unsorted int array
		  LOW_INDEX = 0,						// low index for arrays
		  HIGH_INDEX = ARRAY_SIZE - 1,			// high index for arrays
		  NUM_SORTS = 4,						// number of sorts being tested
		  DOUBLE = 2;							
		  
enum SORTS {BUBBLE, INSERTION, MERGE, QUICK};	// enum representing each test

const string TEST_NAME[NUM_SORTS] = {"Bubble Sort", 		// test names
						  			 "Insertion Sort", 
						  			 "Merge Sort", 
						  			 "Quick Sort"};
			 
typedef void (*sortFunction)(int*, int, int); 	// function pointer
     
// array containing functions for function pointer
const sortFunction sortFunctionArray[NUM_SORTS] = {&BubbleSort, &InsertionSort, 
												   &MergeSort, &QuickSort};                                          
                                             
#endif
