#include <iostream>
using namespace std;

// Base Class

class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

public:
    static int totalVehicles;

    // Constructor
    Vehicle()
    {
        this->vehicleID = 0;
        this->manufacturer = "";
        this->model = "";
        this->year = 0;

        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle()
    {
        totalVehicles--;
    }

    // Setters
    void setVehicleID(int id)
    {
        this->vehicleID = id;
    }

    void setManufacturer(string manufacturer)
    {
        this->manufacturer = manufacturer;
    }

    void setModel(string model)
    {
        this->model = model;
    }

    void setYear(int year)
    {
        this->year = year;
    }

    // Getters
    int getVehicleID()
    {
        return this->vehicleID;
    }

    string getManufacturer()
    {
        return this->manufacturer;
    }

    string getModel()
    {
        return this->model;
    }

    int getYear()
    {
        return this->year;
    }

    virtual void setVehicle()
    {
        cout << "Enter Vehicle ID : ";
        cin >> this->vehicleID;

        cout << "Enter Manufacturer : ";
        cin >> this->manufacturer;

        cout << "Enter Model : ";
        cin >> this->model;

        cout << "Enter Year : ";
        cin >> this->year;
    }

    virtual void getVehicle()
    {
        cout << endl;
        cout << "Vehicle ID : " << this->vehicleID << endl;
        cout << "Manufacturer : " << this->manufacturer << endl;
        cout << "Model : " << this->model << endl;
        cout << "Year : " << this->year << endl;
    }
};

int Vehicle::totalVehicles = 0;
class Car : public Vehicle
{
protected:
    string fuelType;

public:
    Car() : Vehicle()
    {
        this->fuelType = "";
    }

    ~Car()
    {
    }

    void setCar(){
        setVehicle();
        cout << "Enter Fuel Type : ";
        cin >> this->fuelType;
    }

    void getCar() {
        getVehicle();

        cout << "Fuel Type : " << this->fuelType << endl;
    }
};
class ElectricCar : public Car
{
protected:
    float batteryCapacity;

public:
    ElectricCar() : Car()
    {
        this->batteryCapacity = 0;
    }

    ~ElectricCar()
    {
    }

    void setElectricCar()
    {
        setCar();

        cout << "Enter Battery Capacity : ";
        cin >> this->batteryCapacity;
    }

    void getElectricCar()
    {
        getCar();

        cout << "Battery Capacity : "
             << this->batteryCapacity << " kWh" << endl;
    }
};

class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar() : ElectricCar() {
        this->topSpeed = 0;
    }

    ~SportsCar() {}

    void setSportsCar(){
        setElectricCar();

        cout << "Enter Top Speed : ";
        cin >> this->topSpeed;
    }

    void getSportsCar()
    {
        getElectricCar();

        cout << "Top Speed : "
             << this->topSpeed << " km/h" << endl;
    }
};

class Aircraft
{
protected:
    int flightRange;

public:
    Aircraft()
    {
        this->flightRange = 0;
    }

    ~Aircraft()
    {
    }

    void setAircraft()
    {
        cout << "Enter Flight Range : ";
        cin >> this->flightRange;
    }

    void getAircraft()
    {
        cout << "Flight Range : "
             << this->flightRange << " km" << endl;
    }
};
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar() : Car(), Aircraft() {}
    ~FlyingCar(){}
    void setFlyingCar(){
        setCar();
        setAircraft();
    }
    void getFlyingCar(){
        getCar();
        getAircraft();
    }
};

class Sedan : public Car{
public:
    Sedan() : Car(){}
    ~Sedan(){}
    void setSedan(){
        setCar();
    }

    void getSedan(){
        getCar();
    }
};

class SUV : public Car
{
public:
    SUV() : Car()
    {
    }

    ~SUV()
    {
    }

    void setSUV()
    {
        setCar();
    }

    void getSUV()
    {
        getCar();
    }
};

// Main

int main()
{
    Vehicle *vehicles[100];

    int vehicleCount = 0;
    bool isRunning = true;

    while (isRunning)
    {
        int input;

        cout << endl;
    
        cout << "       VEHICLE REGISTRY SYSTEM" << endl;
        cout << "1. Add Car" << endl;
        cout << "2. Add Electric Car" << endl;
        cout << "3. Add Sports Car" << endl;
        cout << "4. Add Flying Car" << endl;
        cout << "5. Add Sedan" << endl;
        cout << "6. Add SUV" << endl;
        cout << "7. View All Vehicles" << endl;
        cout << "8. Search Vehicle By ID" << endl;
        cout << "9. Show Total Vehicles" << endl;
        cout << "10. Exit" << endl;

        cout << endl;
        cout << "Enter your input : ";
        cin >> input;

        switch (input)
        {
        case 1:
        {
            Car *car = new Car();

            car->setCar();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "Car Added Successfully!" << endl;

            break;
        }

            // Add Electric Car

        case 2:
        {
            ElectricCar *car = new ElectricCar();

            car->setElectricCar();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "Electric Car Added Successfully!" << endl;

            break;
        }

            // Add Sports Car

        case 3:
        {
            SportsCar *car = new SportsCar();

            car->setSportsCar();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "Sports Car Added Successfully!" << endl;

            break;
        }

            // Add Flying Car

        case 4:
        {
            FlyingCar *car = new FlyingCar();

            car->setFlyingCar();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "Flying Car Added Successfully!" << endl;

            break;
        }
        case 5:
        {
            Sedan *car = new Sedan();

            car->setSedan();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "Sedan Added Successfully!" << endl;

            break;
        }
    case 6:
        {
            SUV *car = new SUV();

            car->setSUV();

            vehicles[vehicleCount] = car;
            vehicleCount++;

            cout << "SUV Added Successfully!" << endl;

            break;
        }
        case 7:
        {
            for (int i = 0; i < vehicleCount; i++)
            {
                vehicles[i]->getVehicle();
                cout << "------------------------" << endl;
            }

            break;
        }
        case 8:
        {
            int searchID;
            bool found = false;

            cout << "Enter Vehicle ID : ";
            cin >> searchID;

            for (int i = 0; i < vehicleCount; i++)
            {
                if (vehicles[i]->getVehicleID() == searchID)
                {
                    vehicles[i]->getVehicle();

                    found = true;

                    break;
                }
            }

            if (!found)
            {
                cout << "Vehicle Not Found!" << endl;
            }

            break;
        }
        case 9:
        {
            cout << "Total Vehicles : "
                 << Vehicle::totalVehicles << endl;

            break;
        }
        case 10:
        {
            isRunning = false;

            cout << "Thank You For Visiting!" << endl;

            break;
        }

        default:
        {
            cout << "Invalid Input!" << endl;
        }
        }
    }

    for (int i = 0; i < vehicleCount; i++)
    {
        delete vehicles[i];
    }

    return 0;
}