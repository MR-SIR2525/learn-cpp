#include <iostream>
#include <iomanip>
using namespace std;

class Base
{
protected:
int baseVar;

public:
Base (int val = 10)
{
baseVar = val;
}

int getVar() const
{
return baseVar;
}
};

class Derived : public Base
{
private:
int deriVar;

public:
Derived (int val = 200)
{
deriVar = val;
}

int getVar() const
{
return deriVar;
}
};
int main()
{
Base *optr;
Derived object;

optr = &objects;
cout << optr->getVar() << "\n";


return 0;
}
