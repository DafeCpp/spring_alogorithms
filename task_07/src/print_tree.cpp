#include <iostream>

#include "avl_tree.hpp"

std::ostream& operator<<(std::ostream& os, const AvlTree& tree) {
  os << "{";
  bool first_elem = true;
  for (const auto& [key, value] : tree) {
    if (!first_elem) {
      os << ", ";
    }
    os << "(" << key << ", " << value << ")";
    first_elem = false;
  }
  os << "}";
  return os;
}

AvlTree::Node* AvlTree::SearchSuccessor(Node* cur) const {
  if (cur == nullptr) {
    return nullptr;
  }
  if (cur->right_child != nullptr) {
    return SearchMin(cur->right_child);
  } else {
    Node* parent = cur->parent;
    while (parent != nullptr &&
           cur == parent->right_child) {  // пока я не левый ребенок или не
                                          // корень в конце
      cur = parent;
      parent = parent->parent;
    }
    return parent;
  }
}