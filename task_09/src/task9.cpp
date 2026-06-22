#include "task9.hpp"

#include <cstdlib>

Node::Node(int k) {
  key = k;
  prior = rand();
  left = nullptr;
  right = nullptr;
}

Treap::Treap() { root = nullptr; }

void Treap::clear(Node* t) {
  if (!t) return;
  clear(t->left);
  clear(t->right);
  delete t;
}

Treap::~Treap() { clear(root); }

void Treap::split(Node* t, int k, Node*& l, Node*& r) {
  if (!t) {
    l = nullptr;
    r = nullptr;
  } else if (t->key <= k) {
    split(t->right, k, t->right, r);
    l = t;
  } else {
    split(t->left, k, l, t->left);
    r = t;
  }
}

Node* Treap::merge(Node* l, Node* r) {
  if (!l || !r) return l ? l : r;
  if (l->prior > r->prior) {
    l->right = merge(l->right, r);
    return l;
  } else {
    r->left = merge(l, r->left);
    return r;
  }
}

bool Treap::Find(int key) {
  Node* curr = root;
  while (curr) {
    if (curr->key == key) return true;
    if (key < curr->key)
      curr = curr->left;
    else
      curr = curr->right;
  }
  return false;
}

void Treap::Insert(int key) {
  if (Find(key)) return;
  Node* l = nullptr;
  Node* r = nullptr;
  split(root, key, l, r);
  Node* m = new Node(key);
  root = merge(merge(l, m), r);
}

void Treap::Remove(int key) {
  if (!Find(key)) return;
  Node* l1 = nullptr;
  Node* r1 = nullptr;
  split(root, key, l1, r1);
  Node* l2 = nullptr;
  Node* m = nullptr;
  split(l1, key - 1, l2, m);
  delete m;
  root = merge(l2, r1);
}
