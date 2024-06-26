#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <memory>
#include <unordered_map>
#include "Shape.hpp"
#include "Rectangle.hpp"
#include "Square.hpp"
#include "Circle.hpp"

using namespace std;

using Collection = vector<shared_ptr<Shape>>;

bool sortByArea(shared_ptr<Shape> first, shared_ptr<Shape> second)
{
    if(first == nullptr || second == nullptr)
        return false;
    return (first->getArea() < second->getArea());
}

bool perimeterBiggerThan20(shared_ptr<Shape> s)
{
    if(s)
        return (s->getPerimeter() > 20);
    return false;
}

bool areaLessThan10(shared_ptr<Shape> s)
{
    if(s)
        return (s->getArea() < 10);
    return false;
}

void printCollectionElements(const Collection& collection)
{
    for(const auto& el : collection)
        if(el)
            (el)->print();
}

void printAreas(const Collection& collection)
{
    for(const auto& el : collection)
        if(el)
            cout << (el)->getArea() << std::endl;
}

void findFirstShapeMatchingPredicate(const Collection& collection,
                                     bool (*predicate)(shared_ptr<Shape> s),
                                     std::string info)
{
    auto iter = std::find_if(collection.begin(), collection.end(), predicate);
    if(*iter != nullptr)
    {
        cout << "First shape matching predicate: " << info << endl;
        (*iter)->print();
    }
    else
    {
        cout << "There is no shape matching predicate " << info << endl;
    }
}

constexpr int fibonacci (int a)
{
    if (a <= 2) {
        return 1;
    }
    else {
        return fibonacci(a-2) + fibonacci(a-1);
    }
}

int main()
{
//    constexpr int fib = fibonacci(45);
//    std::cout <<  "fib: " << fib << std::endl;

    Collection shapes{make_shared<Circle>(2.0),
                      make_shared<Circle>(3.0),
                      nullptr,
                      make_shared<Circle>(4.0),
                      make_shared<Rectangle>(10.0, 5.0),
                      make_shared<Square>(3.0),
                      make_shared<Circle>(4.0),
                      make_shared<Circle>(Colour::Green),
                      make_shared<Rectangle>(Colour::Pink),
                      make_shared<Square>(Colour::Yellow),
                      };

    printCollectionElements(shapes);

    cout << "Areas before sort: " << std::endl;
    printAreas(shapes);

    std::sort(shapes.begin(), shapes.end(), sortByArea);

    cout << "Areas after sort: " << std::endl;
    printAreas(shapes);

    auto square = make_shared<Square>(4.0);
    shapes.push_back(square);

    findFirstShapeMatchingPredicate(shapes, perimeterBiggerThan20, "perimeter bigger than 20");
    findFirstShapeMatchingPredicate(shapes, areaLessThan10, "area less than 10");

    std::cout << "alignof(Circle): " << alignof(Circle) << std::endl;

    std::unordered_map<std::shared_ptr<Shape>, double> perimeters;
    for ( const auto& el : shapes) {
        if (el) {
            perimeters.insert({el, el->getPerimeter()});
        }
    }

    for (const auto& [key, value] : perimeters) {
        std::cout << "Shape: " << key->getName() << ". " << "Perimeter: " << value << "." << std::endl;
    }

    return 0;
}

