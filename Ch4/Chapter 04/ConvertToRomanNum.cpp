/********************************************************************************
 * Student name: Andrew Blythe
 * Program name: Numbers to Roman Numerals
 * Program description: Program converts numbers 1 through 10 to Roman Numerals
 * Date: September 30, 2020
*********************************************************************************/ 
#include <iostream>
using namespace std;

void conversionOfJustice(int); 

int main()
{
    int num;           //Stores number entered by user
    string RomanNum;   //Stores the resultant Roman Numeral
    cout << "Enter a number (1 through 10) to convert into Roman Numerals.\n";
    cin >> num;
   
    conversionOfJustice(num);
    
    return 0;
}

//Function that converts numbers to Roman Numerals
void conversionOfJustice(int n)
{
    string RomanNumeral;
    if (n < 1 || n > 10)    //validation step
        cout << "\nYou didn't enter a number between 1 and 10.\n\n";
    else if (n >= 1 && n <=10)
    {   
        if (n == 1)
            RomanNumeral = "I";
        else if (n == 2)
            RomanNumeral = "II";
        else if (n == 3)
            RomanNumeral = "III";
        else if (n == 4)
            RomanNumeral = "IV";
        else if (n == 5)
            RomanNumeral = "V";
        else if (n == 6)
            RomanNumeral = "VI";
        else if (n == 7)
            RomanNumeral = "VII";
        else if (n == 8)
            RomanNumeral = "VIII";
        else if (n == 9)
            RomanNumeral = "IX";
        else if (n == 10)
            RomanNumeral = "X";

     cout << n << " in Roman Numerals is: " << RomanNumeral << ". \n\n";
    }
    else
    {
        RomanNumeral = "Invalid";
        cout << "\nYou somehow broke the program.\n";
    }   
   
}