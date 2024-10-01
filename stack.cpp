#include "stack.h"

//pushin element onto stack
void Stack::push(int value) {
    stack.push_back(value);
}

//popping element from stack
void Stack::pop() {
    if (empty()) {
        throw std::runtime_error("Stack is empty. Cannot pop.");
    }
    stack.pop_back();
}

// is stack empty 
bool Stack::empty() const {
    return stack.empty();
}

// finding the top value of stack
int Stack::top() const {
    if (empty()) {
        throw std::runtime_error("Stack is empty.");
    }
    return stack.back();
}

//calcing average
double Stack::average() const {
    if (empty()) {
        throw runtime_error("Stack is empty. Cannot calculate average.");
    }
    return static_cast<double>(accumulate(stack.begin(), stack.end(), 0)) / stack.size();
}