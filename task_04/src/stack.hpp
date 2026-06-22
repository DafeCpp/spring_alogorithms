#pragma once

#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int Top() const;
  bool Empty() const;

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin() const;
  int Top() const;
  bool Empty() const;

 private:
  Stack data_;
  Stack minimum_;
};
