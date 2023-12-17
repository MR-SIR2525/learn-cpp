/***********************************************************************************************
 * Student name:  Andrew Blythe
 * Program name:  Average Rainfall Prog Assignment - Ch 3
 * Program Instructions: 
*         Write a program that calculates the average rainfall for three months. 
*         The program should ask the user to enter the name of each month, such 
*         as June or July, and the amount of rain (in inches) that fell each month. 
*         The program should display a message similar to the following:
*         "The average rainfall for June, July, and August is 6.72 inches."
 * Date:  September 17, 2020
*************************************************************************************************/ 
#include <iostream>
using namespace std;

int main()
{
    double avgRainfall, //average rainfall in INCHES
           m1avg, //avg rainfall month 1
           m2avg, //avg rainfall month 2
           m3avg; //avg rainfall month 3
    string month1, month2, month3; 

    cout << "\nPress ENTER when you're ready to enter the names of three months and their average rainfall data. \n";
    cin.get();  //allows me to do "Press Enter when ready" since "cin" skips over whitespace like ENTER     

    //Getting user input
    cout << " Month 1: ";
    cin >> month1;
    cout << " Month 2: ";
    cin >> month2;
    cout << " Month 3: ";
    cin >> month3;

    cout << " \nNow enter how much rainfall, in inches, each month had.\n"
         << "Average rainfall for " << month1 << ": ";
        cin >> m1avg;
    cout << "Average rainfall for " << month2 << ": ";
        cin >> m2avg;
    cin.ignore();
    cout << "Average rainfall for " << month3 << ": ";
        cin >> m3avg;

    //Calculation & Output
    avgRainfall = (m1avg + m2avg + m3avg)/3;
    cout << "\nThe average rainfall for " << month1 << ", " << month2 << ", and " << month3
         << " is " << avgRainfall << " inches. ";


    return 0;
}