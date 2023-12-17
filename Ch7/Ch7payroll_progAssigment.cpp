/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Ch7 Payroll Prog Assignment
 * Program description:
 * Date: Jan 27, 2021
 *************************************************************************************************/
#include <iostream>
#include <iomanip> // input/output manipulation
#include <cmath>
using namespace std;

class Payroll
{
private:
    double payRate,
        hoursWorked;

public:
    Payroll() // constructor for default values
    {
        payRate = 0;
        hoursWorked = 0;
    }
    Payroll(double r, double hrs) // makes class accept values to my variables
    {
        payRate = r; // r for rate
        hoursWorked = hrs;
    }

    void setPayRate(double);
    void setHoursWorked(double);
    double getPayRate();
    double getHoursWorked();
    double getGrossPay(double, double);
};

/******************************************************************
 *                     Payroll::setPayRate                        *
 *                                                                *
 ******************************************************************/
void Payroll::setPayRate(double p)
{
    payRate = p;
}

/******************************************************************
 *                   Payroll::setHoursWorked                      *
 *                                                                *
 ******************************************************************/
void Payroll::setHoursWorked(double h)
{
    hoursWorked = h;
}

/******************************************************************
 *                     Payroll::getPayRate                        *
 * Returns the hourly pay rate                                    *
 ******************************************************************/
double Payroll::getPayRate()
{
    return payRate;
}

/******************************************************************
 *                   Payroll::getHoursWorked                      *
 * Returns number of hours worked                                 *
 ******************************************************************/
double Payroll::getHoursWorked()
{
    return hoursWorked;
}

/******************************************************************
 *                     Payroll::getGrossPay                       *
 * Calculates and displays the wages from (payrate*hours)         *
 ******************************************************************/
double Payroll::getGrossPay(double payRate, double hrs)
{
    return payRate * hrs;
}


/*************************** int main *****************************/
int main()
{
    int employeeNum = 8;               // 7 employees, i=0 will not be used
    Payroll firstPayroll[employeeNum]; // array of Payroll objects
    double hours,
        payRate;

    // inputing data for Payroll object
    for (int i = 1; i < employeeNum; i++)
    {
        cout << "Enter data for employee #" << i << ":\n";

        cout << "Hourly Rate:   ";
        cin >> payRate;
        while (!cin || payRate < 0) // input validation
        {
            cin.clear();
            cin.ignore(100, '\n');
            if (payRate < 0)
            {
                cout << "Payrate cannot be less than 0. ";
            }
            cout << "Invalid input. Please try again.\n"
                 << "Hourly Rate:  ";
            cin >> payRate;
        }

        cout << "Hours Worked:  ";
        cin >> hours;
        while (!cin || hours < 0) // input validation
        {
            cin.clear();
            cin.ignore(100, '\n');
            if (hours < 0)
            {
                cout << "Hours worked cannot be less than 0. ";
            }
            cout << "Invalid input. Please try again.\n";
            cout << "Hours Worked:  ";
            cin >> hours;
        }

        if (hours > 60) // hours input correction
        {
            cout << "...NOTE: 60 hours worked is the maximum. 60 hours will be recorded.\n";
            hours = 60;
        }

        // Sending the info to the currently-selected object
        firstPayroll[i].setPayRate(payRate);
        firstPayroll[i].setHoursWorked(hours);
        cout << "\n";
    }

    // Displaying the data
    double p, // payrate
        h;    // hours worked

    cout << "Information about employees:  \n\n";

    cout << fixed << showpoint << setprecision(2);
    for (int i = 1; i < employeeNum; i++)
    {
        cout << "Employee #" << i << ":\n";
        p = firstPayroll[i].getPayRate();     // payRate
        h = firstPayroll[i].getHoursWorked(); // hours worked
        cout << "Hourly Rate:   " << p << "\n";
        cout << "Hours Worked:  " << h << "\n";
        cout << "Total Pay   = $" << firstPayroll[i].getGrossPay(p, h) << "\n";
        cout << "\n";
    }

    return 0;
}
