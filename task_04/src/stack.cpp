#include "stack.hpp"

#include <stdexcept>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) {
    throw std::out_of_range("stack is empty");
  }
  const int result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  data_.push_back(value);
  if (minimums_.empty() || value <= minimums_.back()) {
    minimums_.push_back(value);
  }
}

int MinStack::Pop() {
  if (data_.empty()) {
    throw std::out_of_range("stack is empty");
  }
  const int result = data_.back();
  data_.pop_back();
  if (result == minimums_.back()) {
    minimums_.pop_back();
  }
  return result;
}

int MinStack::GetMin() {
  if (minimums_.empty()) {
    throw std::out_of_range("stack is empty");
  }
  return minimums_.back();
}
