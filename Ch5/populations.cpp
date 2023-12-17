/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Organism Population - Prog Assignment
 * Program description: Estimates population level after user inputs initial population and 
 *                      percent of daily increase while validating all user inputs. 
 * Date: October 12, 2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int initialPopulation = 0, //initial organisms
        numDays;    //total days to estimate population growth
    double dailyIncrease;   //percent (decimal) of daily population increase
    double totalPopulation; //holds estimated total population during loop

    bool flagInitialPopulation = false,
         flagDailyIncrease = false,
         flagNumDays = false;
    
    //start of program and initialPopulation input validation
    do
    {
        flagInitialPopulation = false; //prevents infinite loop if input is flagged invalid once
        cout << "How many initial organisms are there? ";
        cin >> initialPopulation;
        
        //input validation
        if (!cin)   
        {
            cin.clear();  cin.ignore(100, '\n');
            cout << "Invalid input! Infinite loop averted. Try again.\n";
            initialPopulation = 0;
            flagInitialPopulation = true;
        }
        else if (initialPopulation < 2)
        {
            cout << "\nSorry but the initial population needs to be greater than 1 organism. Try again.\n";
            initialPopulation = 0;
            flagInitialPopulation = true;
        }

    } while(flagInitialPopulation == true);
    

    //daily increase percentage input
    do 
    {    
        flagDailyIncrease = false;
        cout << "Enter the population's average daily increase percentage as a decimal: ";
        cin >> dailyIncrease;
        
        //input validation
        if (!cin) 
        {
            cin.clear();  cin.ignore(100, '\n');
            flagDailyIncrease = true;
            dailyIncrease = 0;
            cout << "\nInvalid input!\n";
        }
        else if(dailyIncrease < 0)
        {while (dailyIncrease < 0)
        {
            cout << "\nAverage daily increase percentage cannot be less than zero. Try again.";
            cout << "Percentage of growth: ";  cin >> dailyIncrease;
        }}
    } while (flagDailyIncrease == true);
    cout << "";
    

    /* * * * * * * * * * * * number of days * * * * * * * * * * * */ 
    do 
    {
        flagNumDays = false;
        cout << "How many days forward would you like to predict the population level? ";
        cin >> numDays;

        if (!cin) //input format validation
        {
            cin.clear();  cin.ignore(100, '\n');
            cout << "Invalid input!\n";
            numDays = 1;
            flagNumDays = true;
        }
        while (numDays < 1)
        {
            cout << "Days cannot be less than 1. Try again please.\n";
            cout << "Days: ";  cin >> numDays;
        }

    } while (flagNumDays == true);


    /* * * * * * * * * * * asking user if percentage is correct * * * * * * * * * * */ 
    char percentVerify; //To make sure user understands 2.0 is not 2% but actually 2000% for example
    do 
    {
    cout << "\nYou indicated " << dailyIncrease << " or " << (100*dailyIncrease) 
        << "% as the daily increase. Is this correct? (Y / N): ";
    cin >> percentVerify;
    
    if (percentVerify == 'N' || percentVerify == 'n')
    {
        cout << "Ok, no problem. What percent did you mean?\n";
        cout << "Percent as decimal: "; cin >> dailyIncrease;
        cout << "\nOk. I understood " << dailyIncrease*100 << "%.\n";
        
        if (!cin)   //because you can never be too sure...
        {
            cin.clear();  cin.ignore(100, '\n');
            cout << "Invalid input!\n";
            dailyIncrease = 0;
            flagDailyIncrease = true;
        }
        while (dailyIncrease < 0)
        {
            cout << "\nAverage daily increase percentage cannot be less than zero. Try again.";
            cout << "Percentage of growth: ";  cin >> dailyIncrease;
        }
    }
    else if (percentVerify == 'Y' || percentVerify == 'y')
    {
        cout << "Ok, just verifying.";
    }
    cout << "\n";

    } while (flagDailyIncrease == true);    //end of do while for dailyIncrease percentage


    /* * * * * * * * * * * * * * * * final output and estimation * * * * * * * * * * * * * * * */
    totalPopulation = initialPopulation;
    cout << "\nEstimated Population Levels for " << numDays << " days based on a " << (100*dailyIncrease)
         << "% daily population increase: \n";

    for (int day = 1; day <= numDays; day++)
    {
        totalPopulation += (totalPopulation*dailyIncrease);
        cout << setprecision(0) << fixed
             << "Population size on Day " << day << ": " << totalPopulation << "\n";
    }
    
    
    return 0;
}
/* 
 * sorry for the complexity but now the program is pretty hard to break no matter what kind of 
 * inputs you give it. It still acts up if you type an integer followed by a letter, like 
 * "000a" or "0.2f"
 */