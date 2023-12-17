/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Ch16 Min Max Finder
 * Program description: Lab assignment with function templates, determines largest/smallest of inputed datatypes
 * Date: 4-19-21
*************************************************************************************************/ 
#include <iostream>
// #include <chrono>   //sleep function
// #include <thread>   //sleep function
using namespace std;
// using namespace std::this_thread;//sleep function
// using namespace std::chrono;     //sleep function

template <class T>
T min_16(T a, T b) //named with _16 because there's already a min() function in C++
{
    if (a < b)
        return a;
    else
        return b;
}

template <class T>
T max_16(T aa, T bb) //named with _16 because there's already a max() function in C++
{
    if (aa > bb)
        return aa;
    else 
        return bb;
}

int main()
{
    int choice;
    do 
    {
        cout << "Choose one of the following: \n";
        cout << "1.) Determine largest of two integer numbers\n"
             << "2.) Determine smallest of two integer numbers\n"
             << "3.) Compare 2 characters/phrases - return alphabetical largest\n"
             << "4.) Compare 2 characters/phrases - return alphabetical smallest\n"
             << "5.) Determine largest of two decimal-having numbers\n"
             << "6.) Determine smallest of two decimal-having numbers\n"
             << "0.) Quit" << endl;
        cin >> choice;
        while (!cin || !(choice >= 0 && choice <= 6))
        {
            cin.clear();    cin.ignore();
            cout << "Invalid input. Please, 1-6, or 0 to quit." << endl;
            cin >> choice;
        }

        cin.ignore();
        switch(choice)
        {
            
            case 1: //max of 2 ints
            {
                long int num1, num2;
                cout << "Enter two numbers below:" << endl;
                cin >> num1 >> num2;
                while(!cin)
                {
                    cin.clear();    cin.ignore();
                    cout << "Invalid input. Please enter integer numbers only: ";
                    cin >> num1 >> num2;
                }
                
                cout << "Largest is: " << max_16(num1, num2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 2: //min of 2 ints
            {
                long int num1, num2;
                cout << "Enter two numbers below:" << endl;
                cin >> num1 >> num2;
                while(!cin)
                {
                    cin.clear();    cin.ignore();
                    cout << "Invalid input. Please enter integer numbers only: ";
                    cin >> num1 >> num2;
                }
                
                cout << "Smallest is: " << min_16(num1, num2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 3: //max of two strings
            {
                string sss1, sss2;
                cout << "Enter two characters, words, or phrases below:" << endl;
                cout << "First:  ";
                getline(cin, sss1);
                cout << "Second: ";
                getline(cin, sss2);
                
                cout << "Largest is: " << max_16(sss1, sss2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 4: //min of two strings
            {
                string sss1, sss2;
                cout << "Enter two characters, words, or phrases below:" << endl;
                cout << "First:  ";
                getline(cin, sss1);
                cout << "Second: ";
                getline(cin, sss2);
                
                cout << "Smallest is: " << min_16(sss1, sss2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 5: //largest of two doubles
            {
                long double num1, num2;
                cout << "Enter two numbers below:" << endl;
                cin >> num1 >> num2;
                while(!cin)
                {
                    cin.clear();    cin.ignore();
                    cout << "Invalid input. Please enter numbers only: ";
                    cin >> num1 >> num2;
                }
                
                cout << "Largest is: " << max_16(num1, num2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 6: //smallest of two doubles
            {
                long double num1, num2;
                cout << "Enter two numbers below:" << endl;
                cin >> num1 >> num2;
                while(!cin)
                {
                    cin.clear();    cin.ignore();
                    cout << "Invalid input. Please enter numbers only: ";
                    cin >> num1 >> num2;
                }
                
                cout << "Smallest is: " << min_16(num1, num2) << "\n" << endl;
                // sleep_until(system_clock::now() + seconds(1));
                break;
            }
            case 0:
                cout << "\nYou chose to quit.\n";
                break;
        }
    } while(choice != 0);

    cout << "End of program. Goodbye!" << endl;
    return 0;
}