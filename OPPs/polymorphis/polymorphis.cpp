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


// polymorphis means to  handle multiple process by same name. 
// when we want to create same name  fuction with different functionalty
// jab hmme ekhi name ka alag alag functionality create krna ho tab polymorphism recreate hota hai.


// ise do method hote hai 
// 1. method overloading ==> ek class me ek name ke do function bna skte ho (you can create same name fuction in same class but you have to saprate in class by parameter count   )
	
// same function agar parameter pass kro to alag function de rha hai aur parameter na pass kro to alag function de rha hai.  

// 2. method overriding  ==> we can create same name methode in parrante child relation but if you call method from child class then parrant method will be override. (agar parant se parrrant ke method ko call krenge to output aa jayega  but child se parent ke methode ko call krenge to parrant mrthode override hoga. aur child ka output aa jaayega. ) 
 


// 4. data Abstraction -> is process of hiding essentional/ secure / important information from the users and display only necessary data . 
// we decide how system will work and will be used 
// we can secire data by make attributes private, 
// make attributes/ data secure from diresct access of the user 
// bina user ke direct koi data access kr pana chahiye nahi 

// 1. proper user of access modifier (public , private , protected )
//  ** virtual function data ===> we can create virtual function by using virtual keyword. 
//  parant / flow / formate  -> child ko parant ka flow krna hi pdega agr nhi krega to code aage nhi badhega 
// 	isme fucion ka hed parant class ke ander bnana hai aur body child ke ander bnana hai bina body bnaye code run nhi hoga error aayegi .


// ** pure virtual function ===> virtual function ka use krna hai aur 0 bhi declare krna hai 


// ..ATM
// debit - > pin -> atm 