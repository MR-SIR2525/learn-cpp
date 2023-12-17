/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Workspace & Template C++
 * Program description: 
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
using namespace std;



int main()
{
    const int ISIZE = 5,
              DSIZE = 10;
              
    int tests[ISIZE];
    double volumes[DSIZE];

    double avg = 0;

    /* * * Initializing the contents of the array * * */
    tests[0] = 89;
    tests[1] = 73;
    tests[2] = 91;
    tests[3] = 100;
    tests[4] = 58;

    cout << "Test 1: " << tests[0] << endl; 
    cout << "Test 2: " << tests[1] << endl;
    cout << "Test 3: " << tests[2] << endl;
    cout << "Test 4: " << tests[3] << endl;
    cout << "Test 5: " << tests[4] << endl;
    
    //average of the whole array
    avg =  ((tests[0] + tests[1] + tests[2] + tests[3] + tests[4])/5);
    cout << "Average: " << avg;

    //overriding with user input
    cout << "\nNow to override the array values: \n";
    for (int i=0; i < ISIZE; i++)
    {
        cout << "Enter grade: " << (i+1) << ":  ";
        cin >> tests[i];
    }

    //displaying the array with a for loop
    cout << endl;
    for (int i=0; i < ISIZE; i++)
    {
        cout << "Test " << (i+1) << ":  " << tests[i] << endl;
    }

    return 0;
}