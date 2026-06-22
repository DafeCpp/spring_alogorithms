#include "stack.hpp"

Stack::Stack() {
    head = nullptr;
}

void Stack::Push(int value) {
    Node *node = new Node();
    node->value = value;
    node->prev = head;
    head = node;
}

int Stack::Pop() {
    if (!head) {
        return -1;
    }
    int value = head->value;
    Node *temp = head->prev;
    delete head;
    head = temp;
    return value;
}

Stack::~Stack() {
    Node* tmp = head;
    while (tmp) {
        Node* pr = tmp->prev;
        delete tmp;
        tmp = pr;
    }
}
