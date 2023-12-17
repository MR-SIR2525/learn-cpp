// This program shows variable initialization.
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string month = "February";    // month is initialized to "February"  
	int year,                 // year is not initialized
	    days  = 29;           // days is initialized to 29
	auto yearExample = 777;   //"auto" data type finds the correct data type once the variable or whatever is initialized
	
	
	year = 1776;             // Now year is assigned a value

	cout << "In "   << year << " " << month
		 << " had " << days << " days.\n";

	cout << "abc\ndef\tghi\njkl" << endl << endl << "mno\npqr\n";

	return 0;
}
