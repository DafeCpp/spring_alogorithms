#include "stack.hpp"

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  data_.push_back(value);
  if (mins_.empty() || value < mins_.back())
    mins_.push_back(value);
  else
    mins_.push_back(mins_.back());
}

int MinStack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  mins_.pop_back();
  return result;
}

int MinStack::GetMin() { return mins_.back(); }