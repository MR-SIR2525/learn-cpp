/******************************************************************************
* Student Name:  Andrew Blythe
* Program Name: Chapter 15 Programming Assignment - Phone Numbers
*
* Program Description: Takes in either a U.S. phone number or a foreign one,
*                      then you specify some info about it.
*
*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;

enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};

class Phone
{
	protected:
		int areaCode;
		long long number;
		int type;
		int countryCode;
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

		virtual void write()
		{
		    //Overrides country codes not from United States.
            if (countryCode != 1)
            {
                cout << "\n*NOTE: Country code overridden to \"+1\" because you're in U.S. mode*" << endl;
                countryCode = 1;
            }
            else
            {
                countryCode = 1;
            }

            //This prints out the phone in the format: +1 (area code) xxx-xxxx - Home
            cout << "The phone number is: \n"
                 << "+1 (" << areaCode << ") " << (number/10000) << "-"
                 << (number-(10000*(number/10000))) << " - ";

            /*Recall:  {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};    */
             switch(type)
             {
                 case 1 : cout << "Home";
                    break;
                 case 2 : cout << "Office";
                    break;
                 case 3 : cout << "Cell";
                    break;
                 case 4 : cout << "Fax";
                    break;
                 case 5 : cout << "Page";
                    break;
                 default : cout << "We're assuming \"Home\" because the type you entered is invalid.";
                 }
            cout << " - United States\n" << endl;
          /**************** (U.S. is default) *******************/
        }

};

class IntlPhone: public Phone
{
	private:
		int newCountryCode;
		string countryName;
	public:
		/****defaults for IntlPhone?****/
		IntlPhone()
		{
			countryCode = 1;
			countryName = "";
		}
		IntlPhone(int newCountryCode, string newCountryName, int areaCode, long long number, int type):Phone(areaCode, number, type)
		{
			countryCode = newCountryCode;
			countryName = newCountryName;
		}

		virtual void write()
		{
            cout << "Here is what you entered: \n"
                 << "  +" << countryCode << " (" << areaCode << ") "
                 << /** (number/10000) << "-" << (number-(10000*(number/10000))) **/ number << " - ";

    /*Recall:  enum PhoneType {HOME=1, OFFICE=2, CELL=3, FAX=4, PAGE=5};    */
             switch(type)
             {
                 case 1 : cout << "Home";
                        break;
                case 2 : cout << "Office";
                    break;
                 case 3 : cout << "Cell";
                    break;
                 case 4 : cout << "Fax";
                    break;
                 case 5 : cout << "Page";
                    break;
                 default : cout << "We're assuming \"Home\" because the type you entered"
                                << " is invalid.";
             }
            cout << " - " << countryName << endl;

		}
};

void writePhone(Phone *myPhone);
void getUserInput(int *countryCode, int *areaCode, long long *number, int *t);

int main()
{

	int areaCode, countryCode, choice;
	long long number;
	string countryName;
	int type;

	do
	{//TODO: display the menu options and ask the user to enter an option (see my sample output)
        cout << "  What would you like to do? \n"
             << "     1. Enter a U.S. phone number. \n"
             << "     2. Enter an international phone number. \n"
             << "     3. Exit. \n"
             << "\n  Type a number from the choices above and hit enter.  ";
        cin >> choice;

		if (choice == 1) //U.S. number
        {
            cout << "  -> You chose United States. \n" << endl;
            getUserInput(&countryCode, &areaCode, &number, &type);

            Phone *myPhone = new Phone (areaCode, number, type);

            writePhone(myPhone);

            cout << "-------------------------------------------------------------------------------\n\n"
                 << "  You can either enter another number or exit." << endl;
        }

		else if (choice == 2 )
        {   //TODO: call the function to get user input for phone number
            //TODO: create a InterPhone object
            //TODO: print the phone by calling the local writePhone function
            cout << "From what country is the phone number you will be entering? ";
            cin.ignore();
            getline(cin, countryName);
            getUserInput(&countryCode, &areaCode, &number, &type);

            IntlPhone *myIntlPhone = new IntlPhone(countryCode, countryName, areaCode, number, type);
            writePhone(myIntlPhone);

            cout << "-------------------------------------------------------------------------------n\n"
                 << "  You can either enter another number or exit." << endl;

        }

		else
        {/*   //recursive confirmation for leaving
            string leaving; //controls confirmation
            cout << "Are you sure you want to leave? (y/n) \n\n ";
			cin >> leaving;
                if (leaving = "y", "yes")
                {                                        */
                    cout << "\n Goodbye." << endl;       /*
                }
                else if (leaving = "n", "no")
                {
                    return main();
                }                           */
        }

	} while (choice == 1 || choice == 2);

	return 0;
}

void writePhone(Phone *myPhone)
{
	myPhone->write();
}

void getUserInput(int *cCode, int *areaC, long long *num, int *t)
{
    //TODO: implement this function
    //ask the user to enter the area code, the phone number and the type of phone
	//determine the type of phone using a switch statement that matches the user choice
	//and store the matching type in the string type
        cout << "Enter the region's country code:  +";
        cin >> *cCode;
        cout << "Now, enter the area code, PRESS ENTER, then enter the rest of the number with no formatting: " << endl;
        cin >> *areaC;
        cout << "\t";
        cin >> *num;

        cout << "Now choose the number corresponding to the phone number type: \n"
             << "1. HOME \n"
             << "2. OFFICE \n"
             << "3. CELL \n"
             << "4. FAX \n"
             << "5. PAGE \n";
        cout << "\n ";
        cin >> *t;
}
