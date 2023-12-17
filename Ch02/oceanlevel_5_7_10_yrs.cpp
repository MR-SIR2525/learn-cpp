/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Ocean Level in 5, 7, & 10 years
 * Program description: Assuming the ocean’s level is currently rising at about 1.5 millimeters 
 *                      per year: this program displays how much higher (in millimeters) the ocean
 *                      level will be in 5, 7, and 10 years. 
 * Date: September 11, 2020
*************************************************************************************************/ 
#include <iostream>
#include <string>
using namespace std;

int main()
{
     float rateOfChange = 1.5,//fluctation of ocean level per year in MILLIMETERS
           fiveYears,         //holds 5-year level
           sevenYears,        //holds 7-year level
           tenYears;          //holds ten-year level

     //Calculations
     fiveYears = 5*rateOfChange;
     sevenYears = 7*rateOfChange;
     tenYears = 10*rateOfChange;

     cout << "In 5 years, the ocean's level will have risen " << fiveYears << " millimeters.\n"
          << "In 7 years, the ocean's level will have risen " << sevenYears << " millimeters.\n"
          << "In 10 years, the ocean's level will have risen " << tenYears << " millimeters.\n";
     

     return 0;
}