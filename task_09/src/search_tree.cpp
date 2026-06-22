#include "search_tree.hpp"

SearchTree::Node::Node(int key_value)
    : key(key_value), priority(Priority(key_value)) {}

std::uint32_t SearchTree::Priority(int key) {
  std::uint32_t value = static_cast<std::uint32_t>(key);
  value ^= value >> 16;
  value *= 0x7feb352dU;
  value ^= value >> 15;
  value *= 0x846ca68bU;
  value ^= value >> 16;
  return value;
}

void SearchTree::Insert(int key) {
  if (!Find(key)) {
    Insert(root_, std::make_unique<Node>(key));
  }
}

bool SearchTree::Find(int key) const { return Find(root_, key); }

void SearchTree::Remove(int key) { Remove(root_, key); }

bool SearchTree::Find(const std::unique_ptr<Node>& node, int key) {
  if (!node) {
    return false;
  }
  if (key == node->key) {
    return true;
  }
  return Find(key < node->key ? node->left : node->right, key);
}

void SearchTree::Insert(std::unique_ptr<Node>& node,
                        std::unique_ptr<Node> item) {
  if (!node) {
    node = std::move(item);
    return;
  }

  if (item->key < node->key) {
    Insert(node->left, std::move(item));
    if (node->left->priority > node->priority) {
      RotateRight(node);
    }
  } else {
    Insert(node->right, std::move(item));
    if (node->right->priority > node->priority) {
      RotateLeft(node);
    }
  }
}

void SearchTree::Remove(std::unique_ptr<Node>& node, int key) {
  if (!node) {
    return;
  }

  if (key < node->key) {
    Remove(node->left, key);
    return;
  }
  if (key > node->key) {
    Remove(node->right, key);
    return;
  }

  if (!node->left) {
    node = std::move(node->right);
  } else if (!node->right) {
    node = std::move(node->left);
  } else if (node->left->priority > node->right->priority) {
    RotateRight(node);
    Remove(node->right, key);
  } else {
    RotateLeft(node);
    Remove(node->left, key);
  }
}

void SearchTree::RotateLeft(std::unique_ptr<Node>& node) {
  std::unique_ptr<Node> new_root = std::move(node->right);
  node->right = std::move(new_root->left);
  new_root->left = std::move(node);
  node = std::move(new_root);
}

void SearchTree::RotateRight(std::unique_ptr<Node>& node) {
  std::unique_ptr<Node> new_root = std::move(node->left);
  node->left = std::move(new_root->right);
  new_root->right = std::move(node);
  node = std::move(new_root);
}
