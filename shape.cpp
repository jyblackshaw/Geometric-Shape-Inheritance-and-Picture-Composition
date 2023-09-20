#include "shape.hpp"
#include <iostream>

Shape::Shape(Point center, std::string name)
        : center(center), name(name) {
}

// void Shape::print(std::ostream& out) const {
//     out << name << " at (" << center.x << ", " << center.y << ") area = " << area() << "\n";
// }

void Shape::print(std::ostream& out) const{
    out << name << " at (" << center.x << "," << center.y << ") area = " << area() << "\n";
}

Shape* Shape::clone() const {
    // To be implemented in the derived classes
    return nullptr;
}

//Draw, area, clone not implemented as need to be implemented in derived classes (=0 : pure virutal)