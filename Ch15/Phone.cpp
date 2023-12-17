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

enum PhoneType {HOME, OFFICE, CELL, FAX, PAGE};

class Phone
{
	private:
		int areaCode;
		int number;
		PhoneType type;
	public:
		Phone (int newAreaCode, int newNumber, PhoneType newType);
		void write() const;
};

int main()
{

	//code goes here

	return 0;
}

