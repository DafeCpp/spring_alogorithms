#include "stack.hpp"

// template <typename T>
// void Stack<T>::Push(T k) {
//   _data.push_back(k);
// }

// template <typename T>
// T Stack<T>::Pop() {
//   int pop_val{_data.back()};
//   _data.pop_back();
//   return pop_val;
// }

// #include "stack.hpp"

// #include <algorithm>

// void Stack::Push(int value) { data_.push(value); }

// int Stack::Pop() {
//   auto result = data_.top();
//   data_.pop();
//   return result;
// }

// void MinStack::Push(int value) { data_.push_back(value); }

// int MinStack::Pop() {
//   auto result = data_.back();
//   data_.pop_back();
//   return result;
// }

// int MinStack::GetMin() { return *std::min_element(data_.begin(),
// data_.end()); }