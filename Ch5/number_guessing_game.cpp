/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Workspace & Template C++
 * Program description: 
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
#include <cmath>    // maths?
#include <cctype>   //
#include <string>
#include <chrono>   
#include <windows.h>// Needed to display colors and call Sleep
#include <ctime>
#include <conio.h>  // for getch() and pausing
#include <fstream>  // Needed to use files
using namespace std;

int main()
{
    unsigned seed;

    const int MIN_VALUE = 1;
    const int MAX_VALUE = 100;

    int num; //the random number
    int guess;
    int attempts = 5;
    int tries;
    char choice;

    seed = time(0);
    srand(seed);

    num = (rand() % (MAX_VALUE - MIN_VALUE + 1)) + MIN_VALUE;    

    cout << "= = = = = = = = = = = = GUESS THE NUMBER = = = = = = = = = = = =\n";
    
    do 
    {
    cout << "I am thinking of a number between 1 and 100...  can you guess it?\n";

    do
    {
        cout << "Your guess? ";
        cin >> guess;

        if (guess >=1 && guess <= 100) //input validation
        {
            if (guess == num) 
            {
                cout << "Congratulations! You guess correct!. It was " << num;
            }
            else if (num - guess == 2 || num - guess == 2 || guess - num == 2 || num - guess == 1)
            {
                cout << "You're hot.";
                tries++; attempts--;
                cout << "  Attempts remaining: " << attempts << "\n\n";
            }
            else if (guess < num)
            {
                cout << "Too low. Try again.";
                tries++; attempts--;
                cout << "  Attempts remaining: " << attempts << "\n\n";
            }
            else if (guess > num)
            {
                cout << "Tow high. Try again.";
                tries++; attempts--;
                cout << "  Attempts remaining: " << attempts << "\n\n";
            }
        }
        else 
        {
            cout << "Check your input.";
        }
    
    } while (guess != num && attempts != 0);

    if (attempts == 0 && guess != num)
        cout << "You ran out of attempts before guessing :(";
    else
        cout << "It took you " << tries << " attempts.\n";

    tries = 0;
    attempts = 0;
    cout << "Would you like to play again? (Y / N) ";
    cin >> choice;


    } 
    while (choice == 'Y' || choice == 'y');   



    




    return 0;
}