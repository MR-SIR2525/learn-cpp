#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    //Solution using floats
    int thePurchase = 95;
    float stateSalesTax = .04,
          countySalesTax = .02;

    // Set decimal precision to 2 places after the decimal point. 
    cout << setprecision(2) << fixed << endl;

    cout << "The total state sales tax on a $95 dollar purchase is $";
    cout << thePurchase * stateSalesTax << endl;

    cout << "The total county sales tax on a $95 dollar purchase is $";
    cout << thePurchase * countySalesTax << endl << endl;

    //below is in class version
    cout << "\n\nVersion 2: \n";
    double purchase = 95,
           stateTax = .04,
           countyTax = .02;

    cout << "The total state sales tax on a $95 dollar purchase is $";
    cout << purchase * stateTax << "\n";

    cout << "The total county sales tax on a $95 dollar purchase is $";
    cout << purchase * countyTax << "\n\n";

    return 0;
}