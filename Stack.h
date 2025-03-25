#pragma once
#ifndef STACK_IMPLEMENTATION_H
#define STACK_IMPLEMENTATION_H

#include <vector>
#include <stdexcept>

class IntegerStack {
private:
    std::vector<int> stack_data;

public:
    // Check if stack is empty
    bool is_empty() const;

    // Push an element onto the stack
    void push(int value);

    // Pop an element from the stack
    void pop();

    // Get the top element
    int top() const;

    // Calculate average of stack elements
    double get_average() const;

    // Get current stack size
    size_t size() const;
};

#endif // STACK_IMPLEMENTATION_H