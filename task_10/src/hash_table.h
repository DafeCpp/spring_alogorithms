#pragma once

#include <utility>
#include <vector>

class HashTable {
 public:
  HashTable();

  void Insert(int key, int value);
  int Get(int key) const;
  void Remove(int key);
  bool Contains(int key) const;

 private:
  std::vector<std::vector<std::pair<int, int>>> buckets_;
  int size_ = 0;

  size_t GetBucketIndex(int key) const;
  void RehashIfNeeded();
};
