//Fibonacci Series using Recursion
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int fibonacci (int n);

int main ()
{
	int n;

	cout << "Show me the first 10 numbers of the Fibonacci Sequence: " << endl;
	cin >> n;
	cout << fibonacci(n);
	getchar();

	return 0;
}


int fibonacci (int n)
{
	if (n <= 0)
		return 0;
	else if (n ==1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}










// This code is contributed
// by Akanksha Rai
