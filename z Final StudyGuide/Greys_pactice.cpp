#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

//1.) 
/* struct Car
{
    string make = "GMC",
           model = "Yukon";
    double year = 2010,
           cost = 45495;
};

int main()
{
    Car info;

    cout << "Information about my car: " << endl;
    cout << "Make:  " << info.make << endl;
    cout << "Model: " << info.model << endl;
    cout << "Year:  " << info.year << endl;
    cout << "Cost: $" << info.cost << endl;
}*/


//2


//3.)
/*void selectionSort(int array[], int size) //sorting of a single array
{
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
        minIndex = startScan;
        minValue = array[startScan];
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] < minValue)
            {
                minValue = array[index];
                minIndex = index;
            }            
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;        
    }
}

void selectionSort(int array[], int array2[], int size) //sorting of parallel arrays
{
    int startScan, minIndex, minIndex2, minValue, minValue2;

    for (startScan = 0; startScan < (size - 1); startScan++)
    {
          minIndex = startScan;
          minIndex2 = startScan;
          minValue = array[startScan];
          minValue2 = array2[startScan];
          for(int index = startScan + 1; index < size; index++)
          {
              if (array[index] < minValue)
              {
                 minValue = array[index];
                 minIndex = index;
              }

              if (array2[index] < minValue2)
              {
                 minValue2 = array2[index];
                 minIndex2 = index;
              }
          }
          array[minIndex] = array[startScan];
          array[startScan] = minValue;

          array2[minIndex2] = array2[startScan];
          array2[startScan] = minValue2;
    }
}*/



//4.)
/*void getnumber(int *input)
{
    cout << "Enter an integer number :";
    cin >> *input;
}*/



//5.)
void showMe(int arg);                       //checkpoint 14.3 pg 935

/*int main()
{
    int num = 0;

    showMe(num);
    return 0;
}

void showMe(int arg)
{
    if(arg < 10)
    {
        showMe(++arg);
    }
    else
        cout << arg << endl;
}*/


/*int factorial(int num)                      //factorial recursion template
{
  if (num == 0)  //base case
    return 1;
  else
    return num * factorial(num - 1);
}*/


/*void print(int n)
{
    if (n < 0) 
    {
        return;
    }
 
    print(n - 1);
    cout << n << " ";
}

 
int main()                                   //print numbers from 0 to n using recursion
{
    int num = 10; //dummy number

    print(num);
    return 0;
}*/


/*int add(int n)                              //sum up numbers using recurison
{
    if(n != 0)
    {
        return n + add(n - 1);
    }
    return 0;
}

int main() 
{
    int n = 10;

    cout << "Sum =  " << add(n);

    return 0;
}*/


/*void print_array(int arr[], int size, int i)        //display the contents of array with recursion
{
  
    // base case
    if (i == size) {
        cout << endl;
        return;
    }
  
    // print the ith element
    cout << arr[i] << " ";
    i++;
  
    // recursive call
    print_array(arr, size, i);
}
  
// Driver code
int main()
{
  
    int arr[] = { 3, 5, 6, 8, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
  
    print_array(arr, n, 0);
  
    return 0;
}*/



//7.)
/*template <typename T>                       //rotate left template
void rotateLeft(vector <T>& v)
{
    T temp = v[0];
    int size = v.size();

    for (int k = 1; k < size; k++)
    {
        v[k-1] = v[k];    
    }

    v[size-1] = temp;    
}


template <typename T>                       //min template function
T Min(T smallest, T largest)
{
    if(smallest < largest)
    {
        return smallest;
    }

    else
        return largest;
}


template <typename T>                       //max template function
T Max(T smallest, T largest)
{
    if(largest > smallest)
    {
        return largest;
    }

    else
        return smallest;
}*/



//8.)
/*int main()
{
    int number,
        root;

    cout << "Enter an integer: ";
    cin >> number;

    // Try to find its square root and catch the thrown exception if
    // the number has none      
    try
    {
        root = mySqrt(number);
        if (root == -1)
        {
            cout << "No perfect square root for this number." << endl;
        }
        else
        {
            cout << "Square root is " << root;
        }
    }
    catch(int num)
    {
        cout << "You cannot take the square root of any subsequent number lower than 0." << endl;
    }
}

int mySqrt(int number)
{
   if (number < 0)
     //return -1;
     throw int (-1);

   // Check all integers less or equal to number to see if one of 
   // is a square root
   for (int r = 0; r * r <= number; r++)
   {
     if (r * r == number) 
         return r;                 
   }
   
   return -1; //no perfect square root
}*/