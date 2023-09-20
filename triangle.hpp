#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"

class Triangle: public Shape {
public:
    Triangle(Point center, std::string name, int height, int width);
    
    double area() const override;
    void draw(std::ostream& out) const override;
    Triangle* clone() const override;
    
protected:
    Triangle(const Triangle& other) = default;   // copy constrcutor, no need to define.

private:
    int base;
    int height;
};

#endif