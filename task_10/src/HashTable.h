#pragma once
#include <list>
#include <vector>

class HashTable {
 private:
  int num_elements;
  std::vector<std::list<std::pair<int, int>>> buckets;

  int GetIndexBucket(const int key) const {
    return std::hash<int>{}(key) % buckets.size();
  }

 public:
  HashTable(int size = 10) : buckets(size), num_elements(0) {}

  void Insert(int key, int value);
  int Get(int key);
  void Remove(int key);
  bool Contains(int key);
};