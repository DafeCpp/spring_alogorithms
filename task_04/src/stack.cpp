#include "stack.hpp"

#include <stdexcept>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) {
    throw std::underflow_error("Stack is empty");
  }
  const int result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  data_.push_back(value);
  if (mins_.empty() || value <= mins_.back()) {
    mins_.push_back(value);
  }
}

int MinStack::Pop() {
  if (data_.empty()) {
    throw std::underflow_error("MinStack is empty");
  }
  const int result = data_.back();
  data_.pop_back();
  if (result == mins_.back()) {
    mins_.pop_back();
  }
  return result;
}

int MinStack::GetMin() const {
  if (mins_.empty()) {
    throw std::underflow_error("MinStack is empty");
  }
  return mins_.back();
}
