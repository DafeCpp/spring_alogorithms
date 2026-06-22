#pragma once

#include <cstddef>
#include <list>
#include <vector>

class HashTable {
 private:
  struct KeyValue {
    int key;
    int value;
  };

  std::vector<std::list<KeyValue>> table;
  size_t size;
  size_t capacity;
  const double hashing_threshold = 0.75;

  size_t get_hash_index(int key) const;
  void Resize();

 public:
  HashTable(size_t initial_capacity = 16);

  void Insert(int key, int value);
  int Get(int key) const;
  void Remove(int key);
  bool Contains(int key) const;
};
