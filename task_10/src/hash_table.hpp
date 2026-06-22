#pragma once

#include <cstddef>
#include <vector>

class HashTable {
 public:
  void Insert(int key, int value);
  int Get(int key) const;
  void Remove(int key);
  bool Contains(int key) const;

 private:
  enum class State { kEmpty, kOccupied, kDeleted };

  struct Entry {
    int key = 0;
    int value = 0;
    State state = State::kEmpty;
  };

  static constexpr double kMaxLoadFactor = 0.65;

  std::size_t Hash(int key) const;
  std::size_t FindSlot(int key) const;
  void Rehash(std::size_t new_capacity);

  std::vector<Entry> table_ = std::vector<Entry>(8);
  std::size_t size_ = 0;
};

using IntHashTable = HashTable;
