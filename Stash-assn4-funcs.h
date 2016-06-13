// -------------------------------------------------------------------------------------------
// CODE FILENAME: Stash-assn4-funcs.h 
//
// DESCRIPTION:   MStash header file for Assignment 4
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  Matt Stash
// -------------------------------------------------------------------------------------------

#include "StahleyStash-assn4-common.h"

using namespace std;

void GenerateRandomArray(int* firstList, int* secondList);
int RandomNumber();
float CalculateAverage(int clockTicks[], int numRuns);
void DisplayResults(string firstTest, string secondTest, float firstAvg, float secondAvg);
void InsertionSort(int* unsortedArray, int low, int high);
void MergeSort(int* unsortedArray, int low, int high); 
void Merge(int* unsortedArray, int low, int middle, int high);
