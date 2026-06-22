#pragma once

#include <vector>

class HashTable {
 public:
  HashTable();
  HashTable(int capacity);

  void Insert(int key, int value);
  int Get(int key) const;
  void Remove(int key);
  bool Contains(int key) const;
  int Size() const;
  bool Empty() const;

 private:
  using Bucket = std::vector<std::pair<int, int>>;

  std::vector<Bucket> buckets_;
  int size_;

  static const int kDefaultCapacity;
  static const double kMaxLoadFactor;
  static const unsigned int kHashPrime;

  int BucketIndex(int key, int capacity) const;
  void Rehash();
};