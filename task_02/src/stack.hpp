#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  Stack(unsigned int reserve = 0);
  void Push(int value);
  int Pop();
  // some handy extensions
  int GetTop();  // sometimes called Peek but GetTop is more self-describing
  bool IsEmpy();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  MinStack(unsigned int reserve = 0);
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Stack data_;
  Stack min_;
};
