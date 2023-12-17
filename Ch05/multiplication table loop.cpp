/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Workspace & Template C++
 * Program description: 
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype> //
#include <string>
#include <chrono>   
#include <dos.h> //for delay    1 second = 1000 milliseconds
#include <conio.h> //for getch()
using namespace std;

void delay(unsigned int milliseconds); //well idk how this works
enum State {Illinois = 1, Indiana, Michigan, Wisconsin};

int main()
{
    int num;
    int factor;

	cout << "Enter the multiplication table (1-12) ";
    cin >> factor;

    while (factor < 1 || factor > 12) //validation of input
    {
        cout << "Enter a factor that's greater than 1 or less than 13.\n";
        cin >> factor;
    }

	for (int i = 1; i <= factor; i++)
    {
        cout << "\nMultiplication table for " << i << ": \n";
        for (num = 1; num <= 12; num++)
        {
            cout << i << " x " << num << " = " << (num*i) << endl;
            //cout << setw(4) << num  << setw(7) << (num * num) << endl; 
        }
    }
    


    return 0;
}