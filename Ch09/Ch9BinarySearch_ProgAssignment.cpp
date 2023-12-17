/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Selection Sort - Progamming Assignment
 * Program description: "Sorts and searches an array of strings and then demstrates its 
 *                       functionanlity with a driver program."
 * Date: Feb 9, 2021
*************************************************************************************************/ 
#include <iostream>
#include <string>
using namespace std;

//Function prototypes
void selectionSort(string [], int);                   //sorts the array for binary search
string upperCaseName(const string);                   //helps sorting; recieves string, returns it in ALLCAPS
void displayFunction(string [], int);                 //displays the whole array
int binarySearch(string [], int size, string searchKey);//binary search
void resultFunction(int, string);                     //outputs whether binarySearch found search parameter


int main()
{
    const int SIZE = 20;
    string searchKey = "";

    //The array of strings, in this case names
    string names[SIZE] = { "Collins, Bill", "Smith, Bart", "Michalski, Joe", "Griffin, Jim",
                          "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
                          "Allison, Jeff", "Moreno, Juan", "Wolfe, Bill", "Whitman, Jean",
                          "Moretti, Bella", "Wu, Hong", "Patel, Renee", "Harrison, Rose",
                          "Smith, Cathy", "Conroy, Pat", "Kelly, Sean", "Holland, Beth" };
    
    cout << "This program takes an array of strings, sorts them, and allows you to search the array "
         << "for some names.\n\n";

    //Sorting the strings
    selectionSort(names, SIZE);

    //Displaying the (now sorted) strings
    displayFunction(names, SIZE);

    //Searching for a name that is in the array
    cout << "Auto ";
    searchKey = "Allison, Jeff";
    binarySearch(names, SIZE, searchKey);

    //Searching for a name NOT in the array
    cout << "Auto ";
    searchKey = "Smiff, Bart";
    binarySearch(names, SIZE, searchKey);

    //Now user gets to try
    cout << "Would you like to search for a name?\n";
    do
    {
        cout << "Type the name you want to search for, or just \"N\" to leave.\n--> "; 
        getline(cin, searchKey); //no input validation needed 

        if (upperCaseName(searchKey) == "N")
            break;
        else
        {
            binarySearch(names, SIZE, searchKey);
        }

    } while (upperCaseName(searchKey) != "N");


    cout << "\nEnd of program. Goodbye!";   
    return 0;
}


/*****************************************************************
 *                         binarySearch                          *
 * The array is searched for the string stored in the searchKey  *
 * parameter. If the string is found, its array subscript is     *
 * returned. Otherwise, -1 is returned.                          *
 *****************************************************************/
int binarySearch(string array[], int size, string searchParameter)
{
	int  first = 0,                     // First array element
	     last = size - 1,               // Last array element
	     middle,                        // Midpoint of search
	     position = -1;                 // Position of search value
	bool found = false;                 // Flag

    cout << "\nSearching for \"" << searchParameter << "\"... \n";

	while (!found && first <= last)
	{
		middle = (first + last) / 2;          // Calculate midpoint
		if (array[middle] == searchParameter) // If value is found at mid
		{
			found = true;
			position = middle;
		}
		else if (array[middle] > searchParameter) // If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;         // If value is in upper half
	}
    resultFunction(position, searchParameter);
    return position;
}
/**************************************************************
 *                       resultFunction                       *
 * A helping function for binarySearch                        *
 **************************************************************/
void resultFunction(int position, string searchParameter)
{
    if (position == -1)  // return of -1 means name not found
            cout << " " << searchParameter << " was not found in the array.\n";
    else
    {
        cout << " " << searchParameter << " was found in the array at #" << position+1 << ".\n"; 
    }
    cout << "\n";
}


/**************************************************************
 *                        selectionSort                       *
 * ascending-order sorting function for an array              *
 **************************************************************/
void selectionSort(string array[], int size) 
{
	int minIndex;
	string minValue;

	for (int start = 0; start < (size-1); start++)
	{
		minIndex = start;
		minValue = array[start];

		for(int index = start + 1; index < size; index++)
		 {
			if (upperCaseName(array[index]) < upperCaseName(minValue))
			{
				minValue = array[index];
				minIndex = index;
			}
         }

		array[minIndex] = array[start];
		array[start] = minValue;
	}
}


/*************************************************************
 *                     displayFunction                       *
 * This function displays the contents of array. The         *
 * parameter size holds the number of elements in the array. *
 *************************************************************/
void displayFunction(string array[], int size)
{
	for (int count = 0; count < size; count++)
	{
		cout  << " " << count+1 << ". " << array[count] << " \n";
	}
}

/*************************************************************
*                       upperCaseName                        *
*    Returns an uppercased copy of the string passed in      *
*************************************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; // Local copy of stringIn we'll uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}
