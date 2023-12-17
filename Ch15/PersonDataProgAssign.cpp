/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name:
 * Program description: 
 * Date: 4/10/2021
 *************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <limits>
using namespace std;

class PersonData
{
private:
    string lastName, firstName, address, city, state, zip, phone;

public:
    PersonData()
    {
    }
    // set and get methods
    void setLastName(string lastName)
    {
        this->lastName = lastName;
    }
    string getLastName()
    {
        return lastName;
    }
    void setFirstName(string firstName)
    {
        this->firstName = firstName;
    }
    string getFirstName()
    {
        return firstName;
    }
    void setAddress(string add)
    {
        this->address = add;
    }
    string getAddress()
    {
        return address;
    }
    void setCity(string city)
    {
        this->city = city;
    }
    string getCity()
    {
        return city;
    }
    void setState(string state)
    {
        this->state = state;
    }
    string getState()
    {
        return state;
    }
    void setZip(string zip)
    {
        this->zip = zip;
    }
    string getZip()
    {
        return zip;
    }
    void setPhone(string phone)
    {
        this->phone = phone;
    }
    string getPhone()
    {
        return phone;
    }
};

// Parameters: `lastname`, `firstname`, `address`, `city`, `state`, `zipcode`, `phoneNumber`, `customerNumber`, `joinMailingList`
class CustomerData : public PersonData
{
    // TO DO
private:
    int customerNumber; // essentially a customer ID number
    bool mailingList;

public:
    CustomerData() : PersonData()
    {
    }
    CustomerData(string lastname, string firstname, string address, string city, string state,
                 string zipcode, string phoneNumber, int customerNumber, bool joinMailingList)
    {
        setLastName(lastname);
        setFirstName(firstname);
        setAddress(address);
        setCity(city);
        setState(state);
        setZip(zipcode);
        setPhone(phoneNumber);
        setCustomerNumber(customerNumber);
        setMailingListStatus(joinMailingList);
    }
    void setMailingListStatus(bool choice)
    {
        if (choice == true)
            mailingList = true;
        else
            mailingList = false;
    }
    bool getMailingListStatus()
    {
        return mailingList;
    }
    void setCustomerNumber(int num)
    {
        customerNumber = num;
    }
    int getCustomerNumber()
    {
        return customerNumber;
    }
};

void fixInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void fix_cin()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    bool mailingListYN = false;
    char list;
    int number;
    string lname, fname, address, city, state, zip, phone;

    int numCustomers = 0;
    vector<shared_ptr<CustomerData>> customersArr; // vector of people, in this case customers (for loop)
    int customerIDnum = 100000000;

    cout << "How many customers will you be entering information for? ";
    cin >> numCustomers;
    while (!cin || numCustomers < 0)
    {
        fixInput();
        cout << "\n***Invalid entry***\n(Number of customers should be an integer greater than zero.)\n"
             << "How many customers will you be entering info for?\n";
        cin >> numCustomers;
    }
    fix_cin();
    char confirmation = 'Y';

    // TO DO
    for (int i = 0; i < numCustomers; i++)
    {
        customerIDnum = customerIDnum + i;
        if (i > 0)
        {
            cout << "------------------ Next Customer... ------------------\n";
            cout << "Customer #" << customerIDnum << ": \n";
        }

        fix_cin();
        // 1. User enters customer information: lname, fname, address, city, state, zip, phone
        cout << "First Name: ";
        getline(cin, fname);

        cout << "Last Name: ";
        getline(cin, lname);

        cout << "Address: ";
        getline(cin, address);

        cout << "City: ";
        getline(cin, city);

        cout << "State: ";
        getline(cin, state);

        cout << "Zip code: ";
        getline(cin, zip);

        cout << "Phone Number: ";
        getline(cin, phone);

        // 2. Ask if the customer is on the mailing list, if 'Y',
        //    set the mailing list to true (1), else set it to false (0)
        cout << "Would you like to be on the mailing list? (Y/N): ";
        cin >> list;

        while (!cin || toupper(list) != 'Y' && toupper(list) != 'N')
        {
            fixInput();
            cout << "Invalid entry. Type Y or N.\n";
            cin >> list;
        }

        if (toupper(list) == 'Y')
            mailingListYN = true;
        else
            mailingListYN = false;

        fix_cin();
        customersArr.push_back(make_shared<CustomerData>(lname, fname, address, city, state, zip, phone,
                                                         customerIDnum, mailingListYN));

        cout << "\n\nSummary of your information:\n"
             << "\n";
        cout << customersArr[i]->getLastName() << ", " << customersArr[i]->getFirstName() << "\n"
             << "Customer ID #" << customerIDnum << "\n"
             << "\n";

        cout << "Phone: " << customersArr[i]->getPhone() << "\n";

        cout << "Address: " << customersArr[i]->getAddress() << ", " << customersArr[i]->getCity()
             << ", " << customersArr[i]->getState() << "  " << customersArr[i]->getZip() << "\n"
             << "\n";

        cout << "Opted into mailing list: ";
        if (customersArr[i]->getMailingListStatus() == true)
            cout << "Yes";
        else
            cout << "No";

        cout << "\n\n";
        system("pause");
        cout << "\n";
    }

    return 0;
}