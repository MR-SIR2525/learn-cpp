#include <iostream>
#include <string>
#include <memory>
#include <vector>

using namespace std;

class Animal
{
    public:
    virtual void id(string n) = 0;  //virtual function to allow for polymorphism
    virtual void sound() = 0;
/**
    virtual void getName(string n)=0;
    
    {
    cout<<"animal"<<endl;
    }
    
    virtual void horns() const final
    {
    cout <<"horns"<<endl;
    }
*/
   
};

class Cat : public Animal
{
    private: 
    string name;
    public: 
    void id(string n) override
    {
      cout<< "I am a cat and my name is "<< n <<endl;
    }

    void sound()
    {
        cout<<"Meow"<<endl;
    }
    
};
class Dog : public Animal
{
    public: void id(string n)
    {
        cout<< "I am a dog and my name is "<< n <<endl;
    }
    
    void sound()
    {
        cout<<"Woof Woof "<<endl;
    }
};


int main ()
{  
    string name;
    /*
        //Animal *kitty = new Cat();
        //Animal *Doggy = new Dog();
    /*
    vector<shared_ptr<Animal>> dogs
        {
            make_shared<Dog>(),
            make_shared<Dog>(),
        };
    vector<shared_ptr<Animal>> cats
        {
        make_shared<Cat>(),
        make_shared<Cat>()
        };
    */




    int numcat;
    int numdog;


    vector<shared_ptr<Animal>>cats;

    do
    {
        cout<<"How many cats do you have; "<<endl;
        cin>>numcat;

    } while(numcat <= 0);

    vector<shared_ptr<Animal>>dogs;//Creates new dog variable
    do
    {
        cout<<"How many dogs do you have; "<<endl;
        cin>>numdog;

    }while(numdog <=0 );

    cout<<endl;

    //Animal *pA[] ={new Animal(), new Dog (), new Cat()};

    for(int x=0; x < numcat; x++)
    {
        cats.push_back(make_shared<Cat>()); //
        cout << "what is the name of cat " << (x+1) << endl;
        cin >> name;
        cats[x] -> id(name);
        cats[x] -> sound();
    }
    
    cout<<endl;
    for (int y=0; y < numdog; y++)
    {
        dogs.push_back(make_shared<Dog>());
        cout << "What is the name of the dog" << endl;
        cin >> name;
        dogs[y] -> id(name);
        dogs[y] -> sound();
    }
        
    return 0;

    /*
    for(int k=0; k<2; k++)
    {
    pA[k]->id(); 
    pA[k]->getName();
    pA[k]->sound();

    //pA[k]->horns();
    }
    */
   
}