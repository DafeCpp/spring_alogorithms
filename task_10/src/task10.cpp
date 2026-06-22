#include "task10.hpp"

#include <cmath>

HashTable::HashTable() {
  sz = 10007;
  table.resize(sz);
}

int HashTable::hash(int key) {
  int h = key % sz;
  if (h < 0) h += sz;
  return h;
}

void HashTable::Insert(int key, int value) {
  int h = hash(key);
  for (size_t i = 0; i < table[h].size(); i++) {
    if (table[h][i].key == key) {
      table[h][i].val = value;
      return;
    }
  }
  Node n;
  n.key = key;
  n.val = value;
  table[h].push_back(n);
}

int HashTable::Get(int key) {
  int h = hash(key);
  for (size_t i = 0; i < table[h].size(); i++) {
    if (table[h][i].key == key) {
      return table[h][i].val;
    }
  }
  return -1;
}

void HashTable::Remove(int key) {
  int h = hash(key);
  for (size_t i = 0; i < table[h].size(); i++) {
    if (table[h][i].key == key) {
      table[h].erase(table[h].begin() + i);
      return;
    }
  }
}

bool HashTable::Contains(int key) {
  int h = hash(key);
  for (size_t i = 0; i < table[h].size(); i++) {
    if (table[h][i].key == key) {
      return true;
    }
  }
  return false;
}
