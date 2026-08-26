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
    void hour(){
        int hour = Totalsecond/3600 ;//total secon (7300) ko 3600 se divide krne ke baad idher se hour nikl jayega 
        int module = Totalsecond%3600 ; //totaSecond me vaps se 3600 se module krenge to hour ke baad kuch number bachega 100
        int minute= module/60;// 100 ko 60 se devide krenge to  minute nikl jayega 1 minutte (aur 40)
        int second = module%60;// 100 ko 60 se module krenge to 40 milega jo second hai 
        cout << Totalsecond << " seconds = " << hour << " hours aur " <<minute<< " minutes "<<second <<" seocnd" << endl;
    }

};
//isme logic divide aur module ka hai simple hai agar hour nikalna hai to 3600 se divide dena hai 
// aur minute nikana hai to 3600 se module nikalna hai 
int main(){
    int s ;
    cout << "enter seconds";
    cin >> s;
    Second min;
    min.setSecond(s);
    // min.minute(); 
    min.hour();
}