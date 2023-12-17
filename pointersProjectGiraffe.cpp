#include <iostream>
using namespace std;
/*
    cout << "Age: " << &age << "\n";
    cout << "GPA: " << &gpa << "\n";
    cout << "Name: " <<&name << "\n";
*/

int main()
{
    int age = 19;
    int *pAge = &age;
    double gpa = 4.0;
    double *pGpa = &gpa;
    string name = "Mike";
    string *PName = &name;

    cout << pAge << "\n";
    cout << *pAge << "\n";

    return 0;
}
