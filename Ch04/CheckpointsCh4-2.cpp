//Chapter 4 Checkpoints beyond example 12
#include <iostream>
#include <cctype>
using namespace std;

int main()
{
	//If else but short
    int age;
    string msg;

    cout << "Enter your age: ";
    cin >> age;

    msg = (age < 16) ? "No DL yet." : "Yay! DL, okay!"; //simple if else statement using ? and :

    cout << "\n" << msg << "\n\n";

    

	return 0;
}
