#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

template <typename K, typename V>
struct Node {
  K key;
  V value;
  Node(K key_, V value_ = V{}) : key(key_), value(value_) {}
};

template <typename K, typename V>
class HashTable {
 public:
  HashTable() : hash_vector(10) {};
  V& Search(K key);
  bool Contains(K key);
  void AddElement(K key, V value);
  void DelElement(K key);
  V& operator[](const K& key);

  void Print() const;

 private:
  std::vector<std::vector<Node<K, V>>> hash_vector;
  void ReHashVector();
  int number_of_elemnts{0};
};

template <typename K, typename V>
bool HashTable<K, V>::Contains(K key) {
  int hash = std::hash<K>{}(key);
  int index = hash % hash_vector.size();
  for (auto node : hash_vector[index]) {
    if (node.key == key) {
      return true;
    }
  }
  return false;
}

template <typename K, typename V>
void HashTable<K, V>::ReHashVector() {
  int new_size = hash_vector.size() * 2;
  std::vector<std::vector<Node<K, V>>> buf_vec = hash_vector;
  hash_vector = std::vector<std::vector<Node<K, V>>>(new_size);
  for (int i{0}; i < buf_vec.size(); ++i) {
    for (auto element : buf_vec[i]) {
      int hash = std::hash<K>{}(element.key);
      int index = hash % hash_vector.size();
      hash_vector[index].push_back(element);
    }
  }
}

template <typename K, typename V>
void HashTable<K, V>::AddElement(K key, V value) {
  number_of_elemnts++;
  int half_of_size_h_vec = static_cast<int>(hash_vector.size() / 2);
  if (number_of_elemnts > half_of_size_h_vec) {
    ReHashVector();
  }
  int hash = std::hash<K>{}(key);
  int index = hash % hash_vector.size();
  hash_vector[index].push_back(Node(key, value));
}

template <typename K, typename V>
void HashTable<K, V>::DelElement(K key) {
  int hash = std::hash<K>{}(key);
  int index = hash % hash_vector.size();
  if (Contains(key)) {
    std::vector<Node<K, V>> buf_vector;
    for (auto node : hash_vector[index]) {
      if (node.key != key) {
        buf_vector.push_back(node);
      }
    }
    hash_vector[index] = buf_vector;
    return;
  }
  throw std::runtime_error("Can't find this element");
}

template <typename K, typename V>
V& HashTable<K, V>::Search(K key) {
  int hash = std::hash<K>{}(key);
  int index = hash % hash_vector.size();
  for (auto& node : hash_vector[index]) {
    if (node.key == key) {
      return node.value;
    }
  }
  throw std::runtime_error("Can't find this element");
}

template <typename K, typename V>
V& HashTable<K, V>::operator[](const K& key) {
  if (Contains(key)) {
    return Search(key);
  } else {
    AddElement(key, V{});
    return Search(key);
  }
}

template <typename K, typename V>
void HashTable<K, V>::Print() const {
  std::cout << "HashTable contents:\n";
  for (size_t i = 0; i < hash_vector.size(); ++i) {
    std::cout << "Vector" << i << ": ";
    for (const auto& node : hash_vector[i]) {
      std::cout << "[" << node.key << " -> " << node.value << "] ";
    }
    std::cout << "\n";
  }
  std::cout << "--------------------------\n";
}

#endif  // HASH_TABLE_HPP