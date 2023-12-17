/***************************************************************
 * Student name: Andrew Blythe
 * Program name: Land Calculation - Module 2 Prog Assignment
 * Program description: Calculates the number of acres in a 
 *                      tract of land with 389,767 square feet.
 * Date: August 26, 2020
***************************************************************/ 
#include <iostream>
using namespace std;

int main()
{
     double feetPerAcre = 43560; //Conversion factor for feet to acres, initialized
     double landTract;           //stores how many sq feet in tract we are using
     double result;              //stores the result 
     landTract = 389767;         //sq feet of land

    //Calculating Conversion
    result = landTract / feetPerAcre;
    //Displaying Output
    cout << landTract << " square feet equals " << result << " acres. \n";

     return 0;
}