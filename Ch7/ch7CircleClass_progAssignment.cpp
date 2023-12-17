/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Circle Class (Ch7 Prog Assignment)
 * Program description:
 * Date: Jan 27, 2021
 *************************************************************************************************/
#include <iostream>
#include <cmath> //needed for pow function
using namespace std;

// Circle class declaration
class Circle
{
private:
    double radius;
    const double pi = 3.14159;

public:
    Circle() // default constructor
    {
        radius = 0.0;
    }
    Circle(double r) // constructor accepts circle radius as argument
    {
        radius = r;
    }

    void setRadius(double);
    double getRadius();
    double getArea();
    double getDiameter();
    double getCircumference();

    ~Circle()
    {
        setRadius(radius);
        getRadius();
        getArea();
        getDiameter();
        getCircumference();
    }
};

/******************************************************************
 *                      Circle::setRadius                         *
 * This function copies the argument passed into the parameter to *
 * the private member variable radius.                            *
 ******************************************************************/
void Circle::setRadius(double r)
{
    radius = r;
}

/******************************************************************
 *                        Circle::getArea                      *
 * This function calculates and returns the Circle object's area. *
 ******************************************************************/
double Circle::getArea()
{
    return pi * pow(radius, 2);
}

/******************************************************************
 *                      Circle::getRadius                         *
 * Returns radius of the circle                                   *
 ******************************************************************/
double Circle::getRadius()
{
    return radius;
}

/******************************************************************
 *                      Circle::getDiameter                       *
 * Calculates and returns diameter of the circle                  *
 ******************************************************************/
double Circle::getDiameter()
{
    return 2 * radius;
}

/******************************************************************
 *                      Circle::getCircumference                  *
 * Calculates and returns circumference of the circle             *
 ******************************************************************/
double Circle::getCircumference()
{
    return 2 * pi * radius;
}

/*************************** int main *****************************
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
void getReport(Circle); // function prototype

int main()
{
    Circle circle1;
    double usrRadius = 0;

    // user input
    cout << "\nThis program demonstrates the Circle class by taking a radius of your choice, creating "
         << "a Circle object, \nand then reporting the circle's area, diameter, and circumference.\n";
    cout << "\nWhat is your desired radius for a this circle? ";
    cin >> usrRadius;

    // user input validation
    while (!cin || usrRadius < 0)
    {
        cin.clear();
        cin.ignore(100, '\n'); // input buffer reset

        cout << "\nWait...  ";
        if (usrRadius < 0)
            cout << "Radius must be a positive value. ";
        else
            cout << "that's not a valid input. ";

        cout << "Try again.\n"
             << "What radius do you desire for the circle? ";
        cin >> usrRadius;
    }

    cout << "Ok.\n\n";

    circle1.setRadius(usrRadius);

    getReport(circle1);

    return 0;
}

/******************************************************************
 *                        void getReport                          *
 * Generates and prints info of circle object                     *
 ******************************************************************/
void getReport(Circle passedCircle)
{
    // Call member functions display circle info
    cout << "Here is the circle's data:\n\n";
    cout << "Circumference:  " << passedCircle.getCircumference() << "\n";
    cout << "         Area:  " << passedCircle.getArea() << "\n";
    cout << "     Diameter:  " << passedCircle.getDiameter() << "\n";
    cout << " Radius given:  " << passedCircle.getRadius() << "\n";
}