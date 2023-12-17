#include <iostream>
using namespace std;

//Function prototype
bool isConso(char ch);
int totalConso(string str, int n);

//Driver code
int main()
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    cout << "This string has a total of " << totalConso(str, str.length()) << " consonants" << endl;
    return 0;
}

 //Function to check for consonant
 bool isConso(char ch)
{
    //To handle lower case
    ch = toupper(ch);

    //return 1 if true, 0 for false.
    return !(ch == 'A' || ch == 'E' ||
             ch == 'I' || ch == 'O' ||
             ch == 'U') && ch >= 65 && ch <= 90;
}

//To count total number of consonants from
//0 to n-1.
int totalConso(string str, int n)
{
    if (n == 1)
        return isConso(str[0]);

    return totalConso(str, n - 1) +
        isConso(str[n-1]);
}
