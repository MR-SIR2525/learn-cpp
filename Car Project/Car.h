#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED
// Declaration of "Car" class in its own file (header file?)

using namespace std;
class Car
{
    private:
      int year;
      string make;
      string model;
      int speed;

    public: // Defaults?
      Car(int y = 1900, string mk = "Unknown", string model = "Unknown")
        {
            year = y;
            make = mk;
            model = "Model S";
            speed = 0;
        }
    // My get functions...
        int getYear() // Year
        {
            return year;
        };

        string getMake() // Make
        {
            return make;
        };

        string getModel() // Model
        {
            return model;
        };

        int getSpeed() // Speed
        {
            return speed;
        };


    // Changes to car speed...
      void accelerate()
      {
          speed +=5;
      };
      void brake()
      {
          if (speed >=5)
            speed -=5;
            //cout << "Speed decreased by 5 mph.\n";
          else
            speed = 0;
      }
};



#endif // CAR_H_INCLUDED
