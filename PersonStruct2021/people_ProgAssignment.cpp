/******************************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Person Structs and Pointers
 * Program description: Sorts by pointers an array of pointers that point to an array of Person structs
 * Date: 3/7/2021
*******************************************************************************************************/ 
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
void reverseSortByAge_pointers(Person *[], Person [], int);
void sortByPointers(Person *ptrData[], Person data[], int size);
void swap(string &, string &);
void getPersonData(Person [], istream &, int);
void displayPersonData(Person [], int);
void displayPersonDataIndirect(Person* [], int);
string upperCaseName(const string);
//void reverseDisplay(Person* [], int);
void reverseSort(Person *[], int);

/************************ int main ************************/
int main()
{
    const int SIZE = 10;
    Person data[SIZE];
    Person *ptrdata[SIZE];
	string elStringo;	//user types filename into this string
	int count = 0;		//for the do while loop

    //Get data from file
	ifstream inFile; //("peopledata.txt");
	cout <<     "********************************************************************************************\n"
		 << 	"*************************** People Data Arrays - Pointer Edition ***************************\n"
		 <<		"********************************************************************************************\n";
	do
	{
		cout << "Enter the file name you'd like to search for. If it's not in the same folder as this program,\n"
			 << "include the full path:  -->";
		getline(cin, elStringo);
    	inFile.open(elStringo.c_str()); //found from Google search...

		if (!inFile)
		{
			cout << "File not found! " << endl;	
			if (count > 2)
				cout << "Hint:  \"peopledata.txt\"\n";	
		}

	} while(!inFile);
	cout << "\n";
	getPersonData(data, inFile, SIZE);

    //Set the parallel array of pointers
	for (int k=0; k < SIZE; k++)
	{
		ptrdata[k] = &data[k];
		//*(ptrdata+k) = (data+k);
	}	

	// Display the array
	cout << "Here is the array of people: " << endl;
	displayPersonData(data, SIZE);

    //Sorting by pointers, ascending ***************************
	sortByPointers(ptrdata, data, SIZE);
	cout << "\nArray sorted. ";

	// Display by pointers
	cout << "Displaying indirectly through pointers: " << endl;
	displayPersonDataIndirect(ptrdata, SIZE);

	//Display array in reverse order
	cout << "\nDisplaying array in reverse order: \n";
	reverseSort(ptrdata, SIZE);
	displayPersonDataIndirect(ptrdata, SIZE);
	cout << "\n";
	
	cout << "Now, the array sorted in reverse order by age (old to young):\n"; 
	reverseSortByAge_pointers(ptrdata, data, SIZE);
	displayPersonDataIndirect(ptrdata, SIZE);


	cout << "\n\nEnd of Program. Goodbye.\n";
    return 0;
} //end of main

/***********************************************************************************************
*                                         sortByPointers                                       *
* Given a parallel array of pointers to Person objects in an array, sort the array of pointers *
* so that the Person objects are pointed to in ascending alphabetic order of names             *
***********************************************************************************************/
void reverseSortByAge_pointers(Person *ptrData[], Person data[], int size)
{
	int maxIndex;

	for (int k = 0; k < (size-1); k++)
	{
		maxIndex = k; 	

		for(int i = (k+1); i < size; i++)
		{
			if ((ptrData[i]->age) > (ptrData[maxIndex]->age))
			{
				maxIndex = i;  
				//cout << i << "i maxIndex = " << maxIndex << endl; //debugging
			}
        }
		swap(ptrData[maxIndex], ptrData[k]);
	}
}
//normal sorting in ascending 
void sortByPointers(Person *ptrData[], Person data[], int size) 
{
	int minIndex;

	for (int k = 0; k < (size-1); k++)
	{
		minIndex = k; 	
		//cout << k << "k minIndex = " << minIndex << endl; //debugging

		for(int i = (k+1); i < size; i++)
		{
			//if (upperCaseName(ptrData[i]->name) < upperCaseName(ptrData[minIndex]->name))
			if ((ptrData[i]->name) < (ptrData[minIndex]->name))
			{
				minIndex = i;  
				//cout << i << "i minIndex = " << minIndex << endl; //debugging
			}
        }
		swap(ptrData[minIndex], ptrData[k]);
	}
}
/**********************************************************
 *                         swap                           *
 * Swaps the contents of int variables a and b in memory. *
 *********************************************************/
void swap (string &a, string &b)
{   
   string temp = a;
   a = b;
   b = temp;
}

/******************************************************
 *                     getPersonData                  *
 * Reads a file containing the name and age of people *
 * ***************************************************/
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
void displayPersonData(Person personData[], int size)
{
	for (int index = 0; index < size; index++)
	{
		cout << personData[index].name << " "
			 << personData[index].age << "  \n";	
	} 
	
}

/*****************************************************
 *           displayPersonDataIndirect               *
 * Displays person data using an array of pointers   *
 *****************************************************/
void displayPersonDataIndirect(Person *pData[], int size)
{
	for (int i=0; i < size; i++)
	{
		cout << pData[i]->name << " ";
		cout << pData[i]->age << " \n";
	}
}

/*************************************************************
 *              reverse function for exercise 4              *
 * Reverses the order of the elements of given pointer array *
 * to display them										     *
 ************************************************************/
/*
void reverseDisplay(Person* ptrPeople[], int size)
{         //WRITE YOUR CODE HERE
    for (int i=(size-1); i >= 0; i--)
    {
        cout << ptrPeople[i]->name << " "
             << ptrPeople[i]->age << endl;
    }
}	*/
/********************* sort in reverse **************************/
void reverseSort(Person *ptrPeople[], int size)
{
   int up = 0;
   int down = size-1;

   for (up = 0; up < down; up++, down--)
   {
      swap(ptrPeople[up], ptrPeople[down]);
   }
}

/*************************************************************
*                       upperCaseName                        *
*    Returns an uppercased copy of the string passed in      *
*************************************************************/
string upperCaseName(const string stringIn)
{
    string s = stringIn; //Local copy of stringIn we'll uppercase
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}