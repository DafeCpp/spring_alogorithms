#pragma once

#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool Empty() const;

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  bool Empty() const;

 private:
  std::vector<int> data_;
  std::vector<int> min_data_;
};