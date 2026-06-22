#include "stack.hpp"
#include <algorithm>
#include <stdexcept>
void Stack::Push(int value){
  Node *new_node;
  new_node = new Node();
  new_node->data_ = value;
  new_node->next = top;
  top = new_node;
}

int Stack::Pop(){
  if (top == nullptr) {
    throw std::runtime_error("Stack is empty");
  }
  else {
   Node *temp = top;
   top = top->next;
   int res = temp->data_;
   delete temp; 
   return res;
  }
}

void MinStack::Push(int value){
  Node *new_node;
  new_node = new Node();
  new_node->data_ = value;
  if (top == nullptr){
    new_node->min = value;
  }
  else {
    new_node->min = std::min(value, top->min);
  }
  new_node->next = top;
  top = new_node;
}

int MinStack::Pop(){
  if (top == nullptr) {
    throw std::runtime_error("Stack is empty");
  }
   Node *temp = top;
   top = top->next;
   int res = temp->data_;
   delete temp; 
   return res;
}

int MinStack::GetMin(){
  if (top == nullptr) {
    throw std::runtime_error("Stack is empty");
  }
    return top->min;

}

Stack::~Stack() {
    while (top != nullptr) {
        Node *temp = top;  
        top = top->next;    
        delete temp;        
    }
}
MinStack::~MinStack() {
    while (top != nullptr) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}