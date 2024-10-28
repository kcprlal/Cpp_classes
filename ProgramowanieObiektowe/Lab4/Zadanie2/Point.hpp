#pragma once

class Point
{
private:
    int m_x;
    int m_y;

public:
    // parametrized constructor
    Point(int x, int y) : m_x(x), m_y(y) {}

    int getX() const
    {
        return this->m_x;
    }
    int getY() const
    {
        return this->m_y;
    }
    void setX(int value)
    {
        this->m_x = value;
    }
    void setY(int value)
    {
        this->m_y = value;
    }
};