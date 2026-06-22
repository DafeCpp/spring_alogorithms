#include "HashTable.h"

#include <list>
#include <stdexcept>
#include <vector>

void HashTable::Insert(int key, int value) {
  int index = GetIndexBucket(key);

  for (std::pair<int, int>& pair : buckets[index]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  buckets[index].emplace_back(key, value);
  num_elements++;
}

int HashTable::Get(int key) {
  int index = GetIndexBucket(key);

  for (std::pair<int, int>& pair : buckets[index]) {
    if (pair.first == key) {
      return pair.second;
    }
  }
  throw std::out_of_range("Ключа нет");
}

void HashTable::Remove(int key) {
  int index = GetIndexBucket(key);

  std::list<std::pair<int, int>>& chain = buckets[index];
  for (auto it = chain.begin(); it != chain.end(); ++it) {
    if (it->first == key) {
      chain.erase(it);
      num_elements--;
      return;
    }
  }
}

bool HashTable::Contains(int key) {
  int index = GetIndexBucket(key);

  for (std::pair<int, int>& pair : buckets[index]) {
    if (pair.first == key) {
      return true;
    }
  }
  return false;
}