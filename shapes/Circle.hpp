#pragma once

#include "Shape.hpp"

class alignas(128) Circle final : public Shape
{
public:
    using Shape::Shape;
    Circle() = delete;
    Circle(double r);
    Circle(const Circle & other) = default;

    double getArea() const override;
    double getPerimeter() const override;
    double getRadius() const;
    void print() const override;
    std::string getName() const override;

private:
    double r_ = 1.0;
};
