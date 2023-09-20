#ifndef PICTURE_HPP
#define PICTURE_HPP

#include <iosfwd>

#include "shape.hpp"

// class Picture
class Picture {
public:
    
    // initializing constructor creates this as an empty picture
    Picture();
    
    // copy and move constructors for Picture
    Picture(const Picture& other);    //copy
    Picture(Picture&& other);         //move
    
    // swap this Picture's list with other Picture's list
    void swap(Picture& other);
    
    // copy and move assignment for Picture
    Picture& operator=(const Picture& other);
    Picture& operator=(Picture&& other);
    
    // adds clone of shape to end of this Picture's linked list.
    // Cloning allows us to create any number of shape objects.
    // Picture is responsible for deleting cloens when Picture object dies.
    void add(const Shape& shape);
    
    // calls method print() on each shape
    // in order they were added
    void print_all(std::ostream& out) const;
    
    // draws the Shapes in this Picture in the order they were added
    void draw_all(std::ostream& out) const;
    
    // returns sum of areas of all Shapes in this Picture
    double total_area() const;
    
    // frees all storage owned by this Picture when it dies
    ~Picture();
    
private:
    
    struct ListNode{
        Shape* shape;    // pointer to shape (data) in node
        ListNode* prev;
        ListNode* next;
    };
    
    ListNode* head;
    ListNode* tail;
};

#endif