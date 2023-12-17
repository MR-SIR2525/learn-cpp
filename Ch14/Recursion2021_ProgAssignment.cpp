/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Recursion Programming Assignment
 * Program description: Recursion-based... Main menu (powered by switch case) allows user to display a 
 * sign n times, sum up an array of ints, and reverse a string. Each menu selection has its own function, 
 * but uses a separate function to recursively accomplish the task. 
 * Date: 3/23/2021
*************************************************************************************************/ 
#include <iostream>
#include <cstring>

using namespace std;
//These are for the switch case in "int main()"
void conversionOfSign();
void arraySum();
void stringReverser();

void sign(int n);           //displays message n times (converted to use recursion)
int sum(long array[], int size); //sums up contents in an array of ints
void printReverse(string);  //returns whatever string passed to it in reverse 

int main()
{
    int choice;
    char endChoice;

    cout << "This program allows you to do the following:\n\n";
    do
    {
        cout << "Input the number of an option you would like to try, or \"0\" to quit.\n";
        cout << " 1.) Display a \"No Parking\" sign however many times you choose\n"
             << " 2.) Input a list of numbers to be summed up\n"
             << " 3.) Reverse a word or phrase that you type in\n";
        
        cin >> choice;

        switch(choice)
        {
            case 1:
            {   
                cout << "\n";
                conversionOfSign();
                break;
            }
            case 2:
            {   
                cout << "\n";
                arraySum();
                break;
            }
            case 3:
            {   
                cout << "\n";
                stringReverser(); 
                break;
            }
            case 0:break;
        }

        cin.clear();  
        //cin.ignore(100, '\n'); //input buffer reset ////freezes case three for some reason
        if (choice != 0) //logic: this runs for case 1, 2, 3 
        {
            cout << "\nWould you like to return to the main menu? (Y/N)  ";
            cin >> endChoice;
            while(toupper(endChoice) != 'Y' && toupper(endChoice) != 'N')
            {
                cin.clear();  cin.ignore(100, '\n');
                cout << "Invalid entry. Please input Y or N: ";
                cin >> endChoice;
            }
            cout << "\n";
        }

    } while(choice != 0 && (toupper(endChoice) == 'Y' || toupper(endChoice) != 'N'));


    cout << "End of program - goodbye!";
    return 0;
}


/**** Case 1:Displaying a message n times by calling recursive function ***************/
void conversionOfSign()
{
    int num;
    
    cout << "How many times would you like to display the sign?\n";
    cin >> num;
    //input validation
    while (!cin || num < 0) 
    {
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Invalid entry. Please try again. "
             << "How many times would you like to display the sign?\n";
        cin >> num;
    }
    cin.clear();  cin.ignore(100, '\n'); //prevents next verification from running for this ^^^

    //displaying the message, call to recursive function
    sign(num);
}
//recursive function to display message n times
void sign(int n)
{
    if (n > 0)
    {
        cout << "No Parking." << endl;
        sign(n - 1);
    }
}


/**** Case 2:Adding up an array of numbers ********************************************/
void arraySum()
{
    int size = 1;

    cout << "How many numbers would you like to sum up? "; 
    cin >> size;
    while(!cin || size < 0)
    {
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Invalid entry. Please try again. "
             << "How many numbers? ";
        cin >> size;
    }
    cin.clear();  cin.ignore(100, '\n'); //clears cin error flag and ignores - needed for next verification to work properly

    cout << "Enter the numbers you want to sum up. Press enter after each one or separate them by spaces.\n";
    long nums[size];

    for (int i = 0; i < size; i++)
    {
        cin >> nums[i];
        while(!cin)
        {
            cin.clear();  cin.ignore(100, '\n'); //input buffer reset
            cout << "Invalid entry. Please try again. Number -> ";
            cin >> nums[i];
        }
    }
    
    auto total = sum(nums, size); 
    cout << "The sum of the numbers you entered is " << total << ".\n";
}
//recursive function to add up numbers from an array
int sum(long array[], int size) 
{
	if (size == 0)
		return 0;
	else
		return array[size-1] + sum(array, size-1);
}


/**** Case 3:Reversing a string with recursive function *******************************/
void stringReverser()
{
    cout << "Type in something you want to see written backwards.\n ";
    string reverseThis;
    cin.ignore(); //for some reason cin.ignore() was needed to prevent this from not working if running it after case 2
    getline(cin, reverseThis);
    
    cout << "\nThat reversed = ";
    printReverse(reverseThis);
    
}
//recursive function to print a string passed in reverse
void printReverse(string sss)
{
    int numOfChars = sss.size();

    if(sss.size() == 0)
    {
        return;
    }
    printReverse(sss.substr(1));
    cout << sss[0];
}


/*************** Old Code ****************
int vectSum(vector<long> nums)
{
    if (nums.size() <= 1) //base case
    {
        return nums[0];
    }
    else 
    {
        //slice = substr but for vectors...  slice(from  x index to y index)
        //Here, making a new vector with all elements except first, recursively...
        vector<long> slice(nums.begin()+1, nums.begin()+nums.size());

        return nums[0] + vectSum(slice); //recursive call
    }
}   

void arraySum()
{
    int amount;
    cout << "How many numbers would you like to sum up? "; 
    cin >> amount;
    while(!cin || amount < 0)
    {
        cin.clear();  cin.ignore(100, '\n'); //input buffer reset
        cout << "Invalid entry. Please try again. "
             << "How many numbers? ";
        cin >> amount;
    }
    cout << "Enter the numbers you want to sum up, pressing enter after each one.\n";
         //<< "Input a letter or space when you've entered them all.\n";
    int size = amount;
    long nums[size];
    //vector<long> vNums = {0, 0};
    int i = 0;
    
    /*while (cin && i < size)   //first attempt
    {
        size++;
        cin >> nums[i]; //no input validation because invalid input breaks loop here, and negatives are permitted also
        i++;
    }

    while (cin)   //second attempt with vectors...
    {
        cin >> vNums[i];
        i++;
    } 
    //I was trying to dynamically grow an array as the user entered in numbers, but I couldnt get it to work past element 7...
    //This led me to vectors... still same effect, almost as if the the dynamic growth of the size was faulty, or my while loop was flawed...
    //It would have been easier to read them into a string and then convert the string into separate numbers, but I don't know how to do that
    for (; i < size; i++)
    {
        cin >> nums[i];
        while(!cin)
        {
            cin.clear();  cin.ignore(100, '\n'); //input buffer reset
            cout << "Invalid entry. Please try again. Number -> ";
            cin >> nums[i];
        }
    }
    
    auto total = sum(nums, size);
    //auto total = vectSum(vNums);
    cout << "The sum of the numbers you entered is " << total << ".";
}

*************************************************/