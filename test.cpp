#include <iostream>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    int num_count=0;
    char ch;

    while (num_count<10)
            {
                 cin.get(ch);
                 if (isdigit(ch[num_count]) ) number[num_count++]=ch;
            }
}
