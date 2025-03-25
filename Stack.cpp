#include "Stack.h"
#include <numeric>

bool IntegerStack::is_empty() const {
    return stack_data.empty();
}

void IntegerStack::push(int value) {
    stack_data.push_back(value);
}

void IntegerStack::pop() {
    if (is_empty()) {
        throw std::runtime_error("Cannot pop from an empty stack");
    }
    stack_data.pop_back();
}

int IntegerStack::top() const {
    if (is_empty()) {
        throw std::runtime_error("Stack is empty");
    }
    return stack_data.back();
}

double IntegerStack::get_average() const {
    if (is_empty()) {
        throw std::runtime_error("Cannot calculate average of an empty stack");
    }

    double sum = std::accumulate(stack_data.begin(), stack_data.end(), 0.0);
    return sum / stack_data.size();
}

size_t IntegerStack::size() const {
    return stack_data.size();
}