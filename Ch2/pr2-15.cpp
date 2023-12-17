// This program demonstrates the string class.
#include <iostream>
#include <string>	       // Required for the string class
using namespace std;

int main()
{
	string movieTitle;

	movieTitle = "Wheels of Fury";
	cout << "My favorite movie is " << movieTitle << endl;
	
	string name = "Andrew";
	cout << "Hi, my name is " << name << ". " << "It has " << name.size() << " characters." << endl;
	return 0;
}
