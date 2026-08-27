#include<iostream>
#include<string>

using namespace std ;

class X {
    public :
    int a,b,c ;
};

class Y:public X {
    
    public :
   void setCube(){
        cout << "Enter on number a,b , c : " << endl ;
        cin >> a >>b >> c ;
    };
    void getCube (){
        int sum = (a*a*a)+(b*b*b)+ (c*c*c);
        cout << "sum of cube is : " << sum ;
    }
};

int main(){
    Y  num ;
    num.setCube();
    num.getCube();

    return 0;
}