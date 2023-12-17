#include <iostream>
using namespace std;

int main()
{
    int x = 10, y = 25;
    cout << x << " " << y << endl;
    cout << &x << " " << y << endl;

    // Declaring a pointer to an int called xPtr
    int* xPtr;  // * is the indirection operator

    xPtr = &x;  // xPtr is a pointer to an integer to an
                // int variable. It holds the address of that
                // int variable, which is "x" in this case.

    //Print the address stored in xPtr
    cout << xPtr << " the value in xPtr\n" << endl;
    //Print the value in xPtr
    cout << *xPtr << " is the value that xPtr is pointing to. \n" << endl;

    xPtr = &y;
    cout << xPtr << " is the value in xPtr." << endl;
    cout << *xPtr << " is the value xPtr is pointing to now. " << endl;

        cout << "\n-------------------------\n";
    int grades[5] = {1, 3, 5, 7, 9};
    cout << "Address of \"grades[0]\" " << grades << "\n";  //address of grades[0]
    cout << "Address of \"grades[1]\" " << (grades+1) << endl; //address of grades[1]

    cout << *grades << endl; //prints the first element of the array
    cout << grades[0] << endl;
    cout << "\n...\n";


    int count;
    cout << &count << endl;
    double *dPtr = nullptr; // nullptr is the default value for a pointer

    // 3 uses of *
    //1. Multiplication
    //2. Dereferencing a pointer
    //3. Indirection
    //4. Definition of a pointer

    int classsize = 24;
    const int * const ptr = &classsize;

    classsize = 30;
    //ptr = grades;
    cout << classsize << endl;


    return 0;
}
