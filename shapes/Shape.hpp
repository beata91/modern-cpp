#pragma once
#include <string>

enum class Colour : unsigned char {
    Green,
    Yellow,
    Pink
};

class Shape
{
public:
    Shape ();
    Shape (Colour c);
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;
    virtual Colour getColour() const;
    virtual std::string getName() const;

private:
    Colour colour = Colour::Pink;
};
