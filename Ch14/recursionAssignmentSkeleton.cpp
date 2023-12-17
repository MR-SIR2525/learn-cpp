/****************************************
* Student Name:
* Program Name:
* Program Description:
*
*****************************************/

#include <iostream>
#include <cstring>
using namespace std;

//Function Prototype
void sign(int);
int arraySum(int a[ ], int size);
void printReverse(char *);

int main( )
{
    //Calling the sign function
    cout << "Enter an integer value and I will display a sign:  ";
    int number;
    cin >> number;

    // Call sign to display a message the given number of times
	sign(number);
    cout << "\n----------------------------------------" << endl;
    cout << "\nIn the next steps, you will enter the size of your array,"
         << " and the contents of your array.\n" << endl;
    system("PAUSE");
    /**********************************************/

	//Explain purpose of program

	//Get input from user

	// Print the sum

    cout << "\n----------------------------------------" << endl;
	cout << "\nIn the next steps, you will enter a string and I will reverse it.\n" << endl;
	system("PAUSE");
   /***********************************************************************/

   //Calling the printReverse function


   return 0;
}

//********************************************************
//                 sign                                  *
// A recursive function to  display No Parking num times.*
//********************************************************
void sign(int num)
{
    if (num > 0)
   {
      cout << "No Parking." << endl;
      num--;
   }
}

//*********************************************************
//                   arraySum                             *
// Computes sum of integer array arr of given size.       *
//*********************************************************
int arraySum(int arr[ ], int size)
{

}

//*********************************************
//            printReverse                    *
//   prints a string in reverse.              *
//*********************************************

//An empty string is printed in reverse by doing nothing.
//A non empty string is printed in reverse by first printing
//the tail of the string in reverse, then printing the
//first character of the print last.  The tail of the string is
//what remains after you cut off the first element.
void printReverse(char *s)
{

}





