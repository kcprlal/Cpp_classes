#pragma once

#include "Figure.hpp"

class Rectangle : public Figure
{
private:
    double m_a;
    double m_b;

protected:
    // parametrized constructor (why this one is protected?)
    // zeby klasy dziedziczace mogly korzystac z tego konstruktora, ale przy tworzeniu obiektu
    // mozliwe jest skorzystanie jedynie z konstruktora public
    Rectangle(double a, double b, const Point &p, const std::string &name)
        : m_a(a), m_b(b), Figure(p, name) {}

public:
    // parametrized constructor
    Rectangle(double a, double b, const Point &p)
        : m_a(a), m_b(b), Figure(p, "rectangle") {}

    double area() const override
    {
        return m_a * m_b;
    }

    void setA(double newA)
    {
        m_a = newA;
    }

    void setB(double newB)
    {
        m_b = newB;
    }

    double getA() const
    {
        return m_a;
    }

    double getB() const
    {
        return m_b;
    }

    void description() const override
    {
        std::cout << "I have sides of length " << m_a << " and " << m_b << std::endl;
        printCentre();
    }
};
