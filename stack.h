#ifndef STACK_H
#define STACK_H

#include <vector>

class Stack {
private:
    std::vector<int> stack; // Vector to store stack elements

public:
    // Check if stack empty
    bool empty() const;

    // Push element onto stack
    void push(int value);

    // Pop element off stack
    void pop();

    // Get top element of stack
    int top() const;

    // Get average value of stack
    double average() const;

    // Display stack elements
    void display() const;
};

#endif // STACK_H
