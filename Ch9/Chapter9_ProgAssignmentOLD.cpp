/***********************************************************************************************
 * Student Name: Andrew Blythe
 * Program Name: binarySearch Names
 * Program Description: Searches an array of strings for specified names.
 * Date: C++ 2 Spring 2019
*************************************************************************************************/ 
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Prototypes
void selectionSort(string [], int);
void showArray(const string [], int);
string upperCaseName (const string);
int binarySearch(string [], int, string);

int main()
{
   const int SIZE = 20;

   string names[SIZE] =
       {"Collins, Bill",  "Smiff, Bart",  "Michalski, Joe", "Griffin, Jim",
        "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill",
        "Allis, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
        "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
        "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth" };

	// Sorting the array
	selectionSort(names, SIZE);


    // Displaying the sorted names
	cout << " The names in alphabetical order (last name) are: \n";
	showArray(names, SIZE);

    /*******************************************
    *             binarySearch code
    ********************************************/
    string nameFind;       // Holds the name to search for
    int    results;        // Holds the search results

    cout << " Searching for Bill Wolfe..." << endl;
        nameFind = "Wolfe, Bill";
	results = binarySearch(names, SIZE, nameFind); // Searching for the name

        // If binarySearch returned -1, the name was not found
        if (results == -1)
            cout << " " << nameFind << " was not found in the array.\n";
        else
            cout << " " << nameFind << " was found in the array. \n"; 


	cout << "\n Searching for Randy Smiff..." << endl;
        nameFind = "Smiff, Randy";
	results = binarySearch(names, SIZE, nameFind); // Searching for the name

        if (results == -1)  // return of -1 means name not found
            cout << " " << nameFind << " was not found in the array.\n";
        else
        {  // Otherwise result contains the subscript of
           // the specified name in the array
            cout << " " << nameFind << " was found in the array. \n"; }

	cout << "\n Enter another name you wish to search for "
         << "in the format \"Lastname, Firstname\": ";
	getline(cin, nameFind);
	results = binarySearch(names, SIZE, nameFind); // Searching for the name

        if (results == -1)  // return of -1 means name not found
            cout << " " << nameFind << " was not found in the array.\n";
        else
        {  
			//Otherwise result contains the subscript of the specified name in the array
            cout << " " << nameFind << " was found in the array.\n"; 
		}

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
	int minIndex;
	string minValue;

	for (int startScan = 0; startScan < (size - 1); startScan++)
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
	{
		cout  << " " << count+1 << ". " << array[count] << " \n";
	}
}

/******************************************
 * -------- upperCaseName function -------*
 *****************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; // Local copy of stringIn to uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
	{
        s[pos] = toupper(s[pos]);
	}
    return s;
}

/*****************************************************************
 *                 binarySearch function                         *
 * Performs a binary search on array of strings with size        *
 * elements whose values are sorted in ascending order. The array*
 * is searched for the name stored in the value parameter. If the*
 * name is found, its array subscript is returned.               *
 * Otherwise, -1 is returned.                                    *
 *****************************************************************/
int binarySearch(string array[], int size, string value)
{
	int  first = 0,                     // First array element
	     last = size - 1,               // Last array element
	     middle,                        // Midpoint of search
	     position = -1;                 // Position of search value
	bool found = false;                 // Flag

	while (!found && first <= last)
	{
		middle = (first + last) / 2;    // Calculate midpoint
		if (array[middle] == value)     // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > value) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;         // If value is in upper half
	}
	return position;
}
