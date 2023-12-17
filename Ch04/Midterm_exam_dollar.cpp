/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Midterm Dollar Game
 * Program description: 
 * Date: 10/5/2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    int pennies, nickels, dimes, quarters;
    const double PENNY = 0.01, NICKEL = 0.05, DIME = 0.10, QUARTER = 0.25;
    cout << "What of which coins would you like to use to make exactly one dollar? \n"
         << "Pennies: "; cin >> pennies;
    cout << "Nickels: "; cin >> nickels;
    cout << "Quarters: "; cin >> quarters;

    double total = pennies*PENNY + nickels*NICKEL + quarters*QUARTER;
    if (total == 1.00)
        cout << "Congratulations! You won!";
    else if (total > 1.00)
        cout << "Oops, you went over $1.";
    else if (total < 1.00)
        cout << "Uh oh, your coins don't add up to $1.";


    return 0;
}