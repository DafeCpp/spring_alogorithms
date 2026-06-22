#include "avl_tree.hpp"

AvlTree::Node::Node(int k)
    : key(k), height(1), size(1), left(nullptr), right(nullptr) {}

AvlTree::AvlTree() : root_(nullptr) {}

AvlTree::~AvlTree() { DestroyTree(root_); }

void AvlTree::DestroyTree(Node* node) {
  if (node == nullptr) {
    return;
  }
  DestroyTree(node->left);
  DestroyTree(node->right);
  delete node;
}

int AvlTree::Height(Node* node) { return node == nullptr ? 0 : node->height; }

int AvlTree::SizeOf(Node* node) { return node == nullptr ? 0 : node->size; }

int AvlTree::BalanceFactor(Node* node) {
  return Height(node->right) - Height(node->left);
}

void AvlTree::UpdateNode(Node* node) {
  int left_height = Height(node->left);
  int right_height = Height(node->right);
  node->height = (left_height > right_height ? left_height : right_height) + 1;
  node->size = SizeOf(node->left) + SizeOf(node->right) + 1;
}

AvlTree::Node* AvlTree::RotateRight(Node* node) {
  Node* new_root = node->left;
  node->left = new_root->right;
  new_root->right = node;
  UpdateNode(node);
  UpdateNode(new_root);
  return new_root;
}

AvlTree::Node* AvlTree::RotateLeft(Node* node) {
  Node* new_root = node->right;
  node->right = new_root->left;
  new_root->left = node;
  UpdateNode(node);
  UpdateNode(new_root);
  return new_root;
}

AvlTree::Node* AvlTree::Balance(Node* node) {
  UpdateNode(node);
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

AvlTree::Node* AvlTree::InsertNode(Node* node, int key) {
  if (node == nullptr) {
    return new Node(key);
  }
  if (key < node->key) {
    node->left = InsertNode(node->left, key);
  } else if (key > node->key) {
    node->right = InsertNode(node->right, key);
  } else {
    return node;
  }
  return Balance(node);
}

AvlTree::Node* AvlTree::FindMin(Node* node) {
  return node->left == nullptr ? node : FindMin(node->left);
}

AvlTree::Node* AvlTree::RemoveMin(Node* node) {
  if (node->left == nullptr) {
    return node->right;
  }
  node->left = RemoveMin(node->left);
  return Balance(node);
}

AvlTree::Node* AvlTree::RemoveNode(Node* node, int key) {
  if (node == nullptr) {
    return nullptr;
  }
  if (key < node->key) {
    node->left = RemoveNode(node->left, key);
  } else if (key > node->key) {
    node->right = RemoveNode(node->right, key);
  } else {
    Node* left = node->left;
    Node* right = node->right;
    delete node;
    if (right == nullptr) {
      return left;
    }
    Node* min_node = FindMin(right);
    min_node->right = RemoveMin(right);
    min_node->left = left;
    return Balance(min_node);
  }
  return Balance(node);
}

bool AvlTree::FindNode(Node* node, int key) {
  if (node == nullptr) {
    return false;
  }
  if (key < node->key) {
    return FindNode(node->left, key);
  }
  if (key > node->key) {
    return FindNode(node->right, key);
  }
  return true;
}

void AvlTree::Insert(int key) { root_ = InsertNode(root_, key); }

void AvlTree::Remove(int key) { root_ = RemoveNode(root_, key); }

bool AvlTree::Find(int key) const { return FindNode(root_, key); }

bool AvlTree::Empty() const { return root_ == nullptr; }

int AvlTree::Size() const { return SizeOf(root_); }