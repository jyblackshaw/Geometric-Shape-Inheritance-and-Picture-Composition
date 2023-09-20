#include "rectangle.hpp"
#include <iostream>


// Constructor
Rectangle::Rectangle(Point center, std::string name, int height, int width)
    : Shape(center, name), height(height), width(width) {
}

//area
double Rectangle::area() const {
    return height * width;
}


//*draw:
void Rectangle::draw(std::ostream& out) const {
    for (int i = 0; i < height; i += 2){
        for (int j = 0; j < width; ++j) {
            out << '*';
        }
        out << '\n';
    }
}

//clone circle
Rectangle* Rectangle::clone() const {
    return new Rectangle(*this);      // uses copy constructor.
}