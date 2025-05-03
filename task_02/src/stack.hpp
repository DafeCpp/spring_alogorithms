#pragma once
#include <vector>

struct Stack {
  std::vector<int> arr;

  void push(int element);
  void pop();
  int peek();
  void display();
  int min();
};