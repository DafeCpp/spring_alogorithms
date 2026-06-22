#pragma once

#include <vector>

const unsigned int HashNum = 2654435769U;

enum State { empty, occupied, deleted };

struct HashEntry {
  int key;
  int value;
  State state;

  HashEntry() : state(empty) {}
};

class HashTable {
 private:
  std::vector<HashEntry> table;
  size_t num_elements;
  size_t num_deleted;
  unsigned short M;

  unsigned int hashing(int key) const;
  void rehash();

 public:
  HashTable(unsigned short init_M = 4);

  void Insert(int key, int value);
  int Get(int key);
  bool Contains(int key);
  void Remove(int key);
};