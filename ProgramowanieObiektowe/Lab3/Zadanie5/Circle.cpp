#include <iostream>
#include "point.h"
#include "Circle.h"

Circle::Circle(double r, Point center) : m_circle_center(center)
{
    m_radius = new double;
    *m_radius = r;
}

Circle::~Circle()
{
    delete m_radius;
}

double Circle::area()
{
    return PI * (*m_radius) * (*m_radius);
}

double Circle::getradius(){
    return *m_radius;
}

void Circle::setradius(double newradius){
    *m_radius = newradius;
}

Point Circle::getpoint(){
    return m_circle_center;
}

void Circle::setpoint(Point newCenter){
    this -> m_circle_center=newCenter;
}
