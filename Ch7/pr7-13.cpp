// This program demonstrates the use of a structure. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct PayRoll          
{
	int    empNumber;  // Employee number
	string name;       // Employee name
	double hours,      // Hours worked
	       payRate;    // Hourly pay rate
};

int main()
{
	PayRoll employee[3];  // Employee is a PayRoll structure
	double grossPay[3];   // Gross amount the employee earned this week
	double pr = 15;	//(pay rate)
	int savei;

	for (int i = 0; i < 3; i++)
	{
		//Get the employee's data
		cout << "Enter the employee's number: ";
		cin  >> employee[i].empNumber;

		cout << "Enter the employee's name: ";
		cin.ignore();	   // Skip the '\n' character left in the input buffer
		getline(cin, employee[i].name);

		cout << "Hours worked this week: ";
		cin  >> employee[i].hours;

		cout << "Employee's hourly pay rate: ";
		cin  >> employee[i].payRate;

		if (employee[i].payRate < pr)
		{
			pr = employee[i].payRate;
			savei = i;
		}

		// Calculate the employee's gross pay
		grossPay[i] = employee[i].hours * employee[i].payRate;
	}

	for(int i = 0; i < 3; i++)
	{	
		// Display the results
		cout << "\nHere is the employee's payroll data:\n";
		cout << "Name:            " << employee[i].name << endl;
		cout << "Employee number: " << employee[i].empNumber << endl;
		cout << "Hours worked:    " << employee[i].hours << endl;
		cout << "Hourly pay rate: " << employee[i].payRate << endl;
		cout << fixed << showpoint  << setprecision(2);
		cout << "Gross pay:      $" << grossPay[i] << endl;
	}

	return 0;
}
