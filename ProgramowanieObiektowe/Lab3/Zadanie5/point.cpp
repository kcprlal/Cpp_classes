#include "point.h"
#include<iostream>
#include<cmath>

Point::Point(double x, double y) : m_xpoint(x), m_ypoint(y)
{
}

Point::~Point()
{
}

void Point::display()
{
    std::cout << "X coord: " << m_xpoint << std::endl;
    std::cout << "Y coord: " << m_ypoint << std::endl;
    std::cout << "Your hypotenuse is: " << sqrt((m_ypoint * m_ypoint) + (m_xpoint * m_xpoint)) << std::endl;
}

void Point::setX(double newX)
{
    this->m_xpoint = newX;
}
void Point::setY(double newY)
{
    this->m_ypoint = newY;
}
double Point::getX()
{
    return this -> m_xpoint;
}
double Point::getY()
{
    return this -> m_ypoint;
}