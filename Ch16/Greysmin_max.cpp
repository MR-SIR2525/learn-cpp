/********************************************
 * Student name: Grey Chapman
 * Assignment name: Programming Challenge 3
 * File name: min_maxTemmplates.cpp
 * Description: Write templates for the two functions min and max. 
 * min should accept two arguments and return the value of the argument that is the lesser of the two. 
 * max should accept two arguments and return the value of the argument that is the greater of the two.
 * Date:4-20-21
 ********************************************/

#include <iostream>
using namespace std; 

template <typename T>
T Min(T smallest, T largest)
{
    if(smallest < largest)
    {
        return smallest;
    }

    else
        return largest;
}

template <typename T>
T Max(T smallest, T largest)
{
    if(largest > smallest)
    {
        return largest;
    }

    else
        return smallest;
}

template <typename T>
T minString(T smallestString, T largestString)
{
    if(smallestString > largestString)
    {
        return smallestString;
    }

    else
        return largestString;
}

template <typename T>
T maxString(T smallestString, T largestString)
{
    if(largestString < smallestString)
    {
        return largestString;
    }

    else
        return smallestString;
}

int main()
{
    double num1,
           num2;

    int choice;

    char cont,
         afterChoice;

    string string1,
           string2;

    do
    {
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "Welcome to my program. Please choose one of the following choices below to run a portion of the program." << endl;
        cout << "1 -> Determine Minimum Number" << endl;
        cout << "2 -> Determine Maximum Number" << endl;
        cout << "3 -> Determine Minimum String" << endl;
        cout << "4 -> Determine Maximum String" << endl;
        cout << "0 -> End Program" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

        cin >> choice;

        while(!cin || choice > 4 || choice < 0)
        {
            //cin.clear();  cin.ignore(100, '\n'); //input buffer reset
            cout << "Incorrect entry, please try again." << endl;
            cin >> choice;
        }

        switch(choice)
        {
            case 1:
                cout << "Enter two numbers, seperated by a space, and I will display the SMALLER of the two: ";
                cin >> num1 >> num2;
                /*while(!(cin >> num1 >> num2))
                {
                    cin.clear();  cin.ignore(123, '\n'); //input buffer reset
                    cout << "Incorrect entry. Please enter integer values: ";
                    cin >> num1 >> num2;
                }*/
                cout << "The smaller number is " << Min(num1, num2) << endl;
                break;

            case 2:
                cout << "Enter two numbers, seperated by a space, and I will display the LARGER of the two: ";
                cin >> num1 >> num2;
                cout << "The larger number is " << Max(num1, num2) << endl;
                break;

            case 3:
                cout << "Enter a string: ";
                cin >> string1;
                cout << "Enter another string: ";
                cin >> string2;
                cout << "The SMALLER string between " << "'" << string1 << "'" << " and " << "'" << string2 << "'" << " is " << minString(string1, string2) << endl;
                break;

            case 4: 
                cout << "Enter a string: ";
                cin >> string1;
                cout << "Enter another string: ";
                cin >> string2;
                cout << "The LARGER string between " << "'" << string1 << "'" << " and " << "'" << string2 << "'" << " is " << maxString(string1, string2) << endl;
                break;

            case 0:
                exit(1);
        }

        cout << "Would you like to return to the main menu? Please enter a 'Y' or 'N'." << endl;
        cin >> afterChoice;
        while(toupper(afterChoice) != 'Y' && toupper(afterChoice) != 'N')
        {
            cout << "Invalid entry. Please input Y or N: ";
            cin >> afterChoice;
        }

    } while(choice != 0 && toupper(afterChoice) == 'Y' && toupper(afterChoice) != 'N');

    return 0;
}



/*cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "Welcome to my program. Please choose one of the following choices below to run a portion of the program." << endl;
    cout << "1 -> Minimum Number" << endl;
    cout << "2 -> Maximum Number" << endl;
    cout << "0 -> End Program" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------" << endl;

    cin >> choice;

    while(!cin || answer > 2) //keeps crashing for some reason after two incorrect inputs OR when entering a correct input after an incorrect input, don't know why
    {
        //cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Incorrect entry, please try again." << endl;
        cin >> answer;
    }

    switch(choice)
    {
        case 1:
            cout << "Enter two numbers, seperated by a space, and I will display the SMALLER of the two: ";
            cin >> num1 >> num2;
            cout << "The smaller number is " << Min(num1, num2) << endl;
            break;
    }*/



    /*do
    {
        cout << "Enter two numbers, seperated by a space, and I will display the SMALLER of the two: ";
        cin >> num1 >> num2;
        cout << "The smaller number is " << Min(num1, num2) << endl;

        cout << "Would you like to check for other numbers?" << endl;
        cout << "Enter a 0 for no or a 1 for yes: " << endl;
        cin >> choice;

        if(choice == 0)
        {
            cout << "How about we try with strings!" << endl;
            cout << "Enter a string: ";
            cin >> string1;
            cout << "Enter another string: ";
            cin >> string2;

            cout << "The LARGER string between " << "'" << string1 << "'" << " and " << "'" << string2 << "'" << " is " << minString(string1, string2) << endl;
        }


        if(choice == 'Y' || choice == 'y')
        {
            cout << "Enter two numbers, seperated by a space, and I will display the LARGER of the two: ";
            cin >> num1 >> num2;
            cout << "The smaller number is " << Max(num1, num2) << endl;

            cout << "Would you like to try something else? Enter a 'Y' to continue or an 'N' to end the program." << endl;
            cin >> choice;
        }

        else if(choice == 'N' || choice == 'n')
        {
            cout << "How about we try with strings!" << endl;
            cout << "Enter a string: ";
            cin >> string1;
            cout << "Enter another string: ";
            cin >> string2;

            cout << "The SMALLER string between " << "'" << string1 << "'" << " and " << "'" << string2 << "'" << " is " << minString(string1, string2) << endl;

        }

    }while(choice == 1);*/