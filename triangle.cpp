#include "triangle.hpp"
#include <algorithm>
#include <iostream>


// Constructor
Triangle::Triangle(Point center, std::string name, int base, int height)
    : Shape(center, name), base(base), height(height) {
}

//area : b*h / 2
double Triangle::area() const {
    return (base * height) / 2.0;
}

void Triangle::draw(std::ostream& out) const {
    int offset = std::max(height, base);
    
    for (int i = 0; i < height; i += 2) {
        for (int j = 0; j < (offset - i) / 2; ++j) {
            out << ' ';
        }
        
        for (int k = 0; k <= i; ++k) { 
            out << '*';
        }
        out << '\n';
    }
}


//clone circle
Triangle* Triangle::clone() const {
    return new Triangle(*this);      // uses copy constructor.
}

