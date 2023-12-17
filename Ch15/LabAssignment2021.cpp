/***********************************************************************************************
 * Student name: Andrew Blythe
 * Program name: Polymorphism Lab Assignment
 * Program description: Shows inheritance relationship between 3 classes, base class is abstract
 * Date: 4/9/2021
*************************************************************************************************/ 
#include <iostream>
#include <vector>
#include <memory>
#include <chrono>   //sleep function
#include <thread>   //sleep function
using namespace std;
using namespace std::this_thread;//sleep function
using namespace std::chrono;     //sleep function

void dogFunction(); 
void catFunction();

class Animal //Base class
{
    protected:
        string name; //name of animal
    public:
        virtual void ID() = 0;
        virtual void sound() = 0;
        //pure virtual becuase of = 0
    //"animal" cannot really have an ID or noise like dog and cat can; abstract class
};

//Child of animal class
class Dog : public Animal
{
    public:
        Dog(string n)
        {
            name = n;
        }
        virtual void ID() 
        {
            cout << "I am a dog and my name is " << name << ". ";
        }
        void sound() override
        {
            cout << "Woof woof." << endl;
        }
};

//Child of animal class
class Cat : public Animal
{
    public:
        Cat(string n)
        {
            name = n;
        }
        virtual void ID() 
        {
            cout << "I am a cat and my name is " << name << ". ";
        }
        virtual void sound() override
        {
            cout << "Meow meow" << endl;
        }
};


const int mySecond = 1000000000; //a billion (1,000,000,000) nanoseconds in one second, my way around "seconds(int)"
string animalName = "";

int main()
{
    catFunction();
    cout << endl << endl;

    for (int dash = 0; dash < 17; dash++)
    {
        cout << "-";
        sleep_for(nanoseconds(mySecond/20));
    }
    cout << " Now...... onto the dogs -----------------\n\n";
    sleep_for(nanoseconds(mySecond/2));

    dogFunction();


    cout << endl << "End of program, goodbye.";
    return 0;
}


void catFunction() /***************** Cat section *****************/
{
    vector<shared_ptr<Animal>> cats;
    int numcats = 0;

    cout << "How many cats are there?" << endl;
    cin >> numcats;
    cin.ignore();

    for(int n = 0; n < numcats; n++)
    {
        cout << "Enter the name of cat " << n+1 << "." << endl;
        getline(cin, animalName);
        cats.push_back(make_shared<Cat>(animalName)); //inserting new cat object into vector/array?
    }

    sleep_for(nanoseconds(mySecond/2));
    cout << endl;

    for (int i = 0; i < numcats; i++)
    {
        cout << "Cat " << i+1 << " says:" << endl;
        cats[i]->ID();
        cats[i]->sound();  

        sleep_until(system_clock::now() + nanoseconds(mySecond/2));
        cout << endl;
    }
}

void dogFunction()
{
    vector<shared_ptr<Animal>> dogs;
    int numdogs = 0;

    cout << "How many dogs are there?\n";
    cin >> numdogs;
    cin.ignore();
    
    for(int d = 0; d < numdogs; d++)
    {   
        cout << "Enter the name of dog " << d+1 << "." << endl;
        getline(cin, animalName);
        dogs.push_back(make_shared<Dog>(animalName));
    }

    sleep_for(nanoseconds(mySecond/2));
    cout << endl;

    for (int e = 0; e < numdogs; e++)
    {
        cout << "Dog " << e+1 << " says:" << endl;
        dogs[e]->ID();
        dogs[e]->sound(); 

        sleep_until(system_clock::now() + nanoseconds(mySecond/2));
        cout << endl;
    }
}