/**********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Combined Operators
 * Program description: Illustrates combined operators in action.
 * Date: September 9, 2020
***********************************************************************************************/ 
#include <iostream>
using namespace std;

int main()
{
    int x = 10;

    x += 1;
    cout << x << "\n";

    x += 1;
    cout << x << "\n";

    x /= 3;
    cout << x << "\n";

    //Checkpoint 3.19 on page 107
    int total, subtotal, tax, shipping;
    total = subtotal = tax = shipping = 0;

    cout << total << subtotal << tax << shipping << "\n";

    //Checkpoint 3.20 page 107
    int amount = 10;
    int y = 10;

    x += 6;
    amount -= 4; 

    return 0;
}