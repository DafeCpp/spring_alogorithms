#include "stack.hpp"

#include <algorithm>
#include <stdexcept>

// ----------------------------------- STACK -----------------------------------

Stack::Stack(unsigned int reserve) : data_() { data_.reserve(reserve); }

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.size() == 0)
    throw std::runtime_error("trying to pop from empty stack");
  auto result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}

int Stack::GetTop() {
  if (data_.size() == 0)
    throw std::runtime_error("trying get something from empty stack");
  return data_[data_.size() - 1];
}

bool Stack::IsEmpy() { return data_.size() == 0; }

// --------------------------------- MIN STACK ---------------------------------

MinStack::MinStack(unsigned int reserve) : data_(reserve), min_(reserve) {}

void MinStack::Push(int value) {
  data_.Push(value);

  if (min_.IsEmpy())
    min_.Push(value);
  else
    min_.Push(std::min(min_.GetTop(), value));
}

int MinStack::Pop() {
  min_.Pop();
  return data_.Pop();
}

int MinStack::GetMin() { return min_.GetTop(); }
