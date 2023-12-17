/*******************************************
 * Student name: Tanner Housewright
 *
 *
 * *****************************************/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Person
{
	string name;
	int age;
};

// Function prototypes
void sortByPointers(Person *[], Person[], int);
void swap(string &, string &);
void getPersonData(Person[], istream &, int);
void displayPersonData(Person[], int);
void displayPersonDataIndirect(Person *[], int);
void reverseName(Person *[], int);
void reverseAge(Person *[], int);
void sortByPointersByAge(Person *[], Person[], int);

int main()
{
	const int SIZE = 10;
	Person data[SIZE];
	Person *pdata[SIZE];

	// Get data
	ifstream inFile("peopledata.txt");
	if (!inFile)
	{
		cout << "File does not exist! Run the code again." << endl;
	}
	else
	{
		getPersonData(data, inFile, SIZE);
	}

	// Set the parallel array of pointers
	for (int k = 0; k < SIZE; k++)
	{
		pdata[k] = &data[k];
	}

	// Display the array
	cout << "Here is the array of people: " << endl;
	displayPersonData(data, SIZE);

	// Sort by pointers, ascending
	sortByPointers(pdata, data, SIZE);

	// Display the array
	cout << "\nHere is the array of people sorted by pointers: " << endl;
	displayPersonData(data, SIZE);

	// Display by pointers
	cout << "\nDisplay indirectly through pointers: " << endl;
	displayPersonDataIndirect(pdata, SIZE);

	// Display array in reverse order
	reverseName(pdata, SIZE);
	cout << "\nDisplay array in reverse order by name: " << endl;
	displayPersonData(data, SIZE);

	// sort by pointers in age
	sortByPointersByAge(pdata, data, SIZE);
	cout << "\nDispaly the array of people sorted by pointers by age: " << endl;
	displayPersonData(data, SIZE);

	// Display array in reverse order by name
	reverseAge(pdata, SIZE);
	cout << "\nDisplay the in reverse order by age: " << endl;
	displayPersonData(data, SIZE);

	return 0;
}

//****************************************************
//             sortByPointers                        *
// Given a parallel array of pointers to Person      *
// objects in an array, sort the array of pointers   *
// so that the Person objects are pointed to in      *
// ascending alphabetic order of names               *
//****************************************************
void sortByPointers(Person *pData[], Person data[], int size)
{
	int minPos; // Position of pointer to minimum value in a section of the array.

	for (int k = 0; k < (size - 1); k++)
	{

		// The kth iteration finds the pointer to the person with the
		// least name from among pData[k..NUMBER-1] and puts that pointer at
		// pData[k]
		minPos = k; // k is assumed to be the position of the minimum
					// Is there a position in k+1 .. NUMBER - 1
					// with a name less than that at k?
		for (int i = k + 1; i < size; i++)
		{
			if (pData[i]->name < pData[minPos]->name)
			{
				minPos = i;
			}
		}

		// Swap the pointer at minPos with the pointer at k
		// to make pData[k] point to the person with the least name
		// in k..NUMBER -1
		swap(*pData[k], *pData[minPos]);
		// to sort age and name using pointer add an '*' to the begining of the pointer
		// and then treat it like an array
	}
}

void sortByPointersByAge(Person *pData[], Person data[], int size)
{
	int minPos; // Position of pointer to minimum value in a section of the array.

	for (int k = 0; k < (size - 1); k++)
	{

		// The kth iteration finds the pointer to the person with the
		// least name from among pData[k..NUMBER-1] and puts that pointer at
		// pData[k]
		minPos = k; // k is assumed to be the position of the minimum
					// Is there a position in k+1 .. NUMBER - 1
					// with a name less than that at k?
		for (int i = k + 1; i < size; i++)
		{
			if (pData[i]->age < pData[minPos]->age)
			{
				minPos = i;
			}
		}

		// Swap the pointer at minPos with the pointer at k
		// to make pData[k] point to the person with the least name
		// in k..NUMBER -1
		swap(*pData[k], *pData[minPos]);
		// to sort age and name using pointer add an '*' to the begining of the pointer
		// and then treat it like an array
	}
}

/****************************************
 *                 swap                 *
 * This function swaps the contents of  *
 * int variables a and b in memory.     *
 ****************************************/
void swap(string &a, string &b)
{
	string temp = a;
	a = b;
	b = temp;
}

/************************************************
 *                 getPersonData                *
 * This fuction read a file containing the name *
 * and age of people                            *
 * **********************************************/
void getPersonData(Person data[], istream &in, int size)
{
	for (int k = 0; k < size; k++)
	{
		getline(in, data[k].name);
		in >> data[k].age;
		in.ignore();
	}
}

/***************************************************
 *              displayPersonData                  *
 * Displays data for size people                   *
 ***************************************************/
void displayPersonData(Person data[], int size)
{
	// cout<<"List done through array\n";

	for (int k = 0; k < size; k++)
	{
		cout << "Name of person " << k + 1 << ": " << data[k].name << " ";
		cout << " Age: " << data[k].age << endl;
		;
	}
}

/*****************************************************
 *           displayPersonDataIndirect               *
 * Displays person data through an array of pointers *
 *****************************************************/
void displayPersonDataIndirect(Person *pData[], int size)
{
	// cout<<"List done through pointer.\n";

	for (int k = 0; k < size; k++)
	{
		cout << "Name of person " << k + 1 << ": " << (pData[k])->name << " ";
		cout << "Age: " << (pData[k])->age << endl;
	}
}

/***********************************************
 * reverse function for exercise 4             *
 * Reverses the order of the elements of the   *
 * given pointer array.                        *
 ***********************************************/
void reverseName(Person *pData[], int size)
{
	int mini = 0;		  // start of the array
	int maxie = size - 1; // end of the array

	while (mini < maxie)
	{
		swap(*pData[mini], *pData[maxie]);
		mini++;
		maxie--;
	}
}

void reverseAge(Person *pData[], int size)
{
	int mine = 0;
	int maxe = size - 1;

	while (mine < maxe)
	{
		swap(*pData[mine], *pData[maxe]);
		mine++;
		maxe--;
	}
}