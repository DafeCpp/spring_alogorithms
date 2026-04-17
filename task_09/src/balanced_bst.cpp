#include "balanced_bst.h"

#include <algorithm>

BalancedBST::~BalancedBST() {
  Destroy(root_);
}

int BalancedBST::Height(Node* node) {
  return node == nullptr ? 0 : node->height;
}

int BalancedBST::BalanceFactor(Node* node) {
  return Height(node->right) - Height(node->left);
}

void BalancedBST::UpdateHeight(Node* node) {
  node->height = std::max(Height(node->left), Height(node->right)) + 1;
}

BalancedBST::Node* BalancedBST::RotateLeft(Node* node) {
  Node* new_root = node->right;
  node->right = new_root->left;
  new_root->left = node;
  UpdateHeight(node);
  UpdateHeight(new_root);
  return new_root;
}

BalancedBST::Node* BalancedBST::RotateRight(Node* node) {
  Node* new_root = node->left;
  node->left = new_root->right;
  new_root->right = node;
  UpdateHeight(node);
  UpdateHeight(new_root);
  return new_root;
}

BalancedBST::Node* BalancedBST::Balance(Node* node) {
  UpdateHeight(node);
  if (BalanceFactor(node) == 2) {
    if (BalanceFactor(node->right) < 0) {
      node->right = RotateRight(node->right);
    }
    return RotateLeft(node);
  }
  if (BalanceFactor(node) == -2) {
    if (BalanceFactor(node->left) > 0) {
      node->left = RotateLeft(node->left);
    }
    return RotateRight(node);
  }
  return node;
}

BalancedBST::Node* BalancedBST::Insert(Node* node, int key) {
  if (node == nullptr) {
    return new Node{key};
  }
  if (key < node->key) {
    node->left = Insert(node->left, key);
  } else if (key > node->key) {
    node->right = Insert(node->right, key);
  } else {
    return node;
  }
  return Balance(node);
}

BalancedBST::Node* BalancedBST::FindMin(Node* node) {
  return node->left == nullptr ? node : FindMin(node->left);
}

BalancedBST::Node* BalancedBST::RemoveMin(Node* node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = RemoveMin(node->left);
  return Balance(node);
}

BalancedBST::Node* BalancedBST::Remove(Node* node, int key) {
  if (node == nullptr) {
    return nullptr;
  }
  if (key < node->key) {
    node->left = Remove(node->left, key);
  } else if (key > node->key) {
    node->right = Remove(node->right, key);
  } else {
    Node* left = node->left;
    Node* right = node->right;
    delete node;
    if (right == nullptr) {
      return left;
    }
    Node* min = FindMin(right);
    min->right = RemoveMin(right);
    min->left = left;
    return Balance(min);
  }
  return Balance(node);
}

bool BalancedBST::Find(Node* node, int key) {
  if (node == nullptr) {
    return false;
  }
  if (key == node->key) {
    return true;
  }
  return key < node->key ? Find(node->left, key) : Find(node->right, key);
}

void BalancedBST::Destroy(Node* node) {
  if (node == nullptr) {
    return;
  }
  Destroy(node->left);
  Destroy(node->right);
  delete node;
}

void BalancedBST::Insert(int key) {
  root_ = Insert(root_, key);
}

bool BalancedBST::Find(int key) const {
  return Find(root_, key);
}

void BalancedBST::Remove(int key) {
  root_ = Remove(root_, key);
}
