#include <iostream>
using namespace std;

int sumArray(int[], int);
int main()
{
    int numbers[5] = {5, 10, 16, 22, 30};
    int total = sumArray(numbers, 5);

    cout << "The sum of the contents of the array is " << total << endl;

    return 0;
}
/*
int sumArray(int nums[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum+= nums[i];
    return sum;
} //This is doing it but without recursion. */

int sumArray(int nums[], int size)
{
    if (size == 0)
        return 0;
    else
        return nums[size-1] + sumArray(nums, size-1);
}
// ^^done by recursion
