/****************************************
* Student Name:  Andrew Blythe
* Program Name:
* Program Description:
*
*****************************************/
#include <iostream>
#include <string>
using namespace std;

enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};

class Phone
{
	protected:
		int areaCode;
		int number;
		int type;
	public:
		Phone()
		{
		    areaCode = 1;
			number = 0;
			//type = "Home";
        }
		Phone (int newAreaCode, int newNum, int newType)
		{
			areaCode = newAreaCode;
			number = newNum;
			type = newType;
		}
		void setACode(int nAC)
		{
			areaCode = nAC;
		}
		void setNum(int nNum)
		{
			number = nNum;
		}
		void setType(int t)
		{
			type = t;
		}
		int getACode()
		{
			return areaCode;
		}
		int getNum()
		{
			return number;
		}
		int getType()
		{
			return type;
		}

		virtual void write()
		{//This prints out the phone in the format: +1 (area code) xxx-xxxx - Home
            cout << "The phone number is: \n"
                 << "+1 (" << areaCode << ") " << (number/10000) << "-"
                 << (number-(10000*(number/10000))) << " - ";

        /* or    cout << "\nMethod 2..." << endl;
                 cout << " (" << areaCode << ") " << "(" << number.substr(0,3) << ")"
                 << number.substr(3,3) << "-" << number.substr(6,4) << " - ";           */

        /*Recall:  enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};    */
                 switch(type)
                 {
                     case 1 : cout << "Home" << endl;
                        break;
                     case 2 : cout << "Office" << endl;
                        break;
                     case 3 : cout << "Cell" << endl;
                        break;
                     case 4 : cout << "Fax" << endl;
                        break;
                     case 5 : cout << "Page" << endl;
                        break;
                     default : cout << "We're assuming \"Home\" because what you entered"
                                    << " is invalid." << endl;
                 }
        cout << "This is a United States phone number.\n" << endl;
          /**************** (U.S. is default) **********************/
        }

};

class IntlPhone: public Phone
{
	private:
		int countryCode;
		int newCountryCode;
		string countryName;
	public:
		IntlPhone()
		{
			countryCode = 1;
			countryName = "";
		}
		IntlPhone(int newCountryCode, string newCountryName, int ac, int num, int type):Phone(ac, num, type)
		{
			countryCode = newCountryCode;
			countryName = newCountryName;
		}
		void setCountryCode(int countryCode)
		{
			countryCode = newCountryCode;
		}
		void setCountryName(string newCountryName)
		{
			countryName = newCountryName;
		}
		int getCountryCode()
		{
			return countryCode;
		}
		string getCountryName()
		{
			return countryName;
		}
		virtual void write()
		{   //TODO: if the phone is an international phone number,
			//      override the write function to print the phone in this format:
			//      countryName - +countryCode (areacode) xxx-xxxx - [type]
            cout << "Here is what you entered: \n"
                 << countryName << " - +" << countryCode << " (" << areaCode << ") "
                 << (number/10000) << "-" << (number-(10000*(number/10000))) << " - ";

          /*  cout << countryName << " - +" << countryCode << " (" << areaCode << ") "
                 << "(" << number.substr(0,3) << ")" << number.substr(3,3) << "-"
                 << number.substr(6,4) << " - ";        */

    /*Recall:  enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};    */
             switch(type)
             {
                 case 1 : cout << "Home" << endl;
                    break;
                 case 2 : cout << "Office" << endl;
                    break;
                 case 3 : cout << "Cell" << endl;
                    break;
                 case 4 : cout << "Fax" << endl;
                    break;
                 case 5 : cout << "Page" << endl;
                    break;
                 default : cout << "We're assuming \"Home\" because what you entered"
                                << " is invalid." << endl;
             }


		}
};

void writePhone(Phone *myP);
void getUserInput(int *aC, int *num, string *t);

int main()
{

	int areaCode, countryCode, choice;
	int num;
	string countryName;
	int t;
	int type;

	do
	{//TODO: display the menu options and ask the user to enter an option (see my sample output)
        cout << "What would you like to do? \n"
             << "   1. Enter a U.S. phone number. \n"
             << "   2. Enter an international phone number. \n"
             << "\nType a number choice and hit enter.";
        cin >> choice;
        cout << endl;

		if (choice == 1) //U.S. number
        {//TODO: call the function to get user input for phone number in the U.S.
         //TODO: create a Phone object
         //TODO: print the phone by calling the local writePhone function
            cout << "United States country code is +1. \n"
                 << "Enter 3-digit area code, PRESS ENTER, then enter the rest of the number: \n"
                 << "...-......." << endl;
            cin >> areaCode;
            cout << "-";
            cin >> num;

            cout << "Now enter the number for the phone number type: \n"
                 << "1. HOME \n"
                 << "2. OFFICE \n"
                 << "3. CELL \n"
                 << "4. FAX \n"
                 << "5. PAGE \n";
            cin >> type;
        }

		else if (choice == 2 )
        {   //TODO: call the function to get user input for phone number
            //TODO: create a InterPhone object
            //TODO: print the phone by calling the local writePhone function
            cout << "From what country is the phone number you will be entering? ";
            cin >> countryName;
            cout << "Ok, now enter the country code:  +";
            cin >> countryCode;
            cout << "Now enter the phone number (with no formatting). \n";
            cin >> num;

        }

		else
		{   cout << "Neither was chosen.";  }

	}
	while (choice == 1 || choice == 2);

	void writePhone(Phone *myP);

	return 0;
}

void writePhone(Phone *myP)
{
	myP->write();
}

/*
void getUserInput(int *areaC, int *num, int *type)
{
    //TODO: implement this function
    //ask the user to enter the area code, the phone number and the type of phone
	//determine the type of phone using a switch statement that matches the user choice
	//and store the matching type in the string type
        cout << "Enter 3-digit area code, PRESS ENTER, then enter the rest of the number: \n"
             << "...-......." << endl;
        cin >> areaCode;
        cout << "-";
        cin >> num;

    cout << "Now choose the number corresponding to the phone number type: \n"
         << "1. HOME \n"
         << "2. OFFICE \n"
         << "3. CELL \n"
         << "4. FAX \n"
         << "5. PAGE \n"
    cin >> type;
}                                       */
