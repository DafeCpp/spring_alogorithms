#pragma once

#include <iostream>
#include <list>
#include <optional>
#include <string>
#include <vector>

template <typename T>
class HashTable {
 private:
  std::vector<std::list<std::pair<std::string, T>>> table;
  int capacity;
  int size;

  int getIndex(const std::string& key) const {
    return std::hash<std::string>{}(key) % capacity;
  }

  void rehash() {
    int old_capacity = capacity;
    capacity *= 2;
    std::vector<std::list<std::pair<std::string, T>>> new_table(capacity);

    for (const auto& bucket : table) {
      for (const auto& entry : bucket) {
        int idx = std::hash<std::string>{}(entry.first) % capacity;
        new_table[idx].emplace_back(entry.first, entry.second);
      }
    }

    table = std::move(new_table);
  }

  void checkLoadFactorAndRehash() {
    if (size > capacity / 2) {
      rehash();
    }
  }

 public:
  HashTable(int init_capacity = 8) : capacity(init_capacity), size(0) {
    table.resize(capacity);
  }

  void insert(const std::string& key, T value) {
    int idx = getIndex(key);
    for (auto& entry : table[idx]) {
      if (entry.first == key) {
        entry.second = value;
        return;
      }
    }
    table[idx].emplace_back(key, value);
    ++size;
    checkLoadFactorAndRehash();
  }

  std::optional<T> find(const std::string& key) const {
    int idx = getIndex(key);
    for (const auto& entry : table[idx]) {
      if (entry.first == key) {
        return entry.second;
      }
    }
    return std::nullopt;
  }

  bool erase(const std::string& key) {
    int idx = getIndex(key);
    for (auto it = table[idx].begin(); it != table[idx].end(); ++it) {
      if (it->first == key) {
        table[idx].erase(it);
        --size;
        return true;
      }
    }
    return false;
  }

  void print() const {
    for (int i = 0; i < capacity; ++i) {
      std::cout << "[" << i << "]: ";
      for (const auto& entry : table[i]) {
        std::cout << "(" << entry.first << ": " << entry.second << ") ";
      }
      std::cout << "\n";
    }
  }

  int Size() { return size; }
  bool IsEmpty() { return table.empty(); }
};