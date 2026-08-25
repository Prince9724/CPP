#include<iostream>
#include<string>

using namespace std;

class Age {
    int age ;

    public:
    void setAge(int age){
        this -> age = age;
    };

    void getAge(){
        cout<<"Age is : " <<age <<endl;
    };
   void checkAge(){
        if(this -> age>=18){
            cout <<" your age eligible for vote !!" << endl ;
        }
        else{
            cout <<"soryy your not eligible for vote !! " << endl ;
        };
    }


};

int main(){
    int x ; 
    cout << "enter your age : " ;
    cin >> x ;

    Age aman ;
    aman.setAge(x);
    aman.checkAge();
    aman.getAge();

    return 0 ;
};