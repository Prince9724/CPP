
#include <iostream>
#include <string>

using namespace std; 

class Shape {
    string color;
    double area; 

public:
    void setColor(string color){
        this->color = color;
    }
    string getColor(){
        return color;
    }

    void setArea(double area){
        this->area = area; 
    }

    double getArea(){
        return area; 
    }
};

class Circle : public Shape
{
private:
    int radius;

public:
    
    Circle(int radius) {
        this->radius = radius;
    }

    void setCircle(int radius)
    {
        this->radius = radius;
    }

    void calculateArea()
    {
        double area = 3.14 * radius * radius;
        setArea(area);

        cout << "Circle Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{
private:
    int length;
    int width;

public:
    Rectangle(int length, int width)
    {
        this->length = length;
        this->width = width;
    }

    void calculateArea()
    {
        double area = length * width;
        setArea(area);

        cout << "Rectangle Area: " << getArea() << endl;
    }
};

int main(){
    
    Circle c(5);
    c.setColor("Red");


    c.calculateArea();
    cout << "Circle Color: " << c.getColor() << endl;

    return 0;
}

