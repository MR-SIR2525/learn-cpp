/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Monthly Rainfall Prog Assignment Chapter 8
 * Program description: 
 * Date: Nov 10, 2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
using namespace std;
 
int main()
{
    const int NUM_MONTHS = 13;
    
    double totalRainfall = 0,
           avgRainfall = 0;

    //parallel arrays for months and their respective rainfall values (both exclude index 0 and start at 1)
    string month[NUM_MONTHS] = {"N/A", "January", "February", "March", "April", "May", "June", 
                                 "July", "August", "September", "October", "November", "December"};
    double rainfall[NUM_MONTHS] = {0, 3, 2, 1, 1, 2, 3.5, 4.1, 4.8, 3.1, 2, 1.12, 0.85}; //parallel array for months' rainfalls

    int choice = 2;
    cout << "============================= Monthly Rainfall Report =============================\n\n"
         << "Would you like to input your own values (say 1) or use default values (say 2) -> ";  
    cin >> choice;
    
    //getting the rainfall values
    if (choice == 1)
    {
        for (int i = 1; i < NUM_MONTHS; i++)
        {
            cout << "Enter the rainfall for " << month[i] << ": "; 
            cin >> rainfall[i];

            //input validation
            while (!cin || (rainfall[i] < 0)) 
            {
                cin.clear();  cin.ignore(100, '\n'); //input buffer reset
                if (rainfall[i] < 0)
                    cout << "Invalid (negative) rainfall value. ";
                else 
                    cout << " Invalid input. ";
                cout << "Please try again.\nRainfall for " << month[i] << ": ";
                cin >> rainfall[i];
            }

            totalRainfall += rainfall[i];
        }
    }

    
    //variables to store indexes of highest and lowest rainfall months
    //and initialize them both to 1 because my arrays skip index 0
    int lowest = 1, highest = 1;


    //loop on all elements to get find indexes for highest/lowest rainfalls
    //if multiple months tie for least, or most, rainfall, the program doesn't account for that...
    for(int counter = 1; counter < NUM_MONTHS; counter++)
    {
        //update lowest index
        if(rainfall[counter] < rainfall[lowest])
            lowest = counter;
        //update highest index
        if(rainfall[counter] > rainfall[highest])
            highest = counter;
       
        //adding current value to accumulator
        totalRainfall += rainfall[counter];
    }


    //determining the average
    avgRainfall = totalRainfall / (NUM_MONTHS-1);

    //it all comes together
    cout << "\nThe total yearly rainfall was " << totalRainfall << " inches of rain.\n";
    cout << "The average monthly rainfall was " << avgRainfall << " inches.\n";
    cout << "The lowest rainfall was in " << month[lowest] << " with " << rainfall[lowest] << " inches.\n";
    cout << "The highest rainfall was in " << month[highest] << " with " << rainfall[highest] << " inches.\n";
    

    return 0;
}