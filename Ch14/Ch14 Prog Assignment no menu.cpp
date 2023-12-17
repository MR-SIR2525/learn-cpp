/****************************************
* Student Name: Andrew Blythe
* Program Name: Chapter 14 Programming Assignment
* Program Description:
*
*  1. Displays a "No Parking\" sign however many times user chooses.
*  2. Lets the user input a list of numbers to be summed up.
*  3. Reverses a word or phrase that the user types in.
*  Without MENU
*****************************************/
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
#include <istream>
#include <stdio.h>
using namespace std;

//Function Prototype
void dispSign(int);
int arraySum(int*, int size);
int showArray(int [], int);
int ArrayIn(int, int, int usrArray[ ]);
void printReverse(const string& str);

int main( )
{
        //Explain purpose of program
        cout << " The purpose of this program is to: \n"
             << "  a.) display a \"No Parking\" sign however many times you choose \n"
             << "  b.) have you input a list of numbers to be summed up \n"
             << "  c.) reverse a word or phrase that you type in \n" << endl;
        system("PAUSE");


//------------------------------------------------------------------
    //asking user how many times to call sign function
    cout << " Enter a number and I'll display the sign that many times:  ";
    int number;
    cin >> number;

//------------------------------------------------------------------
    //Call sign function to display message the given number of times
	cout << "\n";
	dispSign(number);
    cout << "\n----------------------------------------" << endl;
    system("PAUSE");

//------------------------------------------------------------------
    //Ask user for size for the array
    cout << " Now we're going to make a list of numbers, to add them all together in "
         << "a second. " << endl;

    cout << " How many numbers should the list have?  ";
    int SIZE;
    cin >> SIZE;
    cout << "\n        Ok, the list will have " << SIZE << " numbers... \n"
         << " Now, enter numbers one by one for the list, hitting ENTER after each one." << endl;

    //Ask user for array elements
    int usrArray[SIZE];
    int i;
    for (int i =0; i < SIZE; i++)
    {
        cout << " ";
        cin >> usrArray[i];
    }
    cin.ignore();
    cout << "\n";

//------------------------------------------------------------------
    //Adding the array's elements
    int result;   // Holds the sum result

    cout << " Your list of numbers is below: \n";
    showArray(usrArray, SIZE);
    result = arraySum(usrArray, SIZE);
    cout << " Adding them up together, we get " << result << ".\n";
    //printf("%d", arraySum(usrArray, SIZE));
    cout << "\n----------------------------------------" << endl;

//------------------------------------------------------------------
   //Calling the printReverse function
    cout << " Type in something you want to see written backwards. \n ";
    string reverseThis;
    getline(cin, reverseThis);
    cout << " \n That reversed = ";
    printReverse(reverseThis);
    cout << "\n----------------------------------------";

return 0;
}





//********************************************************
//                 display sign                          *
// A recursive function to display "No Parking" n times. *
//********************************************************
void dispSign(int num)
{
    if (num > 0)
    {
        cout << " No Parking. " << endl;
        dispSign(num-1);
    }
}

//*********************************************************
//                   arraySum                             *
// Computes sum of integer array "usrArray" of given size.*
//*********************************************************
int arraySum(int array[ ], int size)
{
    if (size <=0)
    {
        return 0;
    }
    //else
        return arraySum(array, size-1) + array[size-1];
}

//*********************************************
//            printReverse                    *
//  This prints a string in reverse.          *
//*********************************************
//An empty string is printed in reverse by doing nothing.
//A non empty string is printed in reverse by first printing
//the tail of the string in reverse, then printing the
//first character of the print last.  The tail of the string is
//what remains after you cut off the first element.
/*void printReverse(char *s)
{

} */
void printReverse(const string &str)
{
    size_t numOfChars = str.size();

    if(numOfChars == 1)
       cout << str << endl;
    else
    {
       cout << str[numOfChars - 1];
       printReverse(str.substr(0, numOfChars-1) );
    }
}

/*************************************************************
 *                        showArray     (non-recursive)      *
 * This function displays the contents of array. The         *
 * parameter SIZE holds the (or uses the user-given??) number*
 * of elements in the array.                                 *
 *************************************************************/
int showArray(int array[], int size1)
{
	for (int count = 0; count < size1; count++)
    cout << "  Item " << count+1 << ":  " << array[count] << "\n";
	cout << endl;
	return 0;
}
