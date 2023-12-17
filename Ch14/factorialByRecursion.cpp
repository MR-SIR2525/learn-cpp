#include <iostream>
#include <iomanip>  // input/output manipulation
using namespace std;

long long fact(long long);
//void showMe(int);

int main()
{
    int num;

    cout << "Enter a number to find its factorial: "; 
    cin >> num;
    cout << "Factorial:  " << fact(num) << endl;

    //showMe(num);
    return 0;
    
}

long long fact(long long num)
{
    if (num == 1 || num == 0)
    {
        return 1;
    }
    else if (num < 0)
    {
        return 0;
    }
    else 
    {
        return num * fact(num-1);
    }
}

// void showMe(int arg)
// {
//     if (arg < 10)
//         showMe(++arg);
//     else    
//         cout << arg << endl;
// }