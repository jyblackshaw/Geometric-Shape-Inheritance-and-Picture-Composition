#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

class Rectangle: public Shape {
public:
    Rectangle(Point center, std::string name, int height, int width);
    
    double area() const override;
    void draw(std::ostream& out) const override;
    Rectangle* clone() const override;
    
protected:
    Rectangle(const Rectangle& other) = default;   // copy constrcutor, no need to define.

private:
    int height;
    int width;
};

#endif