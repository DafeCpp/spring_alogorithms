#include "splay_tree.hpp"

void SplayTree::RotateLeft(Node* node) {
  Node* node_right = node->right;
  if (!node_right) return;

  Node* parent = node->parent;
  node->right = node_right->left;
  if (node_right->left) node_right->left->parent = node;

  node_right->left = node;
  node->parent = node_right;
  node_right->parent = parent;

  if (parent) {
    if (parent->left == node)
      parent->left = node_right;
    else
      parent->right = node_right;
  } else
    root = node_right;
}

void SplayTree::RotateRight(Node* node) {
  Node* node_left = node->left;
  if (!node_left) return;

  Node* parent = node->parent;
  node->left = node_left->right;
  if (node_left->right) node_left->right->parent = node;

  node_left->right = node;
  node->parent = node_left;
  node_left->parent = parent;

  if (parent) {
    if (parent->left == node)
      parent->left = node_left;
    else
      parent->right = node_left;
  } else
    root = node_left;
}

void SplayTree::Splay(Node* node) {
  if (!node->parent) return;

  if (!node->parent->parent) {
    if (node->parent->left == node)
      RotateRight(node->parent);
    else
      RotateLeft(node->parent);
    return;
  }
  if (node->parent->right == node) {
    if (node->parent->parent->right == node->parent) {
      RotateLeft(node->parent->parent);
      RotateLeft(node->parent);
    } else {
      RotateLeft(node->parent);
      RotateRight(node->parent);
    }
  } else {
    if (node->parent->parent->left == node->parent) {
      RotateRight(node->parent->parent);
      RotateRight(node->parent);
    } else {
      RotateRight(node->parent);
      RotateLeft(node->parent);
    }
  }
  Splay(node);
}

void SplayTree::Insert(int key) {
  if (!root) {
    root = new Node(key);
    return;
  }

  Node* current = root;
  Node* parent = nullptr;

  while (current) {
    parent = current;
    if (key <= current->key)
      current = current->left;
    else
      current = current->right;
  }

  Node* new_node = new Node(key);
  new_node->parent = parent;

  if (key <= parent->key)
    parent->left = new_node;
  else
    parent->right = new_node;

  Splay(new_node);
}

bool SplayTree::Find(int key) {
  if (!root) return false;

  Node* current = root;
  Node* last = nullptr;

  while (current) {
    last = current;
    if (key == current->key) {
      Splay(current);
      return true;
    } else if (key < current->key)
      current = current->left;
    else
      current = current->right;
  }
  if (last) Splay(last);
  return false;
}

void SplayTree::Remove(int key) {
  if (Find(key)) {
    Node* node = root;

    Node* left_tree = root->left;
    Node* right_tree = root->right;

    if (!left_tree) {
      root = right_tree;
      if (right_tree) right_tree->parent = nullptr;
      delete node;
      return;
    }
    if (!right_tree) {
      root = left_tree;
      if (left_tree) left_tree->parent = nullptr;
      delete node;
      return;
    }

    Node* current = right_tree;
    Node* last = nullptr;

    while (current) {
      last = current;
      current = current->left;
    }

    Splay(last);

    if (last->left) last->left->parent = nullptr;
    last->left = nullptr;

    root = last;
    last->left = left_tree;
    left_tree->parent = last;

    delete node;
  }
}