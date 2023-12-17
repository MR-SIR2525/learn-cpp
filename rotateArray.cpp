
#include <vector>
#include <iostream>

using namespace std;

void rotateLeft(vector <int>& v);

int main()
{
    vector <int> v;                 //create an integer vector
    for (int k = 1; k < 5; k++)
        v.push_back(2*k);           //add 2 4 6 8 to the vector

    for (int k = 0; k < v.size(); k++)
    {
        cout << k+1 << ": ";                      //display the current line
        for (int j = 0; j < v.size(); j++)
            cout << v[j] << "  " ;               //loop through the vector and displays its contents
        cout << "\n";
        rotateLeft(v);                           //call the rotateLeft function
    }

    return 0;
}

void rotateLeft(vector <int>& v)
{
    int temp = v[0];                //store the first element in the vector in a temporary integer variable
    int size = v.size();            //get the size of the vector
    for (int k = 1; k < size; k++)
        v[k-1] = v[k];              //starting with the second element of the array, swap it with the
                                    //the previous element; repeat for all the elements of the vector
    v[size-1] = temp;               //Store the first element of the vector in last position
}
