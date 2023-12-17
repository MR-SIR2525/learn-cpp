/**************************************************
 * Student name:
 * Program name:
 * Description: Determine if a number entered has 
 * a perfect squre root and display the square root. 
 * Or it displays the number does not have a square root
 * 
 * ************************************************/

#include <iostream>
using namespace std;

int mySqrt(int);

int main()
{
  int number;
  int cont;
  cout << "In this program I will determine if the number you enter"
       << " has a perfect square root." << endl;

  do
  {
    int root;
    cout << "Enter an integer: ";
    cin >> number;
    
    // Try to find its square root and catch the thrown exception if
    // the number has none
    try
    {
      root = mySqrt(number);
      cout << "The square root is " << root << endl;
    }
    catch (int exceptionNum)
    {
      ////
      root = -1;
      cout << "Negative numbers do not have perfect square roots." << endl;
      
    }

      /////moved to inside the try block.
      // if (root == -1)
      //   ////cout << number << " does not have a perfect square root." << endl;
      //   continue;
      // else
      // ////  cout << "The square root is " << root << endl;

      cout << endl << endl;
      cout << "Would you like to check another number? " << endl;
      cout << "Enter 0 for no or 1 for yes: " << endl;
      cin >> cont;
      cout << endl;
    }
    while (cont == 1);

    return 0;
  }

  /************************************************
 *             mySqrt                            *
 *  Computes the integer square root of          *
 *  its integer parameter.                       *
 ************************************************/
int mySqrt(int number)
{
  if (number < 0)
  {
    throw(-1);
  }
  //return -1;

  // Check all integers less or equal to number to see if one of
  // is a square root
  for (int r = 0; r * r <= number; r++)
  {
    if (r * r == number)
      return r;
  }

  return -1; //no perfect square root
}
