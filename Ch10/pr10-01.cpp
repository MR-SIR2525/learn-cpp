// This program uses the & operator to determine a  
// variable's address.
#include <iostream> 
using namespace std; 
 
int main()
{  
     char letter = 'A';  char *ptrLetter = &letter;
     short number = 1;   short *ptrNumber = &number;
     float amount = 1;   float *ptrAmount = &amount;
     double profit = 1;  double *ptrProfit = &profit;
     char ch = 'B';      char *ptrCh = &ch;
  
  // Print address of each variable
  // The cast to long makes addresses print in decimal
  // rather than in hexadecimal
  cout << "Address of letter is:  "
       <<  ptrLetter << endl;
  cout << "Address of number is:  " 
       << ptrNumber << endl;
  cout << "Address of amount is:  " 
       << ptrAmount << endl;
  cout << "Address of profit is:  "
       << ptrProfit << endl;
  cout << "Address of ch is:      " 
       << ptrCh << endl;	 
  return 0;
}