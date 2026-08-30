#include <iostream>
#include <string>

using namespace std;
class A
{
//method overloading =>  ek class me ek bame ke do function bna skte hai ( you can create same name function in same class but 
// you have to sparate in class by parameter count )
public:
    void print()
    {
        cout << "class  A....";
    }

    void print(int a)
    {
        cout << "class  A.... " << a << endl;
    }
    void print(int a , int b )
    {
        cout << "class  A.... " << a << " " << b << endl;
    }
    void sum(int a)
    {
        cout << a << endl;
    }
    void sum(int a , int b )
    {
        cout << a + b << endl;
    }
     void sum(int a , int b, int c )
    {
        cout << a + b +c << endl;
    }
     void sum(int a , int b, int c, int d )
    {
        cout << a + b +c  + d<< endl;
    }

};

class B : public A
{

public:
    void print()
    {
        cout << "class  B...";
    }

    // void print (){
    //     cout << "class  B" ;
    // }
};
class Bank{
    protected :
    int balance =10000;

    public :

    void deposite (int amount){
        this -> balance +=  amount ;// because ballence kabhi eqaul nahi hoti hai balance add hoti hai.

        cout << amount<< endl  << "deposite successfully !! and your current ballene is :" << this -> balance<< endl;
        //this keyword ke balance me amount store hai. aur vo global variable hai.  
    }

    void withdraw (int amount){
        this -> balance -= amount ;
        cout << amount << endl << "Withraw successfully !! and your current ballene is :" << this -> balance<< endl;

    }
    void checkbalance(){
        cout  << "your current ballene is :" << this -> balance<< endl;

    }
    
};

class Account :public Bank{
    public :
    void cuttax (){
        this -> balance -=200 ;
    }
};
int main()
{

    // A a1;
    // B b1 ;
    // b1.print();
    // Bank rbi ;
    // rbi.deposite(4000);
    // rbi.deposite(14000);
    // rbi.withdraw(2000);
    // rbi.checkbalance();
    // // rbi.balance = 0 ;
    // rbi.checkbalance();
    Account a1 ;
    a1.checkbalance(); 
    a1.cuttax();
    a1.checkbalance();
    return 0;
}