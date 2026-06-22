#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  int result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) {
  int current_min =
      data_.empty() ? value : std::min(value, data_.back().second);
  data_.push_back({value, current_min});
}

int MinStack::Pop() {
  int result = data_.back().first;
  data_.pop_back();
  return result;
}

int MinStack::GetMin() { return data_.back().second; }