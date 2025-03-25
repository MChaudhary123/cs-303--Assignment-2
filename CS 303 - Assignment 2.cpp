// CS 303 - Assignment 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"
#include "stack.h"

void demonstrate_linked_list() {
    std::cout << "Demonstrating Single Linked List:\n";
    Single_Linked_List<int> list;

    // Test push_front and push_back
    list.push_front(10);
    list.push_back(20);
    list.push_front(5);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;

    // Test insert
    list.insert(2, 15);

    // Test find
    std::cout << "Position of 15: " << list.find(15) << std::endl;

    // Test remove
    list.remove(1);
}

void demonstrate_stack() {
    std::cout << "\nDemonstrating Integer Stack:\n";
    IntegerStack stack;

    // Check if stack is empty
    std::cout << "Is stack empty? " << (stack.is_empty() ? "Yes" : "No") << std::endl;

    // Push elements
    stack.push(10);
    stack.push(20);
    stack.push(30);

    // Size and top
    std::cout << "Stack size: " << stack.size() << std::endl;
    std::cout << "Top element: " << stack.top() << std::endl;

    // Calculate average
    std::cout << "Average: " << stack.get_average() << std::endl;

    // Pop an element
    stack.pop();
    std::cout << "After pop, top is now: " << stack.top() << std::endl;
}

int main() {
    demonstrate_linked_list();
    demonstrate_stack();
    return 0;
}

