#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "rectangle.hpp"

class Square : public Rectangle {
public:
    Square(Point center, std::string name, int sideLength);
    
private:
    // no additional needed.
};

#endif
