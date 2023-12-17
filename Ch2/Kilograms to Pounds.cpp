#include <iostream>
#include <iomanip> //idk yet
#include <cmath>   //math library

using namespace std;

int main()
{
    long miles;
    int feet;
    double inches;

    /*                  Muted for now 
    cout << "\n"; //For asthetics in terminal
    cout << "Enter miles, then feet, then inches - all separated by spaces. \n ";
    cin >> miles >> feet >> inches;

    cout << "You entered:  " << miles << " for miles, " << feet << " for feet, and " << inches 
         << " for inches. \n\n";
    */

   /******** New Thing **********/
   double pounds,
          conversion;
    
    cout << "Enter how many pounds of feed you, as a farmer, want and I'll convert it to kilograms: ";
    cin >> pounds;
    conversion = pounds * 2.2046226218;
    cout << pounds << " pounds, and that converts to " << conversion << " kilograms \n";

    return 0;
}