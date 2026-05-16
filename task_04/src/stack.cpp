#include "stack.hpp"

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
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
  const int result = data_.back();
  data_.pop_back();
  if (result == mins_.back()) {
    mins_.pop_back();
  }
  return result;
}

int MinStack::GetMin() const { return mins_.back(); }
