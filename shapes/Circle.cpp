#include "Circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle(double r)
    : r_(r)
{}

double Circle::getArea() const
{
    static_assert(M_PI != 3.14, "M_PI == 3.14");
    return M_PI * r_ * r_;
}

double Circle::getPerimeter() const
{
    static_assert(M_PI != 3.14, "M_PI == 3.14");
    return 2 * M_PI * r_;
}

double Circle::getRadius() const
{
    return r_;
}

void Circle::print() const
{
    std::cout << "Circle: radius: " << getRadius() << std::endl
              << "          area: " << getArea() << std::endl
              << "     perimeter: " << getPerimeter() << std::endl;
}
