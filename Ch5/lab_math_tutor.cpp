#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    unsigned seed;

    const int MIN_VALUE = 10;
    const int MAX_VALUE = 50;

    int num1, num2;         //two random numbers between 10 and 50
    int guess, sum;         //the guess and the sum of two numbers

    seed = time(0);
    srand (seed);
    
    cout << "Welcome to the Addition Practice Game!\n";
    cout << "In this game, I will display two numbers and you are to guess\n"
         << "what is the total after you add these numbers!\n"
         << "Let's begin!\n\n";
    
    char again = 'Y';
    while (again == 'Y' || again == 'y')
    {
    num1 = (rand() % (MAX_VALUE-MIN_VALUE+1)) + MIN_VALUE;
    num2 = (rand() % (MAX_VALUE-MIN_VALUE+1)) + MIN_VALUE;    
    cout << setw(6) << num1 << endl
         << "+" << setw(5) << num2 << endl
         << setw(6) << "------" << endl;
    cout << "   ";
    cin >> guess;

    sum = num1 + num2;
    if (guess == sum)
    {
        cout << "CORRECT!" << endl;
    }
    else
    {
        cout << "WRONG ANSWER!" << endl;
    }
    
    cout << "Would you like to try again with different numbers?\n(Y or N) ";
    cin >> again;
    }//end of while loop block
 
    return 0;
}