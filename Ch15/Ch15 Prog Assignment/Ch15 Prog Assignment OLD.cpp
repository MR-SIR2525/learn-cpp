/*****************************************************************************************
* Student Name:  Andrew Blythe
* Program Name:
* Program Description:
    Using inheritance, create an international phone number class,
    InterPhone, from the Phone class (Links to an external site.).

   1.) Implement the InterPhone class, its constructor, and its "write" function.
   2.) Make the necessary change to include the country code and country name variables
       to refer to an international number.
   3.) Write a driver program (main) and a function "writePhone" that takes a single
       parameter and uses dynamic binding to print either a U.S. phone number (Phone class)
       or an international phone number (InterPhone class). Make the necessary changes in
       the declaration of the Phone class so that WritePhone executes correctly. Make sure
       the driver program asks the user to enter the country code, the area code, the phone
       number, and the type of phone without any formatting. The program should output the
       phone in the format: +x (xxx) xxx-xxxx, the country and the type of phone.
   4.) Use a loop to allow the user to enter other phones. The program should stop when the
       user no longer wants to enter a phone number.

********************************************************************************************/
#include <iostream>
using namespace std;

enum PhoneType {HOME, CELL, OFFICE, FAX, PAGER};

class Phone //Base class, default (United States phone number)
{
	private:
		int areaCode;
		long long phoneNum;
		PhoneType type;

	public:
		int CountryCode;
		long long number = n;
		string countryName;
		Phone (int newAreaCode, long long newNumber, PhoneType newType)
		{
		    areaCode = newAreaCode;
		    phoneNum = newNumber;
		    type = newType;
		}
		virtual void write() const
		{
		    cout << "+" << countryCode << " (" areaCode << ") "
		}
};

class IntlPhone : public Phone //child of "Phone"
{
    public:
        IntlPhone (int newCountryCode, string newCountryName, int newAreaCode, long long newNumber);
    virtual void write()
    {
        cout << "Phone number: " << "+" << newCountryCode << " "
             << n << endl;
        cout << countryName;
    }


};


int main()
{
    int areaCode;
    string countryName;
    int countryCode;
    long long nbr;
    PhoneType type;
    int choice;

    cout << "What would you like to do?" << endl;
    cout << "   1. Enter a U.S. phone number. \n"
         << "   2. Enter an international phone number. \n"
         << "\nType a number choice and hit enter.";
        cin >> choice;
        cout << endl;

    void writePhone
    {
        cout << "[writePhone]" << endl;
    }

    if (choice == 1) //U.S.
    {
        cout << "United States country code is +1. \n"
             << "Enter 3-digit area code, PRESS ENTER, then enter the rest of the number: \n"
             << "...-......." << endl;
        cin >> areaCode;
        cout << "-"
        cin >> nbr;

        cout << "What type of phone number is it? ("
    }

    if else (choice == 2 )
    {
        cout << "What country is the phone number you will be entering? ";
        cin >> countryName;
        cout << "Ok, now enter the country code: +";
        cin >> countryCode;
        cout << "Now enter the phone number (with no formatting). \n"
        cin >> nbr;

    }

	return 0;
}

