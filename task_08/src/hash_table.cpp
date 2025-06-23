#include "hash_table.hpp"

int HashTable::SecondHashFunc(const std::string& key) { return 1; }

int HashTable::FirstHashFunc(const std::string& key) {
  return base_hasher(key);
}

int HashTable::HashFunc(const std::string& key, int iteration) {
  return (FirstHashFunc(key) + iteration * SecondHashFunc(key)) % array.size();
}

HashTable::HashTable(size_t size) {
  std::vector<Element> vec(size);
  array = vec;
}

HashTable::HashTable() {
  std::vector<Element> vec(20);
  array = vec;
}

HashTable::HashTable(const std::vector<std::pair<std::string, int>>& input) {
  std::vector<Element> vec(input.size() * 3);
  array = vec;
  for (const auto& elem : input) {
    Add(elem.first, elem.second);
  }
}

int HashTable::FindIndex(const std::string& key) {
  for (int i{0}; i < array.size(); ++i) {
    int index{HashFunc(key, i)};
    if (array[index].condition == Condition::Empty) {
      return -1;
    }
    if (array[index].condition == Condition::Full && array[index].key == key) {
      return index;
    }
  }
  return -1;
}

void HashTable::Del(const std::string& del_key) {
  int index = FindIndex(del_key);
  if (index == -1) {
    throw HashTableError("key do not exist");
  }
  array[index].condition = Condition::Cleared;
  full_elements -= 1;
  return;
}

int HashTable::Get(const std::string& key) {
  int index = FindIndex(key);
  if (index == -1) {
    throw HashTableError("key do not exist");
  }
  return array[index].value;
}

void HashTable::Add(const std::string& new_key, int new_value) {
  int index = FindIndex(new_key);
  if (index != -1) {
    array[index].value = new_value;
    return;
  }
  if (full_elements > array.size() / 2) {
    UpdateArray();
  }
  for (int i{0}; i < array.size(); ++i) {
    index = HashFunc(new_key, i);
    if (array[index].condition == Condition::Empty ||
        array[index].condition == Condition::Cleared) {
      array[index].key = new_key;
      array[index].value = new_value;
      array[index].condition = Condition::Full;
      full_elements += 1;
      return;
    }
  }
  throw HashTableError("full table");
}

void HashTable::UpdateArray() {
  std::vector<Element> old_array = std::move(array);
  std::vector<Element> new_array(old_array.size() * 2);
  array = new_array;
  full_elements = 0;
  for (const auto& elem : old_array) {
    if (elem.condition == Condition::Full) {
      Add(elem.key, elem.value);
    }
  }
}