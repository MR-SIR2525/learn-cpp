#include <iostream>
using namespace std;

int foo(int, int);

const int SIZE = 20;

int main()
{
    cout << "Enter 2 integers ";
    int x, y;
    cin >> x >> y;
    cout << "The result is " << foo(x, y) << endl;

    return 0;
}

int foo(int x, int y)
{
    //base case
    if (x == 0)
        return 0;

    //If x is not 0, then handle negative and positive values separately
    if(x > 0)
        return y + foo(x-1, y);
    else
        return -foo(-x, y);
}
// This is multiplication by addition and grouping
