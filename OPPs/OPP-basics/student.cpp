#include <iostream>
using namespace std;

class employee
{
public:
    string eName;
    int eNo;
    string eDep;
    int ePhoneNo;

    void input(string name, int number, string department, int phone)
    {
        eName = name;
        eNo = number;
        eDep = department;
        ePhoneNo = phone;
    }
};

int main()
{
   employee e;
    e.input("prince",1,"full stack web development",123467890);
}



class student
{
public:
    string sName;
    int sNo;
    int sStd;
    string sDiv;

    void input(string name,int roll,int std,string div)
    {
        sName = name;
        sNo = roll;
        sStd = std;
        sDiv = div;
    }
};

int main()
{
   student s;
    s.input("prince ",1,3,"A");
}