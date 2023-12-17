/****************************************
* Student Name:  Andrew Blythe
* Program Name:
* Program Description:
*
*****************************************/
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;

enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};

class Phone
{
	protected:
		int areaCode;
		int num_count=0;
        char ch;
		char p_number[15]; //15 digit allowance for phone numbers of other nations
        long long number;
		int type;
	public:
		Phone()
		{
		    areaCode = 1;
			number = 0;
			//type = "Home";
        }
		Phone (int newAreaCode, long long newNumber, int newType)
		{
			areaCode = newAreaCode;
			number = newNumber;
			type = newType;
		}
		/*********muted**********
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
		}           ****/
		virtual void write() const
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
		string countryName;
	public:
		IntlPhone()
		{
			countryCode = 1;
			countryName = "";
		}
		IntlPhone(int newCountryCode, string newCountryName, int ac, long long num, int type):Phone(areaCode, number, type)
		{
			countryCode = newCountryCode;
			countryName = newCountryName;
		}
		void setCountryCode(int countryCode)
		{
			countryCode;
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

          /*  cout << "Here is what you entered: \n"
                 << countryName << " -  +" << countryCode << " (" << areaCode << ") "
                 << (number/10000) << "-" << (number-(10000*(number/10000))) << " - ";      ***/

            while (num_count<10)
            {
                 cin.get(ch);
                 if (isdigit(p_number[num_count]) ) p_number[num_count++]=ch;
            }

          /*method3*  cout << countryName << " - +" << countryCode << " (" << areaCode << ") "
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

void writePhone(Phone *myPhone);
void getUserInput(int *areaC, int *cCode, string *cName, long long *num, int *t);

int main()
{
	int areaCode, countryCode, choice;
	long long number;
	string countryName;
	//int t;
	//int type;
	int type;

	do
	{   //Menu Options
        cout << "What would you like to do? \n"
             << "   1. Enter a U.S. phone number. \n"
             << "   2. Enter an international phone number. \n"
             << "\nType a number choice and hit enter.  ";
        cin >> choice;
        cout << endl;

		if (choice == 1) //U.S. number
        {//TODO: call the function to get user input for phone number in the U.S.
         //TODO: create a Phone object
         //TODO: print the phone by calling the local writePhone function
            cout << "United States country code is +1. \n"
                 << "Enter the area code, PRESS SPACE, then enter the rest of the number: \n";
            cin >> areaCode >> number;

            cout << "Now enter the number for the phone number type: \n"
                 << "1. HOME \n"
                 << "2. OFFICE \n"
                 << "3. CELL \n"
                 << "4. FAX \n"
                 << "5. PAGE \n";
            cin >> type;
            Phone *myPhone = new Phone (areaCode, number, type);

            writePhone(myPhone);
        }

		else if (choice == 2 )
        {   //TODO: call the function to get user input for phone number
            //TODO: create a InterPhone object
            //TODO: print the phone by calling the local writePhone function
            getUserInput(&areaCode, &countryCode, &countryName, &number, &type);
            /*******
            cout << "From what country is the phone number you will be entering? ";
            getline(cin, countryName);
            cout << "Ok, now enter the country code:  +";
            cin >> countryCode;
            cout << "Now enter the phone number (with no formatting). \n";
            cin >> number;
            ********/

            IntlPhone *myIntlPhone = new IntlPhone(countryCode, countryName, areaCode, number, type);
            writePhone(myIntlPhone);

        }

        else
		{   
            cout << "Neither was chosen. Press ENTER to quit.";
            cin.get();  
        }


	} while (choice == 1 || choice == 2);


	return 0;
}

void writePhone(Phone *myPhone)
{
	myPhone->write();
}

void getUserInput(int *areaC, int *cCode, string *cName, long long *num, int *t)
{
    //TODO: implement this function
    //ask the user to enter the area code, the phone number and the type of phone
	//determine the type of phone using a switch statement that matches the user choice
	//and store the matching type in the string type

    cout << "From what country is the phone number you will be entering? ";
    cin.ignore();
    getline(cin, *cName);
    cout << "Enter the region's country code:  +";
    cin >> *cCode;
    cout << "Now, enter the area code, press ENTER, then enter the rest of the number: " << endl;
    cin >> *areaC;
    cout << "-";
    cin >> *num;


    cout << "Now choose the number corresponding to the phone number type: \n"
         << "1. HOME \n"
         << "2. OFFICE \n"
         << "3. CELL \n"
         << "4. FAX \n"
         << "5. PAGE \n";
    cin >> *t;
    cout << endl;
}
