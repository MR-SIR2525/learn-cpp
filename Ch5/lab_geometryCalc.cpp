/********************************************************************************
 * Student name: Andrew Blythe
 * Program name: Looping Geometry Calculator 
 * Program description: Calculates the area of user-specified shapes.
 * Date: October 7, 2020
*********************************************************************************/ 
#include <iostream>
#include <istream>
#include <cmath>
#include <conio.h>     //for pausing prog with "getch()" 
using namespace std;

enum Menu {Circle = 1, Rectangle, Triangle, Quit};

int main()
{
    const double PI = 3.14159;
    int mChoice = 0;    //user choice for menu
    char again = 'Y';         //determines if program will loop again
    int attempts = 0;   //program will end if attemps == 5
    while (again == 'Y' || again == 'y') 
    {
    //User Menu interaction
    cout << "Geometry Calculator \n"
         << "1. Calculate the Area of a Circle \n"
         << "2. Calculate the Area of a Rectangle \n"
         << "3. Calculate the Area of a Triangle \n"
         << "4. Quit \n"
         << "Enter your choice (1-4): ";
    cin >> mChoice;
    while (mChoice !=Circle && mChoice !=Rectangle && mChoice !=Triangle && mChoice != Quit && attempts <=5)
    {
        cout << "Invalid menu choice. Please a choice from the menu, 1 through 4.\n";
        cin >> mChoice;
        ++attempts;
    }
    
    cout << "\n";
    switch (mChoice)
    {
        case Circle:
            cout << "What is the radius of the circle? ";
            long double circArea,//circle area
                        r;   //circle radius
            cin >> r;
            while ((isalpha(r)) || r < 0)
            {
                cout << "Sorry but the circle can't have a negative radius today.\n"
                     << "Enter a positive radius value please: "; cin >> r;
                ++attempts;                
            }
            if (r >= 0)
            {
                circArea = (pow(r, 2)) * PI ;
                cout << "\nThe area of the circle is " << circArea << " square [units].\n";
                cout << "\nWould you like to calculate the area of another shape?\n(Y or N) ";
                cin >> again;
            }
            break;
        case Rectangle:
            cout << "What are the dimensions of the rectangle (length, width)? \n";
            long double l, w, recArea; //rectangle area
            cout << "Length: "; cin >> l;
            cout << "Width: "; cin >> w;
            while (l < 0 || w < 0 && attempts !=5)
            {
                cout << "Length and Width can't be negative numbers. Try again.\n";
                cout << "Rectangle Length: "; cin >> l;
                cout << "Rectangle Width: "; cin >> w;
                ++attempts;
            }
            if (l >= 0 && w >= 0)
            {
                recArea = l * w;
                cout << "\nThe area of the rectangle is " << recArea << " square [units]. \n";
                cout << "\nWould you like to calculate the area of another shape?\n(Y or N) ";
                cin >> again;
            }               
            break;
        case Triangle:
            cout << "What is the length of the triangle's base and its total height? \n";
            long double b, 
                   h,  
                   triArea; //triangle area
            cout << "Base Length: "; cin >> b;
            cout << "Height: "; cin >> h;
            while (b < 0 || h < 0 && attempts <=5)
            {
                cout << "Both the base and the height should not be negatives. Try again.\n";
                cout << "Base Length: "; cin >> b;
                cout << "Height: "; cin >> h;
                ++attempts;
            }
            if (b >= 0 && h >= 0)
            {
                triArea = 0.5 * b * h;
                cout << "\nThe area of the triangle is " << triArea << " square [units]. \n";
                cout << "\nWould you like to calculate the area of another shape?\n(Y or N) ";
                cin >> again;
            }
            break;
        /***
        case Quit:
            cout << "\nYou chose to quit the program. Goodbye.";
            break;
        default:
            cout << "The valid choices are 1 through 4. Please select one of those.\n\n";   ***/
    } //end of switch block
    if (mChoice == 4)
        again = 'N';    
    } //end of while loop

    if (attempts == 5)
    {
        cout << "You tried to enter negative values too many times. Press any key to exit.";
        getch();
    }
    else if (again !='y' || again !='y')
        cout << "\nYou chose to quit. Goodbye.\n\n";
    else
    {
        cout << "\n\nEnd of Progam. Press Any Key to Exit.\n";
        getch();
    }

    return 0;
}
