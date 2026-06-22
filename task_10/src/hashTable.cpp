#include "hashTable.hpp"

#include <stdexcept>

unsigned int HashTable::hashing(int key) const {
  unsigned int x = static_cast<unsigned int>(key);
  return x * HashNum;
}

void HashTable::rehash() {
  std::vector<HashEntry> oldTable = table;
  M++;
  size_t new_capacity = 1ULL << M;
  table.assign(new_capacity, HashEntry());
  num_elements = 0;
  num_deleted = 0;
  for (const auto& entry : oldTable) {
    if (entry.state == occupied) {
      Insert(entry.key, entry.value);
    }
  }
}

HashTable::HashTable(unsigned short init_M)
    : num_elements(0), num_deleted(0), M(init_M) {
  size_t capacity = 1ULL << M;
  table.assign(capacity, HashEntry());
}

void HashTable::Insert(int key, int value) {
  size_t capacity = 1ULL << M;

  if (num_elements + num_deleted >= capacity * 0.66) {
    rehash();
    capacity = 1ULL << M;
  }

  unsigned int hash = hashing(key);
  size_t index = hash >> (32 - M);
  unsigned int python_fix = hash;
  size_t insert_idx = static_cast<size_t>(-1);

  while (table[index].state != empty) {
    if (table[index].state == occupied && table[index].key == key) {
      table[index].value = value;
      return;
    }
    if (table[index].state == deleted &&
        insert_idx == static_cast<size_t>(-1)) {
      insert_idx = index;
    }

    index = (5 * index + 1 + python_fix) & (capacity - 1);
    python_fix >>= 5;
  }

  if (insert_idx != static_cast<size_t>(-1)) {
    index = insert_idx;
    num_deleted--;
  }

  table[index].key = key;
  table[index].value = value;
  table[index].state = occupied;
  num_elements++;
}

int HashTable::Get(int key) {
  size_t capacity = 1ULL << M;
  unsigned int hash = hashing(key);
  size_t index = hash >> (32 - M);
  unsigned int python_fix = hash;

  while (table[index].state != empty) {
    if (table[index].state == occupied && table[index].key == key) {
      return table[index].value;
    }
    index = (5 * index + 1 + python_fix) & (capacity - 1);
    python_fix >>= 5;
  }
  throw std::runtime_error("no key");
}
bool HashTable::Contains(int key) {
  size_t capacity = 1ULL << M;
  unsigned int hash = hashing(key);
  size_t index = hash >> (32 - M);
  unsigned int python_fix = hash;
  while (table[index].state != empty) {
    if (table[index].state == occupied && table[index].key == key) {
      return true;
    }
    index = (5 * index + 1 + python_fix) & (capacity - 1);
    python_fix >>= 5;
  }
  return false;
}

void HashTable::Remove(int key) {
  size_t capacity = 1ULL << M;
  unsigned int hash = hashing(key);
  size_t index = hash >> (32 - M);
  unsigned int python_fix = hash;
  while (table[index].state != empty) {
    if (table[index].state == occupied && table[index].key == key) {
      table[index].state = deleted;
      num_elements--;
      num_deleted++;
      return;
    }
    index = (5 * index + 1 + python_fix) & (capacity - 1);
    python_fix >>= 5;
  }
}