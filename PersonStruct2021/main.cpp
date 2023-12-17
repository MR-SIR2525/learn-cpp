/******************************************************************************
 * Student name:
 * Program Assignment description:
 * Date:
 ******************************************************************************/

#include <fstream>
#include "Person.h"

int main()
{
	const int NUMBER = 10;
	// TODO: Define an array to hold data for 10 people and a parallel array of
	// pointers.


	// Get data
	ifstream inFile("peopledata.txt");
	if (!inFile)
	{
		cout << "Enter data for 10 people as prompted:" << endl;
		getPersonData(people, NUMBER);
	}
	else
	{
		getPersonData(people, inFile, NUMBER);
	}
	// TODO: Set the parallel array of pointers
	//Each element of the array of pointers will have the
	//address of each element of the array of people


	// Sort by pointers, ascending
	sortByPointers(pPerson, people, NUMBER);

	// Display the array
	cout << "Here is the array of people: " << endl;
	displayPersonData(people, NUMBER);

	cout << endl;
	// Display by pointers
	cout << "Display sorted person array indirectly through pointers: " << endl;
	displayPersonDataIndirect(pPerson, NUMBER);

	cout << endl;
	//TODO: display the array of people sorted in descending order

    return 0;
}

