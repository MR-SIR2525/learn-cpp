/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: 
 * Program description:  
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

//3.)
void selectionSort(int array[], int size) //sorting of a single array
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }            
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;        
    }
}

void selectionSort(int array[], int array2[], int size) //sorting of parallel arrays
{
    int startScan, minIndex, minIndex2, minValue, minValue2;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
          minIndex = startScan;
          minIndex2 = startScan;
          minValue = array[startScan];
          minValue2 = array2[startScan];
          for(int index = startScan + 1; index < size; index++)
          {
              if (array[index] < minValue)
              {
                 minValue = array[index];
                 minIndex = index;
              }

              if (array2[index] < minValue2)
              {
                 minValue2 = array2[index];
                 minIndex2 = index;
              }
          }
          array[minIndex] = array[startScan];
          array[startScan] = minValue;

          array2[minIndex2] = array2[startScan];
          array2[startScan] = minValue2;
    }
}