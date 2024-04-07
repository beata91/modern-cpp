#include "Shape.hpp"
#include <iostream>

Shape::Shape() {}

Shape::Shape(Colour c) : colour{c} {}

Colour Shape::getColour() const
{
    return colour;
}

void Shape::print() const
{
    std::cout << "Unknown Shape" << std::endl;
}

std::string Shape::getName() const
{
    return "Shape";
}