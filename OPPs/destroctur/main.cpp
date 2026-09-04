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