/******************************************************************************
* Student Name:  Andrew Blythe
* Program Name: Chapter 16 Square Root with Exception Handling
* Program Description: User inputs an integer, program returns the
*                      square root of that integer, if it's a perfect square.
*******************************************************************************/
#include <iostream>
#include <string>
#include <cmath>
#include <exception>
using namespace std;

// Function prototypes
long getSquareRoot(long &num);
bool isPerfectSquare(long &num, long double &);

int main()
{
    long int num;
    long int result;
    string decision; //controls whether user loops or ends program

    do
    {
        cout << "This program determines if the number you enter has a square root.\n"
             << "Enter a number: ";
        cin >> num;
        while (!cin)
        {
            cin.clear();    cin.ignore();   num = 0;
            cout << "Invalid input. Please, only integers. \n";
            cin >> num;
            cin.ignore();
            if (num < 0)
                cout << "Notice: you'll end up getting an error message because of that negative "
                     << "number in a second..." << endl;
        }

        try
        {
            result = getSquareRoot(num); //throw is inside function
            cout << "The square root of " << num << " is " << result << endl;
        }
        catch (string exceptionString)
        {
            cerr << exceptionString << endl;
        }

        /********This is where user gets to either loop again or exit**************/
        cout << "\nWould you like to check another number? (Y or N)\n";
        cin >> decision;
        while ((decision != "y" && decision != "Y") && (decision != "n" && decision != "N"))
        {
            cin.ignore();
            cout << "Please, Y or N only: ";
            cin >> decision;
        }
        cout << "\n";
    } while (decision == "Y" || decision == "y");

    cout << "End of program. Goodbye.\n";
    return 0;
}

/***********************************************************
 * Calls isPerfectSquare 
************************************************************/
long getSquareRoot(long &num)
{
    long double root;
    if (num < 0)
        throw string("Negative numbers do not have perfect squares.");
    if (isPerfectSquare(num, root))
        return root;
    else
        throw string("That is not a perfect square.");
}

/************************************************************
 * Function to check if radicand is zero (will throw error),
 * checks if radicand is perfect square after.
 * Used by "getSquareRoot()"
 *************************************************************/
bool isPerfectSquare(long &num, long double &root)
{
    root = sqrt(num);
    //cout << "Internal " << root << endl; //displays what program finds
    return ((root - floor(root)) == 0); //Checks if root is an integer (found on Google)
                                        //If it's a double, then num wasn't a perfect square
}