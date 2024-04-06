#pragma once

enum class Colour : unsigned char {
    Green,
    Yellow,
    Pink
};

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

private:
    Colour colour = Colour::Pink;
};
