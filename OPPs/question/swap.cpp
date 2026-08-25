#include<iostream>
#include<string>
using namespace std ;
class Swap{
  
int a ;  
int b ; 
  public:
    void setSwap (int a, int b){
        this -> a = a ;
        this -> b = b ;
    };
    void getSwap (){
      cout << "a :"  << this -> a <<endl;
      cout << "b :" << this -> b << endl;
    };
    void swap (){
        this ->a = this ->a +this-> b;//10 +20 = 30
        this ->b = this ->a - this-> b;//30 -20 = 10 b =10
        this ->a = this ->a -this-> b;//30 - 10 = 20 
    };
};

int main()
{
    int x,y ;
    cout << "enter value of a :" ;
    cin >> x ;
    cout <<" enter value of b : ";
    cin >> y; 
    Swap number;
     number.setSwap(x,y);
     number.swap();
        cout << "--- Swapping ke baad ---" << endl;
    number.getSwap();
return 0;
}