#include "stack.hpp"

void Stack::Push(int value) { stack_.push_back(value); }

int Stack::Pop() {
  auto result = stack_.back();
  stack_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  stack_.push_back(value);
  if (min_stack_.size() == 0 || value < min_stack_.back())
    min_stack_.push_back(value);
  else
    min_stack_.push_back(min_stack_.back());
}

int MinStack::Pop() {
  auto result = stack_.back();
  stack_.pop_back();
  min_stack_.pop_back();
  return result;
}

int MinStack::GetMin() { return min_stack_.back(); }