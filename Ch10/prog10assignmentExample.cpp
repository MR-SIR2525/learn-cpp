#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

struct Person
{
   string name;
   int age;
};

int main()
{
    struct Person data[10];
    struct Person *pData[10],*temp;

    string names[] = {"a","b","c","g","z","l","p","q","r","w"};
    int num[] = {4,6,34,8,13,90,33,22,18,23};

// for int i=0, if i<9, then increment by +1.
    for(int i=0;i<9;i++)
    {
        data[i].name = names[i];
        data[i].age = num[i];
        pData[i] = &data[i];
    }

    for(int i=0;i<9;i++)
    {
        for(int j=i+1;j<9;j++)
        {
            if(pData[i]->name.compare(pData[j]->name)>0)
            {
                temp = pData[i];
                pData[i] = pData[j];
                pData[j] = temp;
            }
        }
    }

    for(int i=0;i<9;i++)
    {
        cout<<pData[i]->name<<" "<<pData[i]->age<<endl;
    }
}
