#pragma once

#include <vector>


struct Node {
    int data;
    Node* next;
};


class Stack {
  
 public:
  Stack() : top(nullptr) {}


  bool isEmpty();

  void Push(int value);
  int Pop();

 private:
  Node* top;
};

class MinStack {
 public:
  MinStack(): top(nullptr), mintop(nullptr) {}
  void Push(int value);
  int Pop();
  int GetMin();
  bool isEmpty();

 private:
  Node* top;
  Node* mintop;
};
