#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

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
