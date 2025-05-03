#pragma once

#include <algorithm>
#include <concepts>

struct EmptyStackError : std::exception {
  using std::exception::exception;
};

template <typename T>
struct Node {
  T value;
  Node<T>* prev = nullptr;
};

template <typename T>
class Stack {
 public:
  Stack(){};
  void Push(T value);
  T Pop();

 private:
  Node<T>* head = nullptr;
};

template <typename T>
  requires(std::totally_ordered<T>)
class MinStack {
 public:
  MinStack(){};
  void Push(T value);
  T Pop();
  T GetMin();

 private:
  Node<T>* head = nullptr;
  Node<T>* head_min = nullptr;
};

template <typename T>
void Stack<T>::Push(T value) {
  if (!head) {
    head = new Node<T>;
    head->value = value;
  } else {
    Node<T>* new_head = new Node<T>;
    new_head->prev = head;
    new_head->value = value;
    head = new_head;
  }
}

template <typename T>
T Stack<T>::Pop() {
  if (head == nullptr) {
    throw EmptyStackError();
  }
  Node<T>* del_node = head;
  T val = head->value;
  head = head->prev;
  delete del_node;
  return val;
}

template <typename T>
  requires(std::totally_ordered<T>)
void MinStack<T>::Push(T value) {
  if (!head) {
    head = new Node<T>;
    head->value = value;
    head_min = new Node<T>;
    head_min->value = value;
  } else {
    Node<T>* new_head = new Node<T>;
    Node<T>* new_head_min = new Node<T>;
    new_head->prev = head;
    new_head->value = value;
    new_head_min->prev = head_min;
    new_head_min->value = std::min(head_min->value, value);
    head = new_head;
    head_min = new_head_min;
  }
}

template <typename T>
  requires(std::totally_ordered<T>)
T MinStack<T>::Pop() {
  if (head == nullptr) {
    throw EmptyStackError();
  }
  Node<T>* del_node = head;
  Node<T>* del_node_min = head_min;
  T val = head->value;
  head = head->prev;
  head_min = head_min->prev;
  delete del_node;
  delete del_node_min;
  return val;
}

template <typename T>
  requires(std::totally_ordered<T>)
T MinStack<T>::GetMin() {
  if (head_min == nullptr) {
    throw EmptyStackError();
  }
  return head_min->value;
}