/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Selection Sort - Progamming Assignment
 * Program description: "Sorts an array of strings and then displays its functionality."
 * Date: Feb 8, 2021
*************************************************************************************************/ 
#include<iostream>
#include<string>
using namespace std;

// Function prototypes
string upperCaseName(const string);
void selectionSort(string [], int); 
void displayFunction(string [], int);


int main()
{
    const int SIZE = 20;

    //Array of strings
    string names[SIZE] = { "Collins, Bill", "Smith, Bart",   "Michalski, Joe", "Griffin, Jim",
                          "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
                          "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
                          "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
                          "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth" };

    cout << "This program takes an array of strings and sorts them.\n\n";

    cout << "Here is the array of names unsorted in the format LASTNAME, FIRSTNAME: \n\n";
    displayFunction(names, SIZE);
    cout << "\n";

    //Call a function to sort the strings
    selectionSort(names, SIZE);

    //Call a function to display the (now sorted) strings
    cout << "Now, here is the array of names sorted.\n\n";
    displayFunction(names, SIZE);

    return 0;
}


/**************************************************************
 *                        selectionSort                       *
 * ascending-order sorting function for an array              *
 **************************************************************/
void selectionSort(string array[], int size) 
{
	int minIndex;
	string minValue;

	for (int s = 0; s < (size-1); s++)
	{
		minIndex = s;
		minValue = array[s];

		for(int index = s + 1; index < size; index++)
		{
			if (upperCaseName(array[index]) < upperCaseName(minValue))
			{
				minValue = array[index];
				minIndex = index;
			}
        }

		array[minIndex] = array[s];
		array[s] = minValue;
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
