#include "stack.hpp"
#include <cassert>

int main() {
    Stack s;
    assert(s.empty());
    s.push(1);
    s.push(2);
    assert(s.size() == 2);
    assert(s.top() == 2);
    s.pop();
    assert(s.top() == 1);
    s.pop();
    assert(s.empty());

    MinStack ms;
    ms.push(3);
    ms.push(2);
    ms.push(5);
    assert(ms.getMin() == 2);
    ms.push(1);
    assert(ms.getMin() == 1);
    ms.pop();
    assert(ms.getMin() == 2);
    ms.pop();
    assert(ms.top() == 2);
    assert(ms.getMin() == 2);
    ms.push(2);
    ms.push(0);
    ms.pop();
    assert(ms.getMin() == 2);

    return 0;
}