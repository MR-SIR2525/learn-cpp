//this uses linearSearch
#include <iostream>
 using namespace std;

 int linearSearch (const int[], int, int);

 int main()
 {
     int accounts[] = {5658845, 4520125, 7895122, 8777541, 8451277,
                       1302850, 8080152, 4562555, 5552012, 5050552,
                       7825877, 1250255, 1005231, 6545231, 3852085,
                       7576651, 7881200, 4581002};
    int accNum;
    int asize = sizeof(accounts)/sizeof(accounts[0]);
    cout << "Enter your account number: " << endl;
    cin >> accNum;

    int index = linearSearch(accounts, asize, accNum);
    if (index >= 0)
        cout << "Valid account number." << endl;
    else
        cout << "Invalid account number." << endl;

    return 0;
 }

 int linearSearch (const int acc[], int size, int accNum)
 {
    int index = 0;
    int position = -1;
    bool found = false;

    while (index < size && !found)
    {
        if (acc[index] == accNum)
            found = true;
        position = index;
    }
    return position;
 }
