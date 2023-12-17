/***********************************
 * Student name: Carson Grey Chapman
 * Program name: progammingProject15
 * Program description: Monkey Business
 * Date: 11-10-20
*************************************/ 
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <cctype>
#include <fstream>
#include <cstdlib>

using namespace std;

const int NUM_DAYS = 7;

void foodEaten(double[][NUM_DAYS], int /*NUM_MONKEYS but in main*/);
void avgFoodEaten(double[][NUM_DAYS], int /*NUM_MONKEYS but in main*/);
                                    
int main()
{
    const int NUM_MONKEYS = 3; //I put this in main becuase it was confusing me and the function 
    double amtOfFood[NUM_MONKEYS][NUM_DAYS];

    foodEaten(amtOfFood, NUM_MONKEYS);

    avgFoodEaten(amtOfFood, NUM_MONKEYS);
    
    return 0;
}

//you had   ...(int food[] [NUM_DAYS])
void foodEaten(double food[][NUM_DAYS], int Totalmonke)
{           //start monkeys at 0. Otherwise, it skips monkey #3 and day 7... the same for the rest of the loops
    for(int monkeys = 0; monkeys < Totalmonke; monkeys++)
    {       //start at 0
        for(int days = 0; days < NUM_DAYS; days++)
        {
            cout << "Enter the food (in pounds) eaten by " << monkeys << " on " << days << ": " << endl;
            cin >> food[monkeys][days];
                                            //you had your validation before the original input, I switched them
            while(food[monkeys][days] < 0)
            {
                cout << "Please enter a correct, value for pounds of food eaten (no negatives): "; cin >> food[monkeys][days];
            }
            
        }
    }
}
    //you had ...(int food[][NUM_DAYS])
void avgFoodEaten(double food[][NUM_DAYS], int allDaMonkes)
{
    double totalAvgFood;
    int totalFood = 0;
        //start monkeys = 0
    for(int monkeys = 0; monkeys < allDaMonkes; monkeys++)
    {       //start at 0
        for(int days = 0; days < NUM_DAYS; days++)
        {
            totalFood += food[monkeys][days];
        }

        totalAvgFood = totalFood / allDaMonkes*NUM_DAYS; //*NUM_DAYS

        cout << "The average food (in pounds) consumed daily by the monkeys is: " << totalAvgFood << endl;
    }
}

