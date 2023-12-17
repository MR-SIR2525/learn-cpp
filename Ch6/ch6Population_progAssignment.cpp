/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Population Programming Assignment Chapter 6
 * Program description: Displays the starting population and the projected population at the end 
 *                      of each year using a function that calculates and returns the projected 
 *                      new size of the population. 
 * Date: 11/2/2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>
using namespace std;

/* Calculation function parameters: Values match sample output with popCalculation(int, double, double)
 * when passed double, double, double. However, values are slightly off from sample output 
 * when popCalculation(double, double, double) is passed double, double, double with rounding,
 * but I think it would actually be more accurate this way. 
 */
double popCalculation(int=2, double=0, double=0); 

int main()
{
    int initialPopulation = 2,
        years = 1;
    double birthRate = 0,
            deathRate = 0,
            population,
            newPopulation;

    cout << "Enter starting population: "; cin >> initialPopulation;
    while (!cin || initialPopulation < 2)
    {   
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Hey, that's not a valid input. Try again.\n"
             << "Enter starting population: ";  cin >> initialPopulation;
    }

    cout << "Enter annual birth rate: "; cin >> birthRate;
    while (!cin || birthRate < 0) //input validation
    {   
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Invalid input. Please try again.\n"
             << "Enter annual birthrate: "; cin >> birthRate;
    }

    cout << "Enter annual death rate: "; cin >> deathRate;
    while (!cin || deathRate < 0) //input validation
    {   
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Yo, that's not a valid input. Try again.\n"
             << "Enter annual deathrate: "; cin >> deathRate;
    }

    cout << "Enter how many years to display: "; cin >> years;
    while (!cin || years < 1) //input validation
    {   
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Yo, that's not a valid input. Try again.\n"
             << "Enter how many years: "; cin >> years;
    }
    
    population = newPopulation = initialPopulation;
    
    for (int i = 1; i <= years; i++)
    {
        cout << fixed << setprecision(0); //rounding instruction 
        
        population = newPopulation;
        cout << "Year " << i << ":\n"
             << "   Beginning Population: " << population;
        
        newPopulation = popCalculation(population, birthRate, deathRate);

        cout << "   Ending Population: " << newPopulation;
        cout << "\n";        
    }

    return 0;
}


double popCalculation(int population, double birthRate, double deathRate)
{
    return population*(1+birthRate)*(1-deathRate);
}