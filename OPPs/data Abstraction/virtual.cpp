#include<iostream>
#include <string>

using namespace std ;
// class A {
//     int balance ;
//     string name,  bankName ;

//     public :
//     void set (int balance ,string name , string bankName ){
//         this -> balance = balance ;
//         this -> name = name;
//         this -> bankName = bankName ;
        
//     }
//     void get (){
//         cout << "balance : " << balance << endl ;
//         cout << "name : " << name << endl ;
//         cout << "bankName : " << bankName << endl ;
//     }
// };


class RBI {
    public :
    virtual void guidLine()= 0 ;
    virtual void  intrestRate()=0;
};
class CBI : public RBI{
    public :
    void guidLine(){
        cout<< "guidLine Followed !! " << endl ;
    } ; 
    void intrestRate(){
        cout<< " intrestRate Followed !! " << endl ;
    } ; 
    void print(){
        cout << "Hello" << endl ;
    }
};
 
int main (){
    // A a1;
    // a1.set(1000, "aman ", " RBI"); 
    // a1.get();
    CBI a1 ;
    a1.print();
    a1.guidLine();
    return 0 ;
}