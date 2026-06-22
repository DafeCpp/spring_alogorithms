#include "stack.hpp"

#include <stdexcept>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (Empty()) throw std::runtime_error("Pop() on empty stack");
  int val = data_.back();
  data_.pop_back();
  return val;
}

int Stack::Top() const {
  if (Empty()) throw std::runtime_error("Top() on empty stack");
  return data_.back();
}

inline bool Stack::Empty() const { return data_.empty(); }

void MinStack::Push(int value) {
  data_.Push(value);
  int value_on_top = (minimum_.Empty()) ? value : minimum_.Top();
  minimum_.Push((value < value_on_top) ? value : value_on_top);
}

int MinStack::Pop() {
  minimum_.Pop();
  return data_.Pop();
}

int MinStack::GetMin() const {
  if (Empty()) throw std::runtime_error("GetMin() on empty stack");
  return minimum_.Top();
}

int MinStack::Top() const { return data_.Top(); }

inline bool MinStack::Empty() const { return data_.Empty(); }