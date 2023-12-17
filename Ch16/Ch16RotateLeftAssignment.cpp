/******************************************************************************
* Student Name:  Andrew Blythe
* Program Name: Chapter 16 Rotate Left Assignment
* Program Description: Circulates items in a vector to the left using function templates
* Date: 4/23/21 - fixed 12/16/23
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <class T>
void output(vector<T> v)
{
    for(int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
void rotateLeft(vector<T> &v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << "Rotation " << i << ":  ";
        output(v);
        auto temp = v[0];
        for (int j = 0; j < v.size() - 1; ++j)
        {
            v[j] = v[j + 1];
        }

        v[v.size() - 1] = temp;
    }
}

int main()
{
    vector<int> vInts = {1, 3, 5, 7};
    vector<char> vChars = {'a', 'b', 'c', 'd', 'e'};
    vector<string> vStrings = {"Alpha", "Bravo", "Charlie", "Delta", "Echo"};
    vector<double> vDoubles = {100.1, 100.2, 100.3, 100.4};

    cout << "Note, Rotation 0 is the original vector for all the following:" << endl;
    rotateLeft(vInts); //output function called within rotateLeft ↑↑↑, same for others below
    cout << endl;

    rotateLeft(vChars);
    cout << endl;

    rotateLeft(vStrings);
    cout << endl;

    rotateLeft(vDoubles);
    cout << endl;

    cout << "End of program. Goodbye.";
    return 0;
}
