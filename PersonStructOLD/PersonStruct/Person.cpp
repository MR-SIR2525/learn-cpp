#include "Person.h"
#include <algorithm>      // needed for swap

//Need to complete this file *************************************

//*************************************************
//              getPersonData                     *
//        Reads in data for number people         *
//*************************************************
void getPersonData(Person personData[], int number)
{
    for (int i=0; i < number; i++)
    {
        cout << "Enter first name " << i+1 << ": ";
        cin >> personData[i].name;
        cout << "Now enter age" << i+1 << ": ";
        cin >> personData[i].age;
        cout << "Good." << endl;
    }
}

//*************************************************
//              getPersonDataFromStream           *
//        Reads in data for number people         *
//*************************************************
void getPersonData(Person personData[], istream & in, int number)
{
    for (int i=0; i < number; i++)
    {
        in >> personData[i].name;
        in >> personData[i].age;
    }
}

//**************************************************
//              displayPersonData                  *
// Displays data for number people                 *
//**************************************************
void displayPersonData(Person personData[], int number)
{
    for (int i=0; i < number; i++)
    {
        cout << personData[i].name << " ";
        cout << personData[i].age << " \n";
    }
}
//****************************************************
//           displayPersonDataIndirect               *
// Displays person data through an array of pointers *
//****************************************************
void displayPersonDataIndirect(Person * ptrPeople[], int number)
{
        for (int i=0; i < number; i++)
        {
            cout << ptrPeople[i]->name << " ";
            cout << ptrPeople[i]->age << " \n";
        }
}

/**************************************************
 *         descending display function            *
 *************************************************/
void descendingPersonData(Person *ptrPeople[], int NUMBER)
{
    cout << "\nNow the names in descending order... " << endl;
    for (int i=(NUMBER-1); i >= 0; i--)
    {
        cout << ptrPeople[i]->name << ", "
             << ptrPeople[i]->age << endl;

    }
}
//****************************************************
//             sortByPointers   (selectionSort??)    *
// Given a parallel array of pointers to Person      *
// objects in an array, sort the array of pointers   *
// so that the Person objects are pointed to in      *
// ascending alphabetic order of names               *
//****************************************************
/********************************************************
 *                     bubbleSort
 ********************************************************/
void sortByPointers(Person *ptrArray[], Person personData[], int size)
{
   Person *temp;    //Holds an Inventory object
   bool swap;       //a flag?

   do
   {  
        swap = false;
        for (int count = 0; count < (size - 1); count++)
        {
            if (ptrArray[count]->name > ptrArray[count + 1]->name)
            {
                temp = ptrArray[count];
                ptrArray[count] = ptrArray[count + 1];
                ptrArray[count + 1] = temp;
                swap = true;
            }
        }
   } while (swap);
}// End bubbleSort

/******************************************
 * -------- upperCaseName function -------*
 *****************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; //Local copy of stringIn to uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}

