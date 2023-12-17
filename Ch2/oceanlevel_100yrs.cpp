/**********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Ocean Levels
 * Program description: The Earth’s ocean levels have risen an average of 1.8 millimeters per 
 *                      year over the past century. This program computes and displays the
 *                      number of centimeters and number of inches the oceans rose during 
 *                      this time. One millimeter is equivalent to 0.1 centimeters. 
 *                      One centimeter is equivalent to 0.3937 inches. 
 * Date: September 9, 2020
***********************************************************************************************/ 
#include <iostream>
using namespace std;

int main()
{
     float oceanLevelChange,            //fluctation of ocean level per year in MILLIMETERS
            resultInches,               //result in inches
            resultCM,                   //result in centimeters
            mmToCentimeters = 0.1,      //conversion factor for mm to cm
            cmToInches = 0.3937;        //conversion factor for cm to inches
     
     //Conversion & Computing
     oceanLevelChange = 1.8;
     resultCM = oceanLevelChange * mmToCentimeters; //finding ocean level change in cm, mm converted to cm
     resultInches = resultCM * cmToInches;          //Converting answer in cm to inches

     cout << "The ocean level has risen " << resultCM << " centimeters, or "
          << resultInches << " inches, over the last 100 years. \n";

     return 0;
}