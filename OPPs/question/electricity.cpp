#include<iostream>
#include<string>

using namespace std ;
class Electricity {
    int unit;
    int total;
    public:
    void setUnits(int unit){
        this-> unit = unit;
    };
    void getUnits(){
        cout << "number of units "<< unit << endl ; 
    }
    void billing (){
        if(unit>=1 && unit<=20){
            total = unit*1;
            cout << "your bill ammount is : "<<total <<endl;
        }
        else if(unit>20 && unit <=50){
            total =  20 +(unit - 20)*1.5;
            cout << "your billing amount is : "<< total << endl ; 

        }
        else if(unit>50 && unit <=100){
            total = 20 + (30*1.5) +(unit-50)*2;
           cout << "your billing amount is : "<< total << endl ;   
        }
        else if(unit >100 && unit<=150){
            total = 20 + (30*1.5)+(50*2)+(unit-100);
          cout << "your billing amount is : "<< total << endl ;            
        }
    }


};

int main(){
    int x ;
    cout <<"enter Your units : ";
    cin>> x ;
    Electricity unit;
    unit.setUnits(x);
    unit.billing();

    return 0;
}