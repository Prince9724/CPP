#include<iostream>
#include<string>
 using namespace std ; 
class P {
    public:
    int temperature;
};
class Q : public P{
   

    public :
        int Fehrenheit ; 

    void toFehrenheit(){
        cout << "Enter temprature in celcius";
        cin >> temperature ;
        Fehrenheit = temperature *(9.0/5.0)+32 ;
        cout << " Temprature in fehrenheit "<<Fehrenheit << "F"<< endl ;
         
    }
    
};
class R :public Q {
    public :
    int kelvin ; 
    void toKelvin (){
        int f = Fehrenheit ;
        kelvin = (f-32)*(5.0/9.0)+273.15;
         cout << "Temperature in kelvin " << kelvin <<" K "<< endl ;
    }
};

int main(){
    R a1;
    a1.toFehrenheit();
    a1.toKelvin();
    return 0;
}