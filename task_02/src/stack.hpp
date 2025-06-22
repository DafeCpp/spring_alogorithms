#ifndef STACK_HPP
#define STACK_HPP

#include <stdexcept>
#include <vector>

template <typename T>
class Stack {
 private:
  std::vector<T> data;

 public:
  void Push(T value) { data.push_back(value); }

  void Pop() {
    if (IsEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    data.pop_back();
  }

  T Top() {
    if (IsEmpty()) {
      throw std::runtime_error("Stack is empty");
    }
    return data.back();
  }

  bool IsEmpty() { return data.empty(); }
};

template <typename T>
class MinStack {
 private:
  std::vector<T> stack;
  std::vector<T> minStack;

 public:
  void Push(T value) {
    stack.push_back(value);
    if (minStack.empty() || value <= minStack.back()) {
      minStack.push_back(value);
    }
  }

  void Pop() {
    if (stack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    if (stack.back() == minStack.back()) {
      minStack.pop_back();
    }
    stack.pop_back();
  }

  T Top() {
    if (stack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    return stack.back();
  }

  T FindMin() {
    if (minStack.empty()) {
      throw std::runtime_error("Stack is empty");
    }
    return minStack.back();
  }

  bool IsEmpty() { return stack.empty(); }
};

#endif  // STACK_HPP