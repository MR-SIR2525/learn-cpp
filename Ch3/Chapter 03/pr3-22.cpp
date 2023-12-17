// Three ways to use cin.get() to pause a program.
#include <iostream>
#include <conio.h>     //for "getch()" on the fourth pause
using namespace std;

int main()
{
	char ch;

	cout << "This program has paused. Press Enter to continue.";
	cin.get(ch);
	
	cout << "It has paused a second time. Please press Enter again.";
	ch = cin.get();
	
	cout << "It has paused a third time.  Please press Enter again.";
	cin.get();

	cout << "It has paused a fourth time.  Please press Enter again.";
	getch();  //allows me to do "Press Enter when ready" since "cin" skips over whitespace like ENTER
			  //I found this on Google Sept 2020. **NEEDS #include <conio.h>
			  
	cout << "Thank you! \n";
	return 0;
}
