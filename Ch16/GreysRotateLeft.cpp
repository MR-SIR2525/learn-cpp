/*****************************************************************************
 * Student name: Grey Chapman
 * Program name: rotateLeftAssignment.cpp
 * Description: 
 * Date: 4-23-21
 * ***************************************************************************/
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

template <typename T>
void rotateLeft(vector <T>& v)
{
    int temp = v[0];
    int size = v.size();

    for (int k = 1; k < size; k++)
    {
        v[k-1] = v[k];    
    }

    v[size-1] = temp;    
}

template <typename T>
void output(vector <T> v)
{
    for (int k = 0; k < v.size(); k++) 
    {
        cout << v[k] << "  " ;   
    }
}

int main() 
{
    vector <int> vInts;
    vector <string> vStrings = {"Charm", "Strange", "Up", "Down"};
    vector <char> vChars = {'c', 's', 'u', 'd'};

    //create a vector of some values
    for (int k = 1; k < 5; k++)
    {
        vInts.push_back(2*k-1);
    }

    //display the contents of the vector and rotate
    for (int k = 0; k < vInts.size(); k++)
    {
        if (k == 0)
        {
            cout << "Original int vector: ";
        }
        else
        {
            cout << "Rotation " << k << ":      ";
        }        
        output(vInts);        
        cout << endl;
        rotateLeft(vInts);
    }
    
    cout << endl;    
    
    return 0;
}

