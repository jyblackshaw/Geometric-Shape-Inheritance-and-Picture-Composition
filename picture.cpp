#include "picture.hpp"
#include <iostream>
#include <utility>


Picture::Picture() : head(nullptr), tail(nullptr){
}

Picture::Picture(const Picture& other) : Picture() {
    ListNode* current = other.head;
    ListNode* previous = nullptr;

    while (current != nullptr) {
        add(*(current->shape));

        if (previous == nullptr) {
            head = tail;
        }
        previous = tail;
        current = current->next;
    }
}

Picture::Picture(Picture&& other) {
    head = other.head;
    tail = other.tail;

    // Reset other to an empty state
    other.head = nullptr;
    other.tail = nullptr;
}

void Picture::swap(Picture& other) {
    // Swap the head pointers
    ListNode* temp = head;
    head = other.head;
    other.head = temp;

    // Swap the tail pointers
    temp = tail;
    tail = other.tail;
    other.tail = temp;
}

// copy assignment
// Picture& Picture::operator=(const Picture& other) {
//     if (this != &other) {

//         //clear data:
//         ListNode* temp_current = head;
//         while (temp_current != nullptr) {
//             ListNode* next = temp_current->next;
//             delete temp_current->shape; // Use delete to deallocate the shape object
//             delete temp_current; // Deallocate the node
//             temp_current = next;
//         }
//         head = nullptr;
//         tail = nullptr;

//         // Perform deep copy of the linked list
//         ListNode* current = other.head;
//         while (current != nullptr) {
//             add(*(current->shape->clone()));
//             current = current->next;
//         }
//     }
//     return *this;
// }

Picture &Picture::operator=(const Picture& other){
    Picture temp(other);
    swap(temp);
    return *this;
}

// move assignment
Picture& Picture::operator=(Picture&& other) {
    if (this != &other) {
        // Free the current linked list
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* next = current->next;
            delete current->shape;
            delete current;
            current = next;
        }

        // Move the head and tail pointers from 'other' to 'this'
        head = other.head;
        tail = other.tail;

        // Reset 'other' to an empty state
        other.head = nullptr;
        other.tail = nullptr;
    }
    return *this;
}



// adds clone of shape to end of this Picture's linked list.
// Cloning allows us to create any number of shape objects.
// Picture is responsible for deleting cloens when Picture object dies.
void Picture::add(const Shape& shape) {
    ListNode* new_node = new ListNode{shape.clone(), nullptr, nullptr};

    if (head == nullptr) {   //empty doubly linked list.
        head = new_node;
        tail = new_node;
    } else {
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
    }
}


void Picture::print_all(std::ostream& out) const {
    ListNode* current = head;
    while (current != nullptr) {
        current->shape->print(out);
        current->shape->draw(out);
        current = current->next;
    }

}

void Picture::draw_all(std::ostream& out) const {
    ListNode* current = head;
    while (current != nullptr) {
        current->shape->draw(out);
        current = current->next;
    }
}

double Picture::total_area() const {
    ListNode* current = head;
    double total = 0;
    while (current != nullptr) {
        double area = current->shape->area();
        total += area;
        current = current->next;
    }
    return total;
}

Picture::~Picture() {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* next = current->next;
        delete current->shape;  // Delete the shape
        delete current;         // Delete the node itself
        current = next;
    }
}

