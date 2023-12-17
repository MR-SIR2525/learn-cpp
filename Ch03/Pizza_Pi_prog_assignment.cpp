/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Pizza Pi (70110) - Prog Assignment
 * Program Instructions: 
 * Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size 
 * can be divided into. The program should perform the following steps:
 *      - Ask the user for the diameter of the pizza in inches.
 *      - Calculate the number of slices that may be taken from a pizza of that size
 *      - Display a message telling the number of slices.
 *      
 * To calculate the number of slices that may be taken from the pizza, you must know the 
 * following facts:
 *      - Each slice should have an area of 14.125 square inches.
 *      - To calculate the number of slices, simply divide the area of the pizza by 14.125.
 *      - The area of the pizza is calculated with this formula: Area = "pi r squared" 
 *        where pi is approximately 3.14159 and r is the radius (half the the diameter).
 * 			
 * Date: September 17, 2020
*************************************************************************************************/ 
#include <iostream>
#include <cmath>
#include <conio.h>       //for getch()
#include <iomanip>       //Header file needed for setprecision
using namespace std;

int main()
{
    const double pi = 3.14159,
                 policyForSliceArea = 14.125; //desired area (sq inches) of each slice at Joe's Pizza Palace 
    double diameter, //diameter of pizza in INCHES
           area,     //area of pizza in sq inches
           leftover; //leftover pizza in sq inches
     int slices;     //number of possible whole slices
        

    cout << "\nWhat's the diameter of the pizza in inches?  ____ inches\b\b\b\b\b\b\b\b\b\b";
    cin >> diameter;

    area = pi * pow(diameter/2, 2); //pi*(r^2)
    cout << "\nPizza's area is " << area << " square inches. \nPress ENTER to find how many slices are possible using "
         << "the policy of 14.125 square inches per slice. "; 
         getch(); //pauses and awaits input
    
    slices = area / policyForSliceArea;
    //leftover = remainder(area, dPolicy);
    leftover = (area / policyForSliceArea) - slices;
    cout << "\n\n" << slices << " whole slices can be taken, \n" 
         << "with " << setprecision(4) << leftover << " square inches of pizza left over. \n\n";

	return 0;
}