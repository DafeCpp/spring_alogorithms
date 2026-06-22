#ifndef TASK10_HPP
#define TASK10_HPP

#include <vector>

struct Node {
  int key;
  int val;
};

class HashTable {
 private:
  int sz;
  std::vector<std::vector<Node>> table;
  int hash(int key);

 public:
  HashTable();
  void Insert(int key, int value);
  int Get(int key);
  void Remove(int key);
  bool Contains(int key);
};

#endif
