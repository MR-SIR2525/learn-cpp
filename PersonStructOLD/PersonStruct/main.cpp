/******************************************************************************
 * Student name: Andrew Blythe
 * Program Assignment description:
 * Date: 2-12-2020
 ******************************************************************************/
#include <fstream>
#include "Person.h"
#include "Person.cpp"

int main()
{// TODO: Define an array to hold data for 10 people and a parallel array of
 // pointers.
	const int NUMBER = 10; //essentially SIZE 

	Person peopleArr[NUMBER];
	Person *ptrPeople[NUMBER];

	// Get data
	ifstream inFile("peopledata.txt");
	if (!inFile)
	{
		cout << "Enter data for 10 people as prompted:" << endl;
		getPersonData(peopleArr, NUMBER);
	}
	else
	{
		getPersonData(peopleArr, inFile, NUMBER);
	}
    //getPersonData(peopleArr, NUMBER);
	// TODO: Set the parallel array of pointers
	//Each element of the array of pointers will have the
	//address of each element of the array of people
    // for int i=0, if NUMBER, then increment by +1.

    for(int i=0; i < NUMBER; i++)
    {
        *(ptrPeople+i) = (peopleArr+i);
		//ptrPeople[i] = &peopleArr[i];
    }

	// Display the array
	cout << "Here is the array of people: " << endl;
	displayPersonData(peopleArr, NUMBER);

    // Sort by pointers, ascending
    sortByPointers(ptrPeople, peopleArr, NUMBER);

	cout << endl;
	// Display by pointers
	cout << "Displaying sorted person array indirectly with pointers: " << endl;
	displayPersonDataIndirect(ptrPeople, NUMBER);
	cout << endl;

	descendingPersonData(ptrPeople, NUMBER);
	/*
	//TODO: display the array of people sorted in descending order
    cout << "\nNow the names in descending order... " << endl;
    for (int i=(NUMBER-1); i >= 0; i--)
    {
        cout << ptrPeople[i]->name << ", "
             << ptrPeople[i]->age << endl;

    }
    */
    return 0;
}

