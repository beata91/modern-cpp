#include "Shape.hpp"
#include <iostream>

Shape::Shape() {}

Shape::Shape(Colour c) : colour{c} {}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}
