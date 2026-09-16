#include <iostream>
using namespace std;

class Shape
{

    string color;
    double area;

public:
    void setColor(string color)
    {
       this-> color = color;
    }

    string getColor()
    {
        return color;
    }

    void setArea(double a)
    {
        area = a;
    }

    double getArea()
    {
        return area;
    }

    
    virtual void displayDetails()
    {
        cout << "Shape" << endl;
    }
};

class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r, string c)
    {
       this -> radius = r;
        setColor(c);
        setArea(3.14 * radius * radius);
    }

    void displayDetails() override
    {
        cout << "Circle" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Radius: " << radius << endl;
        cout << "Area: " << getArea() << endl;
    }
};

class Rectangle : public Shape
{

    double length;
    double width;

public:
    Rectangle(double l, double w, string c)
    {
       this-> length = l;
       this->  width = w;
        setColor(c);
        setArea(length * width);
    }

    void displayDetails() override
    {
        cout << "Rectangle" << endl;
        cout << "Color: " << getColor() << endl;
        cout << "Length: " << length << endl;
        cout << "Width: " << width << endl;
        cout << "Area: " << getArea() << endl;
    }
};





int main(){
     Circle c(5, "Red");
    Rectangle r(10, 5, "Blue");
    Shape* shapes[2];

    shapes[0] = &c;
    shapes[1] = &r;

      for (int i = 0; i < 2; i++)
    {
        shapes[i]->displayDetails();
        cout << endl;
    }
    return 0 ;
}