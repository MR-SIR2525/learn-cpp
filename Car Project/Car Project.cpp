// This is the MAIN where car.h and car.cpp are being used...
#include <iostream>
#include <string>
#include "Car.h"
using namespace std;

/****************************
 * Car constructor function *
 ****************************
Car()
{
   year = y;
   make = m;
   speed = 0;
}                       */

/*******************************
 * Get functions (accessors..?)*
 *******************************/ // I could not get this to work here,
                                  // so I moved it all to "Car.h"
/*
int getYear()
{
    return year;
}

string getMake()
{
    return make;
}

 int getSpeed()
{
    return speed;
}*/
/***************************************
* ---- HERE IS MAIN --------------------               */
int main()
{
    Car myCar(2019, "Tesla", "Model S");

    cout << "My car is a " << myCar.getYear()
         << " " << myCar.getMake() << myCar.getModel() << ".\n\n";

// Acceleration
// *first number is 0, NOT 1
    cout << "\"Vehicle stationary, ready to go.\" \n\n"
         << "Perfect launch, now accelerating... \n";
    for (int accel = 1; accel <= 5; accel++)
    {
        myCar.accelerate();
        cout << "Travelling at " << myCar.getSpeed()
             << " mph. \n";
    }

// De-acceleration
    cout << "\nBraking... \n";
    for (int deaccel = 1; deaccel <= 5; deaccel ++)
    {
        myCar.brake();
        cout << "Current Speed: " << myCar.getSpeed()
             << " mph. \n";
    }
    cout << "\n\"Your vehicle has stopped.\"" << endl;

    return 0;
}
