#include <iostream>
//#include <cmath>
//#define POINT_H
#include "point.h"
//#define POINT_H
int main()
{
    double a, b;
    std::cout << "Enter your coords: ";
    std::cin >> a >> b;
    Point p1(a, b);
    while (true)
    {
        if (a == 0.0 || b == 0.0)
            break;
        std::cout << std::endl;
        p1.display();
        std::cout << "--------------------" << std::endl;
        std::cout << "Now chose different a and b: ";
        std::cin >> a >> b;
        p1.setX(a);
        p1.setY(b);
    }
}