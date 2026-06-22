#include "task10.hpp"

#include <stdexcept>
#include <utility>

HashTable::HashTable(size_t initial_capacity)
    : size(0), capacity(initial_capacity) {
  table.resize(capacity);
}

size_t HashTable::get_hash_index(int key) const {
  return std::hash<int>{}(key) % capacity;
}

void HashTable::Resize() {
  size_t old_capacity = capacity;
  capacity *= 2;
  std::vector<std::list<KeyValue>> new_table(capacity);

  for (size_t i = 0; i < old_capacity; ++i) {
    for (const auto& kv : table[i]) {
      size_t new_index = get_hash_index(kv.key);
      new_table[new_index].push_back(kv);
    }
  }

  table = std::move(new_table);
}

void HashTable::Insert(int key, int value) {
  if (static_cast<double>(size) / capacity >= hashing_threshold) {
    Resize();
  }

  size_t index = get_hash_index(key);

  for (auto& kv : table[index]) {
    if (kv.key == key) {
      kv.value = value;
      return;
    }
  }

  table[index].push_back({key, value});
  size++;
}

int HashTable::Get(int key) const {
  size_t index = get_hash_index(key);

  for (const auto& kv : table[index]) {
    if (kv.key == key) {
      return kv.value;
    }
  }

  throw std::out_of_range("Key not found");
}

void HashTable::Remove(int key) {
  size_t index = get_hash_index(key);
  auto& cell_list = table[index];

  for (auto it = cell_list.begin(); it != cell_list.end(); ++it) {
    if (it->key == key) {
      cell_list.erase(it);
      size--;
      return;
    }
  }
}

bool HashTable::Contains(int key) const {
  size_t index = get_hash_index(key);

  for (const auto& kv : table[index]) {
    if (kv.key == key) {
      return true;
    }
  }
  return false;
}
