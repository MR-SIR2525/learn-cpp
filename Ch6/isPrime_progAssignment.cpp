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

bool isPrime(long long int=2);        //checks and returns if number is prime
int findFactors(long long int=2, bool=false);    //finds all factors of a number

int main()
{
    long long int num =2;  //stores number to check
    char choice ='N';    //user's choice (Y/N) for checking a new number

    do
    {
        cout << "Enter a number and I'll tell you whether it's prime or not: ";
        cin >> num;

        while (!cin || !(num > 1)) //input validation
        {
            cin.clear();  cin.ignore(100, '\n'); //input buffer reset
            cout << "Invalid input. Please try again.\nYour Number: ";
            cin >> num;
            
            if (num == -1)
            {
                cout << "Override.\n";
                break;
            }
        }

        isPrime(num); //checks if number is prime and outputs result


        cout << "\nWould you like to try another number? (Y/N) ";
        cin >> choice;
        if (!cin)
        {
            choice = 'N';
            cin.clear();  cin.ignore(100, '\n');
        }

        //lets me see if "prime numbers" actually are prime
        if (choice == 't' || choice == 'T')
        {   
            choice = 'Y';
            cout << "Test Mode \n" << findFactors(num, true) << "\n";
        }

    } while (choice == 'Y' || choice == 'y');
    
    cout << "Ok goodbye.";
    return 0;
}

/* * * * * * * * * * * function for tesing if number is prime * * * * * * * * * * */
bool isPrime(long long int n)
{
    bool prime = false;
    int factors = findFactors(n, false);

    if (factors > 2)//not prime scenario
    {
        prime = false;
        cout << n << " is NOT a prime number. ";
    }
    else     //prime scenario
    {
        prime = true;
        cout << n << " is a prime number. ";
    } 
    
     
    if (prime == false)
    {
        cout << "\n-> Would you like to know all the factors of " << n << "? ";

        if (n >= 30000000)
        {   
            // Get the handle to standard output device (the console)
            HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute (screen, 12); //Font color to bright red

            cout << "\nNote that the list could be lenghty and it could take some time. ";
            
            if (n >= 70000000)
            {
                Sleep(1500);
                cout << "\nWarning: Be prepared for a lot of stuff to display and a long wait. ";
            }
            else if (n >= 150000000)
            {
                Sleep(1500);
                cout << "WARNING: Be prepared for a considerably long wait and long list. ";
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
int findFactors(long long int n, bool display)
{
    int factorCount = 0;

    if (display == false)   
    {
        //factorCount <= 3 gives the verdict quicker, good for numbers millions or more
        for (long long i = 1; i <= n && factorCount <= 3 ; i++)
        {
            if (n % i == 0)
                factorCount++;
        }
    }
    else //finding, counting and displaying factors
    {
        char choice;
        for (long long i = 1; i <= n; i++)
        {
            if (n % i == 0) 
            {
                cout << " " << i << " x " << n/i << " = " << n << "\n";
                factorCount++;
            } 

        } //end of for loop
        cout << "\n";
    } //end of else statement

    return factorCount;
}