#include <stdexcept>

class Stack {
private:
    int* arr;
    size_t capacity;
    size_t _size;
    void resize(size_t newCapacity);
public:
    Stack();
    ~Stack();
    void push(int value);
    void pop();
    int top() const;
    bool empty() const;
    size_t size() const;
};

class MinStack {
private:
    Stack dataStack;
    Stack minStack;
public:
    void push(int value);
    void pop();
    int top() const;
    int getMin() const;
    bool empty() const;
    size_t size() const;
};