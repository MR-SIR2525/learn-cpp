#include <iostream>
#include <iomanip>
using namespace std;

//Write your function prototype here
void convert(double *measurement);

int main()
{
    double measurement;

    cout << "Enter a length in inches, and I will convert it to centimeters: ";
    cin >> measurement;

    convert(&measurement);

    cout << setprecision(4);
    cout << fixed << showpoint;
    cout << "Value in cemtimeters: " << measurement << endl;

    return 0;
}

void convert(double *measurement)
{
   *measurement = *measurement *2.54;
}
