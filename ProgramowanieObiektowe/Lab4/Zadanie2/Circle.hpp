#pragma once
#include "Figure.hpp"
class Circle : public Figure
{
private:
    double m_radius;

public:
    Circle(double r, const Point &p) : m_radius(r), Figure(p, "Krzysiek") {}

    void description() const override
    {
        std::cout << "I have radius of length " << m_radius << std::endl;
        printCentre();
    }

    void setR(double newR)
    {
        m_radius = newR;
    }

    double getR(){
        return m_radius;
    }

    double area()const override{
        return 3.14*m_radius*m_radius;
    }
};