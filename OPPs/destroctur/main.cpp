#include<iostream>
#include<string>

using namespace std;

class Student
{
    int id, age, std;
    string name;

public:
    Student() //  yaha pr polyphormism ka concept work kr rha hai 
    {
      cout << "Enter Id : "<< endl;
      cin >> id ; 
      cout << "Enter name : "<< endl;
      cin >> name ; 

      cout << "Enter std : "<< endl;
      cin >> std ; 

      cout << "Enter age: "<< endl;
      cin >> age ;
     cout << endl ; 

    }
    Student(int id, int age, int std, string name) // ye parameter contructor hai bina set ka use kiye ham code ko run kr skte hai 
    {
        this->id = id;
        this->name = name;
        this->std = std;
        this->age = age;
    }
    // void set() {

    // };

    void get()
    {
        cout << "id : " << this->id << endl;
        cout << "name : " << this->name << endl;
        cout << "std : " << this->std << endl;
        cout << "age : " << this->age << endl;
    }
    ~Student(){// destuctor sabse last me call hota hai .
        cout << " destructor is calling !! " << endl ;// jitni baar get function o call krenge ui baar last me ye call hota hai 
    };
};

int main (){

    Student a2 ;
    a2.get();

    return 0 ;
}























#include <iostream>
using namespace std;

class BankAccount
{
private:
    int accountNumber;
    double balance;
    string ownerName;

public:
    // Constructor
    BankAccount(int accNo, double bal, string name)
    {
        accountNumber = accNo;
        balance = bal;
        ownerName = name;
    }

    // Credit money
    void credit(double amount)
    {
        balance = balance + amount;
        cout << "Amount credited successfully." << endl;
    }

    // Debit money
    void debit(double amount)
    {
        if (amount <= balance)
        {
            balance = balance - amount;
            cout << "Amount debited successfully." << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Display balance
    void displayBalance()
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: " << balance << endl;
    }
};

int main()
{
    BankAccount account(101, 10000, "Prince");

    cout << "Initial Account Details:" << endl;
    account.displayBalance();

    cout << "\nAfter Credit:" << endl;
    account.credit(5000);
    account.displayBalance();

    cout << "\nAfter Debit:" << endl;
    account.debit(3000);
    account.displayBalance();

    return 0;
}






















3



#include <iostream>
using namespace std;

class Shape
{
private:
    string color;
    double area;

public:
    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }

    void setArea(double a)
    {
        area = a;
    }

    double getArea()
    {
        return area;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r)
    {
        radius = r;
    }

    void calculateArea()
    {
        double area = 3.14 * radius * radius;
        setArea(area);

        cout << "Circle Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
private:
    double length;
    double width;

public:
    Rectangle(double l, double w)
    {
        length = l;
        width = w;
    }

    void calculateArea()
    {
        double area = length * width;
        setArea(area);

        cout << "Rectangle Area: " << getArea() << endl;
    }
};

int main()
{
    Circle c(5);
    c.setColor("Red");

    Rectangle r(10, 5);
    r.setColor("Blue");

    cout << "Circle:" << endl;
    cout << "Color: " << c.getColor() << endl;
    c.calculateArea();

    cout << "\nRectangle:" << endl;
    cout << "Color: " << r.getColor() << endl;
    r.calculateArea();

    return 0;
}







