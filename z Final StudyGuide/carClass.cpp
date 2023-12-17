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

//2.)
class Car //WORK ON THIS ONE
{
private:
    string make,
           model;
    int year;
    double speed;

public:
    void setYear(int year)
    {
        this-> year = year;
    }
    void setMake(string make)
    {
        this-> make = make;
    }
    void setModel(string model)
    {
        this-> model = model;
    }
    void setSpeed(double speed)
    {
        this-> speed = speed;
    }

    int getYear()
    {
        return year;
    }
    string getMake()
    {
        return make;
    }
    string getModel()
    {
        return model;
    }
    double getSpeed()
    {
        return speed;
    }

    void accel()
    {
        speed += 5;
    }
    void brake()
    {
        speed += -5;
        if (speed < 0)
            speed = 0;
    }
};


int main()
{
    Car info;

    string make, model;
    int year;
    double speed;

    cout << "Enter the year of your car: "; cin >> year;
    cout << "Enter the make of your car:  "; cin >> make;
    cout << "Enter the model of your car: "; cin >> model;
    cout << "Enter the current speed of your car (in mph): "; cin >> speed;

    info.setMake(make);
    info.setModel(model);
    info.setYear(year);
    info.setSpeed(speed);

    cout << "Information about my car: \n";
    cout << "Make:  " << info.getMake() << "\n";
    cout << "Model: " << info.getModel() << "\n";
    cout << "Year:  " << info.getYear() << "\n";
    cout << "Speed: " << info.getSpeed() << endl;

    cout << "Accelerating 3 times, speed now ";
    info.accel();
    info.accel();
    info.accel();
    cout << info.getSpeed() << " mph." << endl;

    cout << "Braking hard now, factor of 5. Speed now ";
    info.brake();
    info.brake();
    info.brake();
    info.brake();
    info.brake(); //5
    cout << info.getSpeed() << " mph." << endl;

}