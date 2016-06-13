// -------------------------------------------------------------------------------------------
// CODE FILENAME: Stahley-assn4-funcs.h 
//
// DESCRIPTION:   RStahley header file for Assignment 4
//
// CLASS/TERM:    CS372 Summer 16 8W1
//
// DESIGNER: 	  River Stahley
// -------------------------------------------------------------------------------------------

#ifndef STAHLEY_FUNCS_H
#define STAHLEY_FUNCS_H

// prototypes

void Menu (int* firstList, int* secondList);
void MenuSelect (char* selection);
bool ValidateSelect (char choice, int &sortSelection);
void RunTests (int firstSort, int secondSort, int* firstList, int* secondList);
void BubbleSort (int* list, int low, int high);
void QuickSort (int* list, int low, int high);
bool VerifySorted (int* sortedArray, int* sortedArray2);
void DestroyArray (int* list);

#endif
