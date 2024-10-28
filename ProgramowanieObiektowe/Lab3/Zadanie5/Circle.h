#ifndef PI
#define PI 3.1415
#endif
#ifndef CIRCLE_H
#define CIRCLE_H

class Circle
{
private:
    double* m_radius;
    Point m_circle_center;
public:
    Circle(double r, Point center);
    ~Circle();
    double area();
    double getradius();
    void setradius(double newradius);
    Point getpoint();
    void setpoint(Point newCenter);
};
#endif
