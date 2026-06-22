#pragma once

struct Stack{
  public:
    Stack(){}
    ~Stack();
    void Push(int value);
    int Pop();
  private:
    struct Node{
      int data_;
      Node *next;
    };
    Node *top = nullptr;

};

struct MinStack{
  public:
    MinStack(){}
    ~MinStack();
    void Push(int value);
    int Pop();
    int GetMin();
  private:
    struct Node{
      int data_;
      int min;
      Node *next;
    };
    Node *top = nullptr;
};

