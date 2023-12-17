//
#include <iostream>
using namespace std;

int main()
{
    int *count, *arrayptr;
    count = new int;

    cout <<"How many students? ";
    cin >> *count;

    arrayptr = new int[*count];

    for (int i=0; i<*count; i++)
    {
        cout << "Enter score " << i+1 << ": ";
        cin >> arrayptr[i];
    }	


    delete count;
    delete [] arrayptr;

    return 0;    
}