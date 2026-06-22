#include "min_stack.hpp"

MinStack::MinStack() {
    head = nullptr;
}

void MinStack::Push(int value) {
    MinNode *node = new MinNode();
    node->value = value;
    node->min = std::min(value, GetMin());
    node->prev = head;
    head = node;
}

int MinStack::Pop() {
    if (!head) {
        return -1;
    }
    int value = head->value;
    MinNode *temp = head->prev;
    delete head;
    head = temp;
    return value;
}

int MinStack::GetMin() {
    if (!head) {
        return 1e9;
    }
    return head->min;
}

MinStack::~MinStack() {
    MinNode* tmp = head;
    while (tmp) {
        MinNode* pr = tmp->prev;
        delete tmp;
        tmp = pr;
    }
}