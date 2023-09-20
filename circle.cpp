#include "circle.hpp"
#include <iostream>
#include <numbers>


// Constructor
Circle::Circle(Point center, std::string name, int radius)
    : Shape(center, name), radius(radius) {
}

// Area override
double Circle::area() const {
    double pi = std::numbers::pi;
    return pi * (radius * radius);
}


//draw:
void Circle::draw(std::ostream& out) const {
    for (int y = -radius; y <= radius; y+=2){
        for (int x = -radius; x <= radius; ++x) {
            out << (x*x + y*y <= radius * radius ? '*' : ' ');
        }
        
        out << '\n';
    }
}

//clone circle
Circle* Circle::clone() const {
    return new Circle(*this);      // uses copy constructor.
}