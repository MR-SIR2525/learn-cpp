/*******************************************
 * Student name: Grey Chapman
 * 
 * 
 * *****************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std; 

struct Person
{
    string name;
    int age;
};

// Function prototypes
void sortByPointers(Person *[], Person [], int);
void swap(string &, string &);
void getPersonData(Person [], istream &, int);
void displayPersonData(Person [], int);
void displayPersonDataIndirect(Person* [], int);
void reverse(Person* [], int);

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
	cout << "\n";

	//Dispplay the array
	cout << "Here is the array of people sorted by pointers." << endl;
	//displayPersonData(data, SIZE);
	displayPersonDataIndirect(pdata, SIZE);

	// Display by pointers
	cout << "\nDisplay indirectly through pointers: " << endl;
	displayPersonDataIndirect(pdata, SIZE);

	//Display array in reverse order
	reverse(pdata, SIZE);
	cout << "\nDisplay array in reverse order: " << endl;
	//displayPersonData(data, SIZE);
	displayPersonDataIndirect(pdata, SIZE);

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
    int minPos;

    for(int i = 0; i < (size-1); i++)
    {
        minPos = i;

        for(int j = (i + 1); j < size; j++)
        {
            if((pData[i]->name) < (pData[minPos]->name))
            {
                minPos = i;
            }
        }
        
        swap(pData[minPos], pData[i]);

    }
}

/****************************************
 *                 swap                 *
 * This function swaps the contents of  * 
 * int variables a and b in memory.     *
 ****************************************/
void swap (string &a, string &b)
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
void getPersonData(Person data[], istream & in, int size)
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
	//WRITE YOUR CODE HERE
	for(int i = 0; i < size; i++)
	{
		cout << data[i].name << data[i].age << endl;
	}

}

/*****************************************************
 *           displayPersonDataIndirect               *
 * Displays person data through an array of pointers *
 *****************************************************/
void displayPersonDataIndirect(Person* pData[], int size)
{
	//WRITE YOUR CODE HERE
    for (int i = 0; i < size; i++)
    {
    	cout << pData[i]->name << pData[i]->age << endl;
    }
}


/***********************************************
 * reverse function for exercise 4             *
 * Reverses the order of the elements of the   *
 * given pointer array.                        *
 ***********************************************/
void reverse(Person* pData[], int size)
{
	//WRITE YOUR CODE HERE
    for (int i = 0; i < size; i++)
    {
    	pData--;
    }
}




/*void sortByPointers(Person *pData[], Person data[], int size)
{
	int minPos;        //Position of pointer to minimum value in a section of the array.   

	for (int k = 0; k < (size - 1); k++)
	{
		// The kth iteration finds the pointer to the person with the
		// least name from among pData[k..NUMBER-1] and puts that pointer at 
		// pData[k]
		minPos = k;     // k is assumed to be the position of the minimum

		// Is there a position in k+1 .. NUMBER - 1
		// with a name less than that at k? 
		//WRITE YOUR CODE HERE

		// Swap the pointer at minPos with the pointer at k
		// to make pData[k] point to the person with the least name
		// in k..NUMBER -1
		//WRITE YOUR CODE HERE
	}
}*/