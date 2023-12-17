// This program demonstrates a pointer to const parameter  
#include <iostream>
using namespace std;

void displayValues(const int *numbers, int size);
void displayValues2(int *const numbers, int size);

int main()
{
   // Array sizes
   const int SIZE = 6;

   // Define an array of const ints
   const int array1[SIZE] = { 1, 2, 3, 4, 5, 6 };

   // Define an array of non-const ints
   int array2[SIZE] = { 2, 4, 6, 8, 10, 12 };

   // Display the contents of the const array
   displayValues(array1, SIZE);
   //displayValues2(array1, SIZE);
   
   // Display the contents of the non-const array
   displayValues(array2, SIZE);
   displayValues2(array2, SIZE);
   return 0;
}

//***************************************************
// The displayValues function uses a pointer        *  
// parameter to display the contents of an array.   *
//***************************************************

void displayValues(const int *numbers, int size) //pointer that points to a constant
{
   // Display all the values
   for (int count = 0; count < size; count++)
   {
      cout << *(numbers + count) << " ";
   }
   cout << endl;
}

void displayValues2(int *const numbers, int size) //const pointer 
{
   *(numbers + 0) = 111;
   // Display all the values
   for (int count = 0; count < size; count++)
   {
      cout << *(numbers + count) << " ";
   }
   cout << endl;
}