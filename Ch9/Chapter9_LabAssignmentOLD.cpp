/************************************************************************************
 * Student Name: Andrew Blythe
 * Program Name: Name Sorter
 * Program Description: This program, when completed, will sort a set of strings.
 * Date: C++2 1st, spring 2020
*************************************************************************************/
#include <iostream>
#include <string>
using namespace std;

// Prototypes
void selectionSort(string [], int);
void showArray(const string [], int);
string upperCaseName (const string);

int main()
{
   const int SIZE = 20;

   string name[SIZE] =
   {"Collins, Bill",  "Smiff, Bart",  "Michalski, Joe", "Griffin, Jim",
    "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
    "Allis, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
    "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
    "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};

	// Sorting the array
	selectionSort(name, SIZE);

    // Displaying the sorted names
	cout << "The names in alphabetical order (last name) are: \n";
	showArray(name, SIZE);
	return 0;
}

/**************************************************************
 *                        selectionSort                       *
 * This function performs an ascending-order selection sort   *
 * on array. The parameter size holds the number of elements  *
 * in the array.                                              *
 **************************************************************/
void selectionSort(string array[], int size)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (upperCaseName(array[index]) < upperCaseName(minValue))
			{
				minValue = array[index];
				minIndex = index;
			}
      }
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}
/*************************************************************
 *                        showArray                          *
 * This function displays the contents of array. The         *
 * parameter size holds the number of elements in the array. *
 *************************************************************/
void showArray(const string array[], int size)
{
	for (int count = 0; count < size; count++)

		cout  << count+1 << ". " << array[count] << " \n";
	cout << endl;
}

/******************************************
 * -------- upperCaseName function -------*
 *****************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; // Local copy of stringIn to uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}
