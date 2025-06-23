#include "queue.hpp"

MinQueue::MinQueue()
    : data_queue(), min_val_queue(), min_pos_queue(), already_pushed(0) {}

void MinQueue::Push(int value) {
  data_queue.push(value);

  // front -->  newer  --> back
  // front --> greater --> back
  // delete everything that is incorrect)
  while (min_val_queue.size() > 0 && min_val_queue.back() > value) {
    min_val_queue.pop_back();
    min_pos_queue.pop_back();
  }
  min_val_queue.push_back(value);
  min_pos_queue.push_back(already_pushed++);
}

int MinQueue::Pull() {
  int pull_pos = already_pushed - data_queue.size();
  if (min_pos_queue.front() == pull_pos) {
    min_val_queue.pop_front();
    min_pos_queue.pop_front();
  }
  int res = data_queue.front();
  data_queue.pop();
  return res;
}

int MinQueue::Front() { return data_queue.front(); }
int MinQueue::Back() { return data_queue.back(); }

int MinQueue::GetMin() { return min_val_queue.front(); }
int MinQueue::GetMinPos() { return min_pos_queue.front(); }

bool MinQueue::IsEmpty() { return data_queue.empty(); }
