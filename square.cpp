#include "square.hpp"

Square::Square(Point center, std::string name, int sideLength)
    : Rectangle(center, name, sideLength, sideLength) {
}
