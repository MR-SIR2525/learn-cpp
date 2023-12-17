// This program demonstrates a simple class with member functions
// defined outside the class declaration.
#include <iostream>
#include <cmath>
using namespace std;

// Circle class declaration
class Circle
{  private:
      double radius;             // This is a member variable.
		
   public:
	  Circle()        // default constructor
	  {
		  radius = 1;
	  }
	  Circle(double r)
	  {
		  radius = r;
	  }

	  /************ or ****************
	    Circle() : radius = 1 {}     // default constructor
		Circle(double r) : radius = r {}
	 */
      void  setRadius(double);   // These are just prototypes 
      double calcArea();         // for the member functions.
	  ~Circle();  //destructor
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
 *                        Circle::calcArea                        *
 * This function calculates and returns the Circle object's area. *
 * It does not need any parameters because it already has access  *
 * to the member variable radius.                                 *
 ******************************************************************/
double Circle::calcArea()
{	
	return 3.14 * pow(radius, 2); 
}

void printCircle(Circle c);
Circle createCircle();

/******************************************************************
 *                            main                                *
 ******************************************************************/
int main()
{
	Circle circle1 = createCircle(),          // Define 2 Circle objects 
		   circle2 = createCircle(),
		//   clock(5); //this invokes the overloaded constructor
		   clock = createCircle();

	circle1.setRadius(0.5);    // This sets circle1's radius to 1.0
	circle2.setRadius(2.5);  // This sets circle2's radius to 2.5

	// Get and display each circle's area
	printCircle(circle1);
	printCircle(circle2);
	printCircle(clock);
	
	return 0;
}

void printCircle(Circle c)
{
	cout << "The area of this circle is " << c.calcArea() << endl;
}

Circle createCircle()
{
	Circle c;
	double r;

	cout << "Enter the radius of the circle: ";
	cin >> r;

	c.setRadius(r);

}