#include<iostream>
#include <string>

using namespace std;

class Second {
    int Totalsecond ;

    public:
      void setSecond(int s ){
        this -> Totalsecond = s ;
    };
    void getSecond(){
            cout << "time is" << Totalsecond ;
    };
    void minute(){
        int minute = Totalsecond/60 ;
        int module = Totalsecond%60 ;
        cout << Totalsecond << " seconds = " << minute << " minute(s) aur " <<module<< " second(s)." << endl;
    }

};
int main(){
    int s ;
    cout << "enter seconds";
    
}