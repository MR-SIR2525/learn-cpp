#include <iostream>
#include <iomanip>
#include <string> 

using std::string;
using std::cout;
using std::cin;

void convert(double *measurement);

int main()
{
    string userInput = "";
    double measurement = 0.0;

    cout << "**Inches to Centimeters conversion** \nEnter inches: ";
    cin >> userInput;

    std::istringstream iss(userInput);

    if (iss >> measurement) 
    {
        cout << std::setprecision(3);
        cout << std::fixed << std::showpoint;

        cout << measurement << " in = ";
        convert(&measurement);

        cout << measurement << " cm\n";
    } 
    else 
        cout << "Input must be a number." << "\n";

    return 0;
}

void convert(double *measurement)
{
    *measurement = *measurement * 2.54;
}