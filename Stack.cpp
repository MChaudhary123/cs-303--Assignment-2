#include "Stack.h"
#include <numeric>

// Check if the stack is empty
// Time complexity: O(1)
// Returns true if no elements are in the stack, false otherwise
bool IntegerStack::is_empty() const {
    // Utilizes vector's built-in empty() method to check stack contents
    return stack_data.empty();
}

// Add a new element to the top of the stack
// Time complexity: O(1) amortized
// @param value: Integer to be added to the stack
void IntegerStack::push(int value) {
    // Uses vector's push_back() to add element to the end (top of stack)
    stack_data.push_back(value);
}

// Remove the top element from the stack
// Time complexity: O(1)
// Throws runtime_error if stack is empty
void IntegerStack::pop() {
    // Check if stack is empty before attempting to remove an element
    if (is_empty()) {
        throw std::runtime_error("Cannot pop from an empty stack");
    }
    // Remove the last element (top of the stack)
    stack_data.pop_back();
}

// Retrieve the top element of the stack without removing it
// Time complexity: O(1)
// @return: Reference to the top element
// Throws runtime_error if stack is empty
int IntegerStack::top() const {
    // Ensure stack is not empty before accessing top element
    if (is_empty()) {
        throw std::runtime_error("Stack is empty");
    }
    // Return the last element (top of the stack)
    return stack_data.back();
}

// Calculate the average of all elements in the stack
// Time complexity: O(n), where n is the number of elements
// @return: Average of stack elements as a double
// Throws runtime_error if stack is empty
double IntegerStack::get_average() const {
    // Check if stack is empty before calculating average
    if (is_empty()) {
        throw std::runtime_error("Cannot calculate average of an empty stack");
    }
    
    // Use std::accumulate to sum all elements
    // 0.0 ensures floating-point division
    double sum = std::accumulate(stack_data.begin(), stack_data.end(), 0.0);
    
    // Return average by dividing sum by number of elements
    return sum / stack_data.size();
}

// Get the current number of elements in the stack
// Time complexity: O(1)
// @return: Number of elements in the stack
size_t IntegerStack::size() const {
    // Directly returns the size of the underlying vector
    return stack_data.size();
}
