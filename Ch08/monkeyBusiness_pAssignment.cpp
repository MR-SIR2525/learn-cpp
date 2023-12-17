/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Monkey Business Prog Assignment Chapter 8
 * Date: Nov 11, 2020
 * Program description: Gathers from input food consumption data for monkeys for a given week 
 *                      and then generates a report including: average daily food consumed, 
 *                                                             monkey that ate least on what day,
 *                                                             monkey that ate most on what day.
*************************************************************************************************/ 
#include <iostream>
using namespace std;

int main()
{
    const string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    int numMonkeys = 3;
    string monkeyName[numMonkeys] = {"Albert", "Brian", "Charlemagne"};
    double monkeyData[numMonkeys][7] = {{10, 11, 10, 14, 13,  8, 15}, //monkey 1 [0]
                                        {12, 13,  9, 12, 11,  9, 16}, //monkey 2 [1]
                                        { 9, 12,  9, 12, 10, 10, 13}};//monkey 3 [2]
    int choice = 2;
    cout << "==================== Monkey(s) Food Consumption for One Week ====================\n\n"
         << "Would you like to input your own values (say 1) or use default values (say 2) -> ";    
    cin >> choice;
    
    //Filling the array with each monkey's data for each day of the week
    if (choice == 1)
    {
        cout << "Enter food consumption, in pounds, for each monkey for all seven days of the week:\n";
        for (int day = 0; day < 7; day++)
        {	cout << daysOfWeek[day] << ":\n";
            for (int m = 0; m < numMonkeys; m++)
            {
                cout << " Monkey " << m + 1 << " (" << monkeyName[m] << "): ";
                cin >> monkeyData[m][day];
            //input validation
            while (!cin || (monkeyData[m][day] < 0)) 
            {
                cin.clear();  cin.ignore(100, '\n'); //input buffer reset
                if (monkeyData[m][day] < 0)
                    cout << "Invalid (negative) food quantity. ";
                else 
                    cout << " Invalid input. ";
                cout << "Please try again.\n   -> Monkey " << m + 1 << " (" << monkeyName[m] << "): ";
                cin >> monkeyData[m][day];
            }
            }
            cout << "\n"; 
        }
    }
    
    int mostMonkey, //index of monkey who ate most
        mostDay,    //day for ^
        leastMonkey, //index of monkey who ate least
        leastDay;    //day for ^
    double totalFoodConsumed = 0;    

    //finding average, least, and most food consumed by all monkeys in week
    leastMonkey = leastDay = 0;
    mostMonkey = mostDay = 0; //starting all indexes at 0
    for (int day = 0; day < 7; day++)
    {	for (int m = 0; m < numMonkeys; m++)
        {
            totalFoodConsumed += monkeyData[m][day];

            //update LOWEST monkey index
            if(monkeyData[m][day] < monkeyData[leastMonkey][leastDay])
            {
                leastMonkey = m;
                leastDay = day;
            }
            //update highest monkey index
            if(monkeyData[m][day] > monkeyData[mostMonkey][mostDay])
            {
                mostMonkey = m;
                mostDay = day;
            }
        }
    }
    
    //The Report
    double avgFoodAllMonkeys = totalFoodConsumed/(numMonkeys*7);
    cout << "\nAverage food consumed daily this week: " << avgFoodAllMonkeys << "\n";
    
    cout << "The least daily food consumed was by monkey #" << leastMonkey+1 << " (" << monkeyName[leastMonkey] << ") on " 
         << daysOfWeek[leastDay] << "\n";
    
    cout << "The most daily food consumed was by monkey #" << mostMonkey+1 << " (" << monkeyName[mostMonkey] << ") on " 
         << daysOfWeek[mostDay] << ".\n";
    
    

    return 0;
}

