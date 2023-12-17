// This program demonstrates the use of a nested structure. 
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct CostInfo
{	
   double food,      // Food costs
          medical,   // Medical costs
          license,   // License fee
          misc;      // Miscellaneous costs
};

struct PetInfo
{
   string name;      // Pet name
   string type;      // Pet type
   int    age;       // Pet age
	
   CostInfo cost;    // A PetInfo structure has a CostInfo structure
                     // nested inside as one of its members
   
   PetInfo()         // Default constructor
   {  name = "unknown";
      type = "unknown";
	  age = 0;
	  cost.food = cost.medical = cost.license = cost.misc = 0.00;
   }
};

int main()
{
   // Define a PetInfo structure variable called pet
   PetInfo pet1; 
	
   // Assign values to the pet member variables.    
   // Notice that cost.misc is not assigned a value,
   // so it remains 0, as set by the constructor.   
   pet1.name = "Sassy";
   pet1.type = "cat";
   pet1.age = 5;
   pet1.cost.food = 300.00;
   pet1.cost.medical = 200.00;
   pet1.cost.license = 7.00;
  
   // Display the total annual costs for the pet
   cout << fixed << showpoint << setprecision(2);
   cout << "Annual costs for my " << pet1.age << "-year-old "
        << pet1.type << " " << pet1.name  << " are $"
        << (pet1.cost.food + pet1.cost.medical + 
            pet1.cost.license + pet1.cost.misc) << endl;
   return 0;
}
