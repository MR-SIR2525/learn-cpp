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
#include <dos.h>    // for delay    1 second = 1000 milliseconds
#include <conio.h>  // for getch() and pausing
#include <fstream>  // Needed to use files
using namespace std;

//void delay(unsigned int milliseconds); //well idk how this works
enum State {Illinois = 1, Indiana, Michigan, Wisconsin};

int main()
{
    /*****************Writing to File*****************/
    // declare a variable for output file
    ofstream outFile;

    // create and open an output file with a name
    outFile.open("myFile.txt");

    // Use the file
    string name;
    cout << "Enter your name: " << flush;
    getline(cin, name);

    // saving "name" to file now
    outFile << name;
    
    // close the file
    outFile.close();

    cout << "Done. Now go open your file.\n";


    /*****************Reading from File*****************/
    //declare an input file stream variable
    ifstream fileToRead;

    //open the file to read
    fileToRead.open("myFile.txt");

    //Read the file
    string text;

    if (fileToRead)
    {
        while (getline(fileToRead, text))
        {
            cout << "I read: " << text << endl;
        }
    }
    else
    {
        cout << "Error reading the file.\n";
    }
    

    

    //Close the file
    fileToRead.close();



    return 0;
}