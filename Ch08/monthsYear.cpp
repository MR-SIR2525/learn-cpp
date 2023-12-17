/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: 
 * Program description: 
 * Date: 11/4/2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
#include <fstream>  // Needed to use files
using namespace std;

//alias for an array of 13 elements of type string
typedef string monArray[13];

void printMonths(monArray, int arrSIZE);

int main()
{
    const int SIZE = 13; //1 through 12  plus 0 = 13
    string arrMonths[SIZE] = {" ", "Januray", "February", "March", "April", "May", "June", 
                            "July", "August", "September", "October", "November", "December"};
    
    int month; 
    
    cout << "Enter your birthday month number: ";
    cin >> month;

    while (!(month >= 1 && month <= 12))
    {
        cout << "\nSorry, I don't know that month.\n";        
        printMonths(arrMonths, SIZE);
    }

    cout << "\nYour birth month is " << arrMonths[month] << "\n\n";

    printMonths(arrMonths, SIZE);


    return 0;
}

void printMonths(monArray arrMonths, int arrSIZE)
{
    cout << "Months of the year are: " << endl;
                
                for (int m = 1; m < arrSIZE; m++)
                {
                    cout << arrMonths[m] << endl;
                }
            
            /*******Range Based for loop********
            for (string m: arrMonths)
            {
                if (m != " ")
                    cout << m << endl;
            }
            */
}