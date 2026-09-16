#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
public:
    virtual void startEngine() = 0;
    virtual void drive() = 0;
};

class Car : public Vehicle
{
public:
    void startEngine() override
    {
        cout << "Car engine started." << endl;
    }

    void drive() override
    {
        cout << "Car is driving." << endl;
    }
};

// Bike class Car ke BAHAR hai
class Bike : public Vehicle
{
public:
    void startEngine() override
    {
        cout << "Bike engine started." << endl;
    }

    void drive() override
    {
        cout << "Bike is driving." << endl;
    }
};

int main()
{
    Bike b;

    b.startEngine();
    b.drive();

    return 0;
}