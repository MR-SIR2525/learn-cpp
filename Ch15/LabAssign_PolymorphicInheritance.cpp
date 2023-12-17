/*******************************************************************
* Name: Andrew Blythe
* Program description: Cat and Dog classes inherit aspects from base class "Animal."
* Date: 11 March 2020
*******************************************************************/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Animal //Base class
{
protected:
    string name; //n for name of animal
public:
    Animal(string n)
    {
        name = n;
    }
    virtual void makeNoise() const = 0;
    virtual void ID() const = 0;
};

//Child of animal.
class Dog : public Animal
{
public:
    Dog (string n) : Animal(n)
    {

    }
    virtual void ID() const
    {
        cout << "I am a dog and my name is " << name << ". ";
    }
    virtual void makeNoise() const
    {
        cout << "Woof woof." << endl;
    }
};

//Child of animal.
class Cat : public Animal
{
public:
    Cat (string n) : Animal(n)
    {

    }
    virtual void ID() const
    {
        cout << "I am a cat and my name is " << name << ". ";
    }
    virtual void makeNoise() const
    {
        cout << "Meow." << endl;
    }
};

int main()
{
    vector<shared_ptr<Animal>> pets
    {
        make_shared<Cat>("Grey"),
        make_shared<Dog>("Rex"),
        make_shared<Dog>("Charlemagne")
    };

    for (int i = 0; i < pets.size(); i++)
    {
        pets[i]->ID();
        pets[i]->makeNoise();
        cout << endl;
    }
}
