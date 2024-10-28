#ifndef POINT_H
#define POINT_H

class Point
{
private:
    double m_xpoint;
    double m_ypoint;

public:
    Point(double x, double y);
    ~Point();
    void display();
    void setX(double newX);
    void setY(double newY);
    double getX();
    double getY();
};
   
#endif