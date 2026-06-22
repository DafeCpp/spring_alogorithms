#include "stack.hpp"

#include <stdexcept>

Stack::~Stack() {
  while (top != nullptr) {
    Node* temp = top;
    top = top->next;
    delete temp;
  }
}

void Stack::Push(int value) {
  Node* newNode = new Node();
  newNode->data = value;
  newNode->next = top;
  top = newNode;
}

int Stack::Pop() {
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty");
  }
  Node* temp = top;
  int poppedValue = temp->data;
  top = top->next;
  delete temp;
  return poppedValue;
}
bool Stack::isEmpty() { return top == nullptr; }

void MinStack::Push(int value) {
  Node* newNode = new Node();
  Node* minNode = new Node();
  newNode->data = value;
  newNode->next = top;
  minNode->data = value;
  minNode->next = mintop;
  top = newNode;
  if (mintop == nullptr) {
    mintop = minNode;
  } else {
    if (mintop->data >= value) {
      mintop = minNode;
    } else {
      delete minNode;
    }
  }
}

int MinStack::Pop() {
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty");
  }
  Node* temp = top;
  Node* mintemp = mintop;
  int poppedValue = temp->data;
  if (mintop != nullptr && poppedValue == mintemp->data) {
    mintop = mintemp->next;
    delete mintemp;
  }
  top = top->next;
  delete temp;
  return poppedValue;
}
bool MinStack::isEmpty() { return top == nullptr; }
int MinStack::GetMin() {
  if (isEmpty()) {
    throw std::runtime_error("Stack is empty");
  }
  return mintop->data;
}

MinStack::~MinStack() {
  while (top != nullptr) {
    Node* temp = top;
    top = top->next;
    delete temp;
  }
  while (mintop != nullptr) {
    Node* temp = mintop;
    mintop = mintop->next;
    delete temp;
  }
}