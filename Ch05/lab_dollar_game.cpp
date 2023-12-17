/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Looping Dollar Game
 * Program description: Asks user to input quantities of different coins to try and add up to a
 * dollar in total using a while loop to let them do it again.
 * Date: 10/7/2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    cout << "Want to know if you can win this game? "
         << "The objective of this game is to have a combination of coins that add "
         << "up to a dollar. \n";
    cout << fixed << showpoint << setprecision(2);
    const double PENNY = 0.01, NICKEL = 0.05, DIME = 0.10, QUARTER = 0.25; //value of coin
    int pennies, //number of pennies
        nickels, //number of nickels
        dimes,   //number of dimes
        quarters;//number of quarters
    double total = 0; //total value of all the coins
    
    char loop = 'Y'; //determines whether program loops or not (Sentinel?)
    do
    {
        cout << "To win, your coins should add up to $1.00. \n"
             << "How many of each coin do you have? \n"
             << "Pennies: "; cin >> pennies;
        cout << "Nickels: "; cin >> nickels;
        cout << "Dimes: ";  cin >> dimes;
        cout << "Quarters: "; cin >> quarters;
        
        total = pennies*PENNY + nickels*NICKEL + dimes*DIME + quarters*QUARTER;
        if (total == 1.00)
        {
            cout << "\nYou won the game! You have $" << total << " in your pocket! \n"
                 << "Want to try again with a different combination of coins? (Y or N): ";
            //cin >> loop;
        }
        else if (total > 1.00)
        {
            cout << "Uh oh, your coins add up to $" << total << " and over $1. \n"
                 << "Want to try again? (Y or N): ";
            //cin >> loop;

        }
        else if (total < 1.00)
            cout << "Oops, the total value of your coins is only $" << total << ". \n"
                 << "Want to try again? (Y or N): ";
            //cin >> loop;

        cin >> loop;
        if (loop == 'y' || loop == 'Y')
            cout << "Ok. ";
        else
            cout << "Alright, goodbye! Thanks for playing.\n\n";
               
    } while (loop == 'y' || loop == 'Y');
    
    

    return 0;
}