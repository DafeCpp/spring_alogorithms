#pragma once

struct Node {
  Node(const int& key)
      : key(key), left(nullptr), right(nullptr), parent(nullptr){};

  Node* left;
  Node* right;
  Node* parent;
  int key;
};

struct SplayTree {
  Node* root{nullptr};

  void Splay(Node* n);
  void Insert(int key);  // вставка ключа
  bool Find(int key);    // поиск ключа
  void Remove(int key);  // удаление ключа

 private:
  void rotateRight(Node* n);
  void rotateLeft(Node* n);
};