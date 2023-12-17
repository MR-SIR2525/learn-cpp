/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: isPrime Programming Assignment Chapter 6
 * Program description: Checks to see whether a number is prime or not
 * Date: 11/2/2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <windows.h>    //Needed to display colors and call Sleep
using namespace std;

bool isPrime(int=2);        //checks and returns if number is prime
int findFactors(int=2, bool=false);    //finds all factors of a number

int main()
{
    long long int num;  //stores number to check
    char choice;    //user's choice (Y/N) for checking a new number

    do
    {
        cout << "Enter a number and I'll tell you whether it's prime or not.\n"
            << "Your number:  ";  cin >> num;

        while (!cin || !(num > 1)) //input validation
        {
            cin.clear();  cin.ignore(100, '\n'); //input buffer reset
            cout << "Invalid input. Please try again.\nYour Number: ";
            cin >> num;
        }

        isPrime(num); //checks if number is prime and outputs result

        cout << "Would you like to try another number? (Y/N) ";
        cin >> choice;

    } 
    while (toupper(choice) == 'Y');

    cout << "\nGoodbye.";
    return 0;
}

bool isPrime(int n)
{
    //if (n % 2 == 0 || n % 3 == 0 || n % 5 == 0 || n % 7 == 0 || n % 11 == 0) //not prime scenario
    bool prime = false;
    int factors = findFactors(n, false);

    if (factors > 2)//not prime scenario
    {
        prime = false;
        cout << n << " is not a prime number. ";
    }
    else     //prime scenario
    {
        prime = true;
        cout << n << " is in fact a prime number. ";
    } 
    
     
    if (prime == false)
    {
        cout << "Would you like to know all the factors of " << n << "? ";

        if (factors > 100)
        {   
            // Get the handle to standard output device (the console)
            HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute (screen, 12); //Font color to bright red

            cout << "\nNote that the list could be very lenghty. ";
            
            if (factors > 750)
            {
                Sleep(1500);
                cout << "\n**Warning: Be prepared for A LOT of stuff to display.** ";
            }
            SetConsoleTextAttribute (screen, 7); //Back to default color
        }
        

        char choice;
        cout << "(Y/N) ";  cin >> choice;

        if (choice == 'Y' || choice == 'y')
            findFactors(n, true);
        else
            cout << "Ok. ";
        
    }

    return prime;
}


/* * * * * * * * * * function that finds every possible factor * * * * * * * * */
int findFactors(int n, bool display)
{
    int factorCount = 2; //defaultly two, can increase
    int ArrFactors[factorCount] = {1, n};

    //     arrayWalk is used to traversely store factors into the "ArrFactors" array
    for (int i = n, arrayWalk = 0; i != 0; i--, arrayWalk++) //finding and counting factors
    {
        if (n % i == 0)
        {
            factorCount++;
            ArrFactors[arrayWalk] = i; //where factor itself is stored
        }
    }

    if (display == true)
    {
        for (int f2=0; f2 < factorCount; f2++)
        {
            cout << n << " divided by " << ArrFactors[f2] << " = " << n/ArrFactors[f2];
        }
    }








    if (display == false)   
    {       //     arrayWalk is used to traversely store factors into the "ArrFactors" array
        for (int i = n, arrayWalk = 0; i != 0; i--, arrayWalk++) //finding and counting factors
        {
            if (n % i == 0)
            {
                factorCount++;
                ArrFactors[arrayWalk] = i; //where factor itself is stored
            }
        }
    }
    else    //counting and displaying factors
    {
        char choice;
        for (int i = n, tolerance = 500; i != 0; i--)
        {
            if (n % i == 0) //counts up and displays all factors
            {
                cout << " " << n << " divided by " << i << " = " << n/i << "\n";
                factorCount++;
            }

            if (factorCount % tolerance == 0 && tolerance != 2500) //offers chances to leave listing process
            {
                cout << "Would you like to keep going? (Y/N) ";
                cin >> choice;
                if (choice == 'Y' || choice == 'y')
                {
                    tolerance +=500;
                    if (tolerance == 2500) //this if() removes any more escape opportunities
                    {
                        cout << "We won't be ask anymore.\n";
                        Sleep(1500);
                    }
                    continue;
                }
                else
                    break;
            }   
        } //end of for loop
        cout << "\n";
    } //end of else statement

    return factorCount;
}