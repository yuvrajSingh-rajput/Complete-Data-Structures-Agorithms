#include <iostream>
using namespace std;

// car class definition;
class Car
{
public:
    // Data members(state)
    string make;
    string model;
    int year;
    float speed;

    // Member function (behaviour)
    void start()
    {
        cout << "car started.\n";
        speed = 0.0;
    }
    void accelerate(float increament)
    {
        speed = speed + increament;
        cout << "Accelerating. current speed: " << speed << " km/h.\n";
    }
    void brake()
    {
        if (speed > 0.0)
        {
            speed = speed - 5.0;
            if (speed < 0.0)
            {
                speed = 0.0;
            }
        }
        cout << "Breaking. Current speed: " << speed << " km/h\n";
    }
};

int main()
{
    // creating objects of the Car class.
    Car car1, car2;

    // Assigning values to data members of car1.
    car1.make = "Toyota";
    car1.model = "Corolla";
    car1.year = 2020;
    car1.speed = 0.0;

    // Assigning values to data members of car1.
    car2.make = "Honda";
    car2.model = "Civic";
    car2.year = 2019;
    car2.speed = 0.0;

    // Interacting with car objects using member functions;
    car1.start();
    car1.accelerate(30.0);
    car1.brake();

    car2.start();
    car2.accelerate(30.0);
    car2.brake();

    return 0;
}