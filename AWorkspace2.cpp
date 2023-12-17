/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name:
 * Program description:
 * Date:
 *************************************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

void showMe(int arg) // #5 (checkpoint 14.3 pg 935)
{
    if (arg < 10)
    {
        showMe(++arg);
    }
    else
        cout << arg << endl;
}

void getnumber(int &input) // #4
{
    cout << "Enter an integer number: ";
    cin >> input;
}

template <class T>
T printArray(T myArray[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << myArray[i];
    }
}

template <class T>
void output(vector<T> v)
{
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

template <class T>
T rotateLeft(vector<T> &v)
{
    T temp = v[0];
    for (int i = 0; i < v.size(); i++)
    {
        v[i - 1] = v[i];
    }
    v[v.size - 1] = temp;
}

int main()
{
    string str[] = {"C++", "SQL", "Python", "Java", "JavaScript"};
    int len = sizeof(str) / sizeof(str[0]);

    cout << len << "\n";

    int oneNum;
    getnumber(&oneNum);
    cout << oneNum << "\n";

    int num = 0;
    showMe(num);

    return 0;
}
