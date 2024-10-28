#include <iostream>

#include "Square.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"

void line(){
    std::cout<<"---------------------------------"<<std::endl;
}

int main()
{
    Rectangle rectangle(4, 5, Point(12, 14));
    rectangle.introduce();
    rectangle.description();
    std::cout << "Area of rectangle is: " << rectangle.area() << std::endl;
    line();
    Square square(6, Point(30, 40));
    square.introduce();
    square.description();
    std::cout << "Area of square is: " << square.area() << std::endl;
    line();
    Rectangle rectangle2 = rectangle;
    rectangle2.setCentre(Point(21, 37));
    rectangle2.setA(10);
    rectangle2.setB(5);
    rectangle2.introduce();
    rectangle2.description();
    std::cout << "Area of rectangle is: " << rectangle2.area() << std::endl;
    line();
    Circle circle(4, Point(15, 15));
    circle.introduce();
    circle.description();
    std::cout << "Area of circle is: " << circle.area() << std::endl;
    return 0;
}