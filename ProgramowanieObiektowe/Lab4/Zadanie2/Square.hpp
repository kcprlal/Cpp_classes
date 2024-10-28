#pragma once

#include "Rectangle.hpp"

class Square : public Rectangle
{
public:
    // parametrized constructor
    Square(double a, const Point &p) : Rectangle(a,a,p,"Square") {}
    // dzięki temu, że w klasie rectangle konstruktor jest protected mozna to tak ustawiac
    // Square(double a, const Point &p, const std::string &name) : Rectangle(a,a,p,name) {}
};