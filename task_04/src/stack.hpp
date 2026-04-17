#pragma once

#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin() const;

 private:
  std::vector<int> data_;
  std::vector<int> mins_;
};
