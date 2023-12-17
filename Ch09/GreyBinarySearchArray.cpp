/****************************************
* Student Name: Grey Chapman
* Program Name: selectionSortArray
* Program Description: Use selcetionSort function to produce an array of strings rather than an array of ints.
*****************************************/

#include<iostream>
#include<string>

using namespace std;

// Function prototypes
void selectionSort(string[], int);
void swap(string &, string &);
void displaySortedStrings(string[], int);
int binarySearch(string[], int, string);
string upperCaseName(const string);

int main()
{
    const int SIZE = 20;

    // Set up the array of strings, in this case names
    string name[SIZE] = { "Collins, Bill", "Smith, Bart",   "Michalski, Joe", "Griffin, Jim",
                          "Sanchez, Manny", "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
                          "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
                          "Moretti, Bella", "Wu, Hong",     "Patel, Renee",   "Harrison, Rose",
                          "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth" };

    // Call a function to sort the strings
    selectionSort(name, SIZE);

    // Call a function to display the (now sorted) strings
    displaySortedStrings(name, SIZE);

    string inName;

    cout << "\n";
    cout << "Enter a name to search within the index: "; getline(cin, inName);
    cout << "\n";

    int position = binarySearch(name, SIZE, inName);

    if(position != -1)
    {
        cout << name[position] << " was found in the array." << endl;
    }
    while(position == -1)
    {
        cout << inName << " was NOT found in the array. Please enter another name: " << endl;
        getline(cin, inName);
    }
    
    return 0;
}

void selectionSort(string arrayNames[], int arraySize)
{
    int minIndex;
    string minValue;

    for(int i = 0; i < (arraySize-1); i++)
    {
        minIndex = i;
        minValue = arrayNames[i];

        for(int index = i + 1; index < arraySize; index++)
        {
            if(upperCaseName(arrayNames[index]) < upperCaseName(minValue))
            {
                minValue = arrayNames[index];
                minIndex = index;
            }
        }
        
        swap(arrayNames[minIndex], arrayNames[i]);

    }
}

void swap(string &i, string &v)
{
    string temp = i;
    i = v;
    v = temp;
}

void displaySortedStrings(string name[], int SIZE)
{
    cout << "\n";
    cout << "The names in sorted order are: " << endl;
    cout << "\n";

    for(int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ". " << name[i] << endl; //put this is selectionSortArray assignment
    }
}

int binarySearch(string name[], int size, string searchIndex)
{
	int  first = 0,
	     last = size - 1,
	     middle,
	     position = -1;
	bool found = false;

    while (!found && first <= last)
	{
		middle = (first + last) / 2;

		if (name[middle] == searchIndex)
		{
			found = true;
			position = middle;
		}
		else if (name[middle] > searchIndex)
        {
			last = middle - 1;
        }
		else
			first = middle + 1;
	}

	return position;

}

/*************************************************************
* upperCaseName*
* Called by: selectionSort and binarySearch *
* Passed : A string *
* Returns : An uppercased copy of the string passed in *
*************************************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; // Local copy of stringIn we'll uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}