#include <iostream>
using namespace std;
/*
    cout << "Age: " << &age << endl;
    cout << "GPA: " << &gpa << endl;
    cout << "Name: " <<&name << endl;
*/

int main()
{
    int age = 19;
    int *pAge = &age;
    double gpa = 4.0;
    double *pGpa = &gpa;
    string name = "Mike";
    string *PName = &name;

    cout << pAge << endl;
    cout << *pAge << endl;

    return 0;
}
