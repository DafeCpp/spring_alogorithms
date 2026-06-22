#include "stack.hpp"

void Stack::Push(int value) { 
  data_.push_back(value); 
}

int Stack::Pop() {
  if (data_.empty()) {
    return -1;
  }
  auto result = data_.back();
  data_.pop_back();
  return result;
}

bool Stack::Empty() const {
  return data_.empty();
}

void MinStack::Push(int value) {
  data_.push_back(value);
  
  if (min_data_.empty() || value <= min_data_.back()) {
    min_data_.push_back(value);
  }
}

int MinStack::Pop() {
  if (data_.empty()) {
    return -1;
  }
  
  auto result = data_.back();
  data_.pop_back();
  
  if (!min_data_.empty() && result == min_data_.back()) {
    min_data_.pop_back();
  }
  
  return result;
}

int MinStack::GetMin() {
  if (min_data_.empty()) {
    return -1;
  }
  return min_data_.back();
}

bool MinStack::Empty() const {
  return data_.empty();
}