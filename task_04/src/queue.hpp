#pragma once
#include <deque>
#include <queue>

class MinQueue {
 private:
  std::queue<int> data_queue;
  std::deque<int> min_val_queue;
  std::deque<int> min_pos_queue;
  unsigned int already_pushed;

 public:
  MinQueue();
  void Push(int value);
  int Pull();
  int Front();
  int Back();
  int GetMin();
  int GetMinPos();
  bool IsEmpty();
};
