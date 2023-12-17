/********************************************************************************
 * Student name: Andrew Blythe
 * Program name: Geometry Calculator
 * Program description: Calculates the area of user-specified shapes.
 * Date: October 3, 2020
*********************************************************************************/ 
#include <iostream>
#include <istream>
#include <cmath>
#include <conio.h>     //for pausing prog with "getch()" 
using namespace std;

enum Menu {Circle = 1, Rectangle, Triangle, Quit};

int main()
{
    //User Menu interaction
    cout << "Geometry Calculator \n"
         << "1. Calculate the Area of a Circle \n"
         << "2. Calculate the Area of a Rectangle \n"
         << "3. Calculate the Area of a Triangle \n"
         << "4. Quit \n"
         << "Enter your choice (1-4): ";
    const double PI = 3.14159;
    int mChoice;
    cin >> mChoice;
    cin.ignore();
    cout << "\n";
    
    switch (mChoice)
    {
        case Circle:
            cout << "What is the radius of the circle? ";
            long double circArea,//circle area
                        r;   //circle radius
            cin >> r;
            if (r >= 0)
            {
                circArea = (pow(r, 2)) * PI ;
                cout << "\nThe area of the circle is " << circArea << " square [units]. \n";
            }
            else
                cout << "Sorry but the circle can't have a negative radius this time.";
            break;
        case Rectangle:
            cout << "What are the dimensions of the rectangle (length, width)? \n";
            long double l, w, recArea; //rectangle area
            cout << "Length: "; cin >> l;
            cout << "Width: "; cin >> w;
            if (l >= 0 && w >= 0)
            {
                recArea = l * w;
                cout << "\nThe area of the rectangle is " << recArea << " square [units]. \n";
            }
            else
                cout << "Length and Width can't be negative numbers.";
            break;
        case Triangle:
            cout << "What is the length of the triangle's base and its total height? \n";
            long double b, 
                   h,  
                   triArea; //triangle area
            cout << "Base Length: "; cin >> b;
            cout << "Height: "; cin >> h;
            if (b >= 0 && h >= 0)
            {
                triArea = 0.5 * b * h;
                cout << "\nThe area of the triangle is " << triArea << " square [units]. \n";
            }
            else 
                cout << "Both the base and the height should be zero or greater.";
            break;
        case Quit:
            cout << "You chose to quit the program. Goodbye. \n";
            break;
        default:
            cout << "Error... The valid choices are 1 through 4. Run the program again "
                 << "and select one of those.";
    } 

    cout << "\n\nEnd of Progam. Press Any Key to Exit.\n";
    //char pause;
    //cin.get(pause);   //didn't work for some reason
    getch();

    return 0;
}
