// This program uses the selection sort algorithm
// to sort an array in ascending order.
#include <iostream>
#include <string>
using namespace std;

// Function prototypes
void selectionSort(string [], int);
void showArray(const string [], int);
string upperCaseWord (const string);

int main()
{
	const int SIZE = 6;

	// Array of unsorted values
	string values[SIZE] = {"Eggies", "Milk", "White Bread", "Cheese", "cereal", "Yogurt"};

	// Display the values
	cout << "The unsorted values are\n";
	showArray(values, SIZE);

	// Sort the array
	selectionSort(values, SIZE);

	// Display the values again
	cout << "\nThe sorted values are\n";
	showArray(values, SIZE);
	return 0;
}

/**************************************************************
 *                        selectionSort                       *
 * This function performs an ascending-order selection sort   *
 * on array. The parameter size holds the number of elements  *
 * in the array.                                              *
 **************************************************************/
void selectionSort(string array[], int size)
{
	int startScan, minIndex;
	string minValue;

	for (startScan = 0; startScan < (size - 1); startScan++)
	{
		minIndex = startScan;
		minValue = array[startScan];
		for(int index = startScan + 1; index < size; index++)
		{
			if (upperCaseWord(array[index]) > upperCaseWord(minValue))
			{
				minValue = array[index];
				minIndex = index;
			}
      }
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}

/*************************************************************
 *                        showArray                          *
 * This function displays the contents of array. The         *
 * parameter size holds the number of elements in the array. *
 *************************************************************/
void showArray(const string array[], int size)
{
	for (int count = 0; count < size; count++)
		cout << array[count] << ", ";
	cout << endl;
}
int i = 1;
while (!data_store.eof()) {
    std::getline(data_store, line);
    std::cout << ++i << ": " << line << std::endl;
}
/******************************************
 * -------- upperCaseWord function -------*
 * Converts a word to uppercase...        *
 * It is used in the selectionSort function
 *****************************************/
string upperCaseWord (const string stringW)
{
    string s = stringW;
    for (unsigned pos = 0; pos < s.length(); pos++)
        s[pos] = toupper(s[pos]);
    return s;
}


