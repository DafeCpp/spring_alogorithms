#pragma once

#include <iostream>

class AVLTree {
 private:
  struct Node {
    int key;
    Node* left{nullptr};
    Node* right{nullptr};
    int height;
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
    ~Node() {
      delete left;
      delete right;
    }
  };

  Node* root = nullptr;

  int height(Node* n) { return n ? n->height : 0; }

  int balanceFactor(Node* n) {
    return n ? height(n->left) - height(n->right) : 0;
  }

  void updateHeight(Node* n) {
    n->height = 1 + std::max(height(n->left), height(n->right));
  }

  Node* rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    updateHeight(y);
    updateHeight(x);

    return x;
  }

  Node* rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    updateHeight(x);
    updateHeight(y);

    return y;
  }

  Node* balance(Node* n) {
    updateHeight(n);
    int bf = balanceFactor(n);

    if (bf > 1) {
      if (balanceFactor(n->left) < 0) {
        n->left = rotateLeft(n->left);
      }
      return rotateRight(n);
    }

    if (bf < -1) {
      if (balanceFactor(n->right) > 0) {
        n->right = rotateRight(n->right);
      }
      return rotateLeft(n);
    }

    return n;
  }

  Node* insert(Node* node, int key) {
    if (!node) return new Node(key);

    if (key < node->key)
      node->left = insert(node->left, key);
    else if (key > node->key)
      node->right = insert(node->right, key);
    else
      return node;

    return balance(node);
  }

  Node* minValueNode(Node* node) {
    Node* current = node;
    while (current->left) current = current->left;
    return current;
  }

  Node* erase(Node* node, int key) {
    if (!node) return node;

    if (key < node->key)
      node->left = erase(node->left, key);
    else if (key > node->key)
      node->right = erase(node->right, key);
    else {
      if (!node->left || !node->right) {
        Node* temp = node->left ? node->left : node->right;
        if (!temp) {
          temp = node;
          node = nullptr;
        } else {
          *node = *temp;
        }
        delete temp;
      } else {
        Node* temp = minValueNode(node->right);
        node->key = temp->key;
        node->right = erase(node->right, temp->key);
      }
    }

    if (!node) return node;

    return balance(node);
  }

  bool find(Node* node, int key) const {
    if (!node) return false;
    if (key == node->key) return true;
    if (key < node->key)
      return find(node->left, key);
    else
      return find(node->right, key);
  }

  void inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->key << " ";
    inorder(node->right);
  }

 public:
  void insert(int key) { root = insert(root, key); }

  void erase(int key) { root = erase(root, key); }

  bool find(int key) const { return find(root, key); }

  void printInorder() const {
    inorder(root);
    std::cout << "\n";
  }
};
