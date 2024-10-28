#include <iostream>
#include "point.h"
#include "Circle.h"

int main()
{
    double r, a, b;
    std::cout << "Enter radius and center coords: ";
    std::cin >> r >> a >> b;
    Point p1(a, b);
    Circle c1(r, p1);
    while (true)
    {
        if (r < 0)
            break;
        std::cout << std::endl;
        std::cout << "Radius of your circle is: " << c1.area() << std::endl;
        std::cout << "--------------------" << std::endl;
        std::cout << "Now chose different radius: ";
        std::cin >> r;
        c1.setradius(r);
    }
}
