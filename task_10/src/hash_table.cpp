#include "hash_table.hpp"

#include <functional>

HashTable::HashTable(size_t size) : data(size) {}

void HashTable::Insert(int key, int value) {
  int hash = std::hash<int>{}(key) % data.size();
  Node n{key, value};

  auto& values = data[hash];
  for (auto it = values.begin(); it != values.end(); ++it) {
    if (it->key == key) {
      it->value = value;
      return;
    }
  }
  values.push_front(n);
}

void HashTable::Remove(int key) {
  int hash = std::hash<int>{}(key) % data.size();
  auto& values = data[hash];

  auto previous = values.before_begin();

  for (auto current = values.begin(); current != values.end(); ++current) {
    if (current->key == key) {
      values.erase_after(previous);
      return;
    }
    previous = current;
  }
}

std::optional<int> HashTable::Get(int key) {
  int hash = std::hash<int>{}(key) % data.size();
  auto& values = data[hash];
  for (const auto& node : values) {
    if (node.key == key) return node.value;
  }
  return {};
}

bool HashTable::Contains(int key) {
  int hash = std::hash<int>{}(key) % data.size();
  auto& values = data[hash];
  for (const auto& node : values) {
    if (node.key == key) return true;
  }
  return false;
}