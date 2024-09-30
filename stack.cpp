#include "stack.h"
#include <iostream>
#include <vector>
#include <numeric>  // For std::accumulate

// Check if stack is empty
bool Stack::empty() const {
    return stack.empty();
}

// Push element onto stack
void Stack::push(int value) {
    stack.push_back(value);
}

// Pop element off stack
void Stack::pop() {
    if (!empty()) {
        stack.pop_back();
    } else {
        std::cout << "Stack is empty, cannot pop an element.\n";
    }
}

// Get top element off stack
int Stack::top() const {
    if (!empty()) {
        return stack.back();
    } else {
        std::cout << "Stack is empty, no top element.\n";
        return -1; // Return -1 if stack is empty
    }
}

// Get average value of stack
double Stack::average() const {
    if (empty()) {
        std::cout << "Stack is empty, cannot compute average.\n";
        return 0;
    }

    double sum = std::accumulate(stack.begin(), stack.end(), 0.0);
    return sum / stack.size();
}

// Display stack elements
void Stack::display() const {
    if (empty()) {
        std::cout << "Stack is empty.\n";
    } else {
        std::cout << "Stack elements: ";
        for (int val : stack) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}
