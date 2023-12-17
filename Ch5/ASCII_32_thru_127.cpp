/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Workspace & Template C++
 * Program description: 
 * Date: 
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input/output manipulation
#include <cmath>    // maths?
#include <cctype>   //
#include <string>
#include <chrono>   
#include <windows.h>// Needed to display colors and call Sleep
#include <conio.h>  // for getch() and pausing
#include <fstream>  // Needed to use files
using namespace std;

int main()
{
    int myASCII = 32;
    int chCount = 1;    //initial default

    for (; myASCII <= 127; ++myASCII)
    {
        cout << (char)myASCII << " ";
        
        
        if (chCount == 16) 
        {  
            cout << "\n";  
            chCount = 0; //reset
        }
        chCount++;   
    }

    return 0;
}