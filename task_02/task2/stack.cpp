#include "stack.hpp"

Stack::Stack() : capacity(10), _size(0) {
    arr = new int[capacity];
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::resize(size_t newCapacity) {
    int* newArr = new int[newCapacity];
    for (size_t i = 0; i < _size; ++i) {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    capacity = newCapacity;
}

void Stack::push(int value) {
    if (_size == capacity) {
        resize(capacity * 2);
    }
    arr[_size++] = value;
}

void Stack::pop() {
    if (empty()) {
        throw std::out_of_range("empty");
    }
    --_size;
}

int Stack::top() const {
    if (empty()) {
        throw std::out_of_range("empty");
    }
    return arr[_size - 1];
}

bool Stack::empty() const {
    return _size == 0;
}

size_t Stack::size() const {
    return _size;
}

void MinStack::push(int value) {
    dataStack.push(value);
    if (minStack.empty() || value <= minStack.top()) {
        minStack.push(value);
    }
}

void MinStack::pop() {
    if (dataStack.empty()) {
        throw std::out_of_range("empty");
    }
    if (dataStack.top() == minStack.top()) {
        minStack.pop();
    }
    dataStack.pop();
}

int MinStack::top() const {
    return dataStack.top();
}

int MinStack::getMin() const {
    if (minStack.empty()) {
        throw std::out_of_range("empty");
    }
    return minStack.top();
}

bool MinStack::empty() const {
    return dataStack.empty();
}

size_t MinStack::size() const {
    return dataStack.size();
}