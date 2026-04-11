#include "splay_tree.hpp"

#include <string>

void SplayTree::rotateLeft(Node* n) {
  Node* m = n->right;
  if (!m) return;

  Node* parent = n->parent;
  n->right = m->left;
  if (m->left) m->left->parent = n;

  m->left = n;
  n->parent = m;
  m->parent = parent;

  if (parent) {
    if (parent->left == n)
      parent->left = m;
    else
      parent->right = m;
  } else
    root = m;
}

void SplayTree::rotateRight(Node* n) {
  Node* m = n->left;
  if (!m) return;

  Node* parent = n->parent;
  n->left = m->right;
  if (m->right) m->right->parent = n;

  m->right = n;
  n->parent = m;
  m->parent = parent;

  if (parent) {
    if (parent->left == n)
      parent->left = m;
    else
      parent->right = m;
  } else
    root = m;
}

void SplayTree::Splay(Node* n) {
  if (!n->parent) return;

  if (!n->parent->parent) {
    if (n->parent->left == n)
      rotateRight(n->parent);
    else
      rotateLeft(n->parent);
    return;
  }
  if (n->parent->right == n) {
    if (n->parent->parent->right == n->parent) {
      rotateLeft(n->parent->parent);
      rotateLeft(n->parent);
    } else {
      rotateLeft(n->parent);
      rotateRight(n->parent);
    }
  } else {
    if (n->parent->parent->left == n->parent) {
      rotateRight(n->parent->parent);
      rotateRight(n->parent);
    } else {
      rotateRight(n->parent);
      rotateLeft(n->parent);
    }
  }
  Splay(n);
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

  Node* new_n = new Node(key);
  new_n->parent = parent;

  if (key <= parent->key)
    parent->left = new_n;
  else
    parent->right = new_n;

  Splay(new_n);
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
    Node* n = root;

    Node* left_tree = root->left;
    Node* right_tree = root->right;

    if (!left_tree) {
      root = right_tree;
      if (right_tree) right_tree->parent = nullptr;
      delete n;
      return;
    }
    if (!right_tree) {
      root = left_tree;
      if (left_tree) left_tree->parent = nullptr;
      delete n;
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

    delete n;
  }
}