// This program demonstrates a simple recursive function.
#include <iostream>
using namespace std;

void countdown (int);

int main()
{
    cout << "Starting countdown... " << endl;
    countdown(10);

    cout << "\nBye bye Elon Musk. " << endl;
    return 0;
}

void countdown(int num)
{
    if (num == 0)
        cout << "Blastoff! " << endl;
    else
    {
        cout << num << ". . .  ";
        countdown(num-1); //RESCURSIVE CALL
    }
}
