#include <iostream>
#include<string>

using namespace std ; 
class Student {
    public :
    //global variable 
    int grid ;
    string name;
    string course;
     
   void setStudent(int grid ,string name , string course)//local varibale 
   {
    this -> grid = grid;//this-> global varible 
    this -> name = name;
    this -> course = course;
   }

   void getStudent(){
    cout << "GRID :"  << this -> grid <<endl;
    cout << "Name :"  << this -> name << endl;
    cout << "Course :"<< this -> course <<endl;
   }

};

class employe 
{
public:
        int grid;
        string name;
        string email;
        int number;
        string age ;

        void setEmploye(int grid , string name , string email , int number , string age)
        {
            this -> grid = grid ;
            this -> name = name;
            this ->email = email;
            this -> number = number;    
            this -> age = age ;
            
        };
};

int main(){
        Student amit,raj;
        amit.setStudent(123,"amit ","course ");
        amit.setStudent(133,"raj  ","Full stack web development !!");
        amit.getStudent();

        return 0 ;
}
