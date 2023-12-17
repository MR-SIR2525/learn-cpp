/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Populations Bar Chart  
 * Program description: Reads population data from a file and then prints out a bar
 *                      graph of the populations every 20 years per 1000 people
 * Date: October 18, 2020
*************************************************************************************************/ 
#include <iostream>
#include <iomanip>  // input output manipulation
#include <math.h>   // for ceil()
#include <windows.h>// Needed to display colors and call Sleep
#include <fstream>  // Needed to use files
using namespace std;


int main()
{
    // Bright Green = 10   Bright Red = 12   Bright Yellow = 14   
	// Get the handle to standard output device (the console)
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    cout << "PRAIRIEVILLE POPULATION GROWTH\n"
         << "(each * represents 1000 people)\n";
    
    //input file stream variable
    ifstream fileToRead;

    //opening the file, fileToRead now associated with "people.txt"
    fileToRead.open("people.txt");

    int population,
        numAsterisks, 
        year = 1900;    //initially the first year
    
    
    if (fileToRead) //if the file opens correctly
    {
        for (year; fileToRead >> population; year += 20)
        {
            if (population >= 0)
            {
                numAsterisks = (ceil(population / 1000)); //calculation & rounding up 

                //cout << " ~~~popValue/1000 no rounding " << population / 1000;    //diagnostic
                //cout << " ~~~numAsterisks: " << numAsterisks;                   //diagnostic
                //cout << " ~~~" << population << endl;                       //diagnostic

                cout << year << " ";
                for (int i = 1; i <= numAsterisks; ++i)
                {
                    cout << "* ";
                }
                cout << endl;
            }
            else   
            {
                cout << "BAD DATA\n";
                break;
            }
        }//end of for loop

        //Close the file
        fileToRead.close();
    }
    else    //file didn't open or couldn't be accessed
    {
        cout << "Error reading the file.\n";
    }

    return 0;
}