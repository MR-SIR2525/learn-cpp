#include<iostream>
#include<vector>
using namespace std;
template<typename T>
void rotateLeft(vector<T> &v)
{
    T a = v[0];
    for(int i=0;i<v.size()-1;i++)
    v[i]=v[i+1];
    v[v.size()-1]=a;
}

template<typename T>
void output(vector<T> v)
{
   for(int i=0;i<v.size();i++)
   cout<<v[i]<<" ";
   cout<<endl;
}
int main()
{
   //testing with integers
   vector<int> a;
   a.push_back(1);a.push_back(3);a.push_back(5);a.push_back(7);
   for(int i=0;i<a.size();i++)
   {
       output(a);
       rotateLeft(a);
   }
   cout<<endl;

   vector<double> b;
   b.push_back(1.2);b.push_back(3.3);b.push_back(5.4);b.push_back(7.5);
   for(int i=0;i<b.size();i++)
   {
       output(b);
       rotateLeft(b);
   }


   vector<char> c;
   c.push_back('a');c.push_back('b');c.push_back('c');c.push_back('d');
   for(int i=0;i<c.size();i++)
   {
       output(c);
       rotateLeft(c);
   }
   cout<<endl;

   //testing with strings
   vector<string> d;
   d.push_back("Hello");d.push_back("How");d.push_back("Are");d.push_back("You");
   for(int i=0;i<d.size();i++)
   {
       output(d);
       rotateLeft(d);
   }
   cout<<endl;
   return 0;
}






int *ptr = arr;

for (int x = 0; x < 100; x++)

                cout << *(ptr + x) << endl;
