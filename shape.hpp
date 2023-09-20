#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iosfwd>
#include <string>

struct Point {
    int x;
    int y;
};

class Shape {
public:

    //construct this Shape with given center and name
    Shape(Point center, std::string name);

    // prints this Shape's name and coordinates
    // format: name(center.x, center.y), e.g., Circle_2(1.0,2.3)  + newline.
    void print(std::ostream& out) const;

    // delete assignment to prevent accidental slicing
    Shape& operator=(const Shape& other) = delete;

    // computes and returns the area of this Shape
    // pure virutal: makes class abtract
    virtual double area() const = 0;

    //draws this Shape using character graphcis
    // use algorithms given in write-up
    virtual void draw(std::ostream& out) const = 0;

    // create a new duplicate of this Shape
    // allocated from the free store
    // *must be over-ridden by each concrete class to return a copy of itself
    virtual Shape* clone() const = 0;

    // clean up any sub-storage owned by this Shape object (destructor)
    virtual ~Shape() = default;    // default so don't need to handle cleanup?

protected:

    //protect the copy constructor to be used only by clone()
    Shape(const Shape& other) = default;

private:

    // position coordinates, used to illustract inheritance
    Point center;

    // the name of this shape (supplied to the constructor)
    std::string name;
};

#endif