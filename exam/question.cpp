#include <iostream>
#include <string>
using namespace std;


class Hero
{
    string name;
int price;
string processor;

 public :

    void set (string name, int price , string processor){
        this -> name = name;
        this -> price = price;
        this -> processor = processor ;
    } 

    void get (){
        cout << "name  : " << name << endl ;
        cout << "price : " << price << endl ;
        cout << "processor  : " << processor << endl ;
    }
};

int main(){
    Hero a1,a2 ;  
    a1.set("HP ", 120000, "i5 ");
    a2.set("lenevo", 90000, "i7");

    a1.get();
    a2.get();
    return 0 ;
}

