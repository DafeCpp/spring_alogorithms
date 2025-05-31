#include "avl_tree.hpp"

#include <iostream>

AvlTree::Node* AvlTree::Search(int search_key) const {
  Node* cur = head;
  while (cur != nullptr) {
    if (cur->key == search_key) {
      return cur;
    } else if (search_key < cur->key) {
      cur = cur->left_child;
    } else if (search_key > cur->key) {
      cur = cur->right_child;
    }
  }
  return nullptr;
}

void AvlTree::Add(int new_key, int data) {
  Node* new_node = new Node(new_key, data);
  if (head == nullptr) {
    head = new_node;
    return;
  }
  Node* par = nullptr;
  Node* cur = head;

  while (cur != nullptr) {
    par = cur;
    if (cur->key == new_key) {
      std::cout << "the key is already exist\n";
      delete new_node;
      return;
    } else if (new_key < cur->key) {
      cur = cur->left_child;
    } else if (new_key > cur->key) {
      cur = cur->right_child;
    }
  }

  if (new_key < par->key) {
    par->left_child = new_node;
  }
  if (new_key > par->key) {
    par->right_child = new_node;
  }
  new_node->parent = par;

  while (new_node != nullptr) {
    new_node = Balance(new_node)->parent;
  }
}

AvlTree::Node* AvlTree::SearchMin(Node* cur) const {
  while (cur->left_child != nullptr) {
    cur = cur->left_child;
  }
  return cur;
}

void AvlTree::Del(int del_key) {
  Node* del_par = nullptr;
  Node* del_node = head;

  while (del_node != nullptr) {
    if (del_node->key == del_key) {
      break;
    }
    del_par = del_node;
    if (del_key < del_node->key) {
      del_node = del_node->left_child;
    } else if (del_key > del_node->key) {
      del_node = del_node->right_child;
    }
  }
  if (del_node == nullptr) {
    return;
  }

  Node* new_n;

  if (del_node->right_child == nullptr) {
    new_n = del_node->left_child;
    if (del_par == nullptr) {
      head = del_node->left_child;
    } else if (del_node == del_par->left_child) {
      del_par->left_child = del_node->left_child;
    } else {
      del_par->right_child = del_node->left_child;
    }
    if (del_node->left_child != nullptr) {
      del_node->left_child->parent = del_par;
    }
    delete del_node;
  } else {
    new_n = SearchMin(del_node->right_child);
    if (new_n == del_node->right_child) {  // это прямой правый ребенок
      new_n->left_child = del_node->left_child;
    } else {
      new_n->parent->left_child = new_n->right_child;
      if (new_n->right_child != nullptr) {
        new_n->right_child->parent = new_n->parent;
      }
      new_n->right_child = del_node->right_child;
      new_n->left_child = del_node->left_child;
      del_node->right_child->parent = new_n;
    }
    new_n->parent = del_par;
    if (del_node->left_child != nullptr) {
      del_node->left_child->parent = new_n;
    }
    if (del_par != nullptr) {
      if (del_node == del_par->left_child) {
        del_par->left_child = new_n;
      } else {
        del_par->right_child = new_n;
      }
    } else {
      head = new_n;
    }
    delete del_node;
  }
  Node* balancing = (new_n) ? new_n : del_par;
  while (balancing != nullptr) {
    balancing = Balance(balancing)->parent;
  }
}

AvlTree::AvlTree(std::vector<std::pair<int, int>> key_values) {
  for (int i = 0; i < key_values.size(); ++i) {
    Add(key_values[i].first, key_values[i].second);
  }
}

AvlTree::Node* AvlTree::Balance(Node* old_par) {
  UpdateHeight(old_par);
  int diff{GetDifference(old_par)};
  if (diff > 1) {
    if (GetDifference(old_par->left_child) > 0) {
      return LeftLeftImbalance(old_par);
    } else {
      return LeftRightImbalance(old_par);
    }
  } else if (diff < -1) {
    if (GetDifference(old_par->right_child) < 0) {
      return RightRightImbalance(old_par);
    } else {
      return RightLeftImbalance(old_par);
    }
  }
  return old_par;
}

AvlTree::Node* AvlTree::LeftLeftImbalance(Node* old_par) {
  Node* new_par{old_par->left_child};
  if (old_par->parent) {
    if (old_par->parent->left_child == old_par) {
      old_par->parent->left_child = new_par;
    } else {
      old_par->parent->right_child = new_par;
    }
  }
  new_par->parent = old_par->parent;
  old_par->left_child = new_par->right_child;
  if (new_par->right_child) new_par->right_child->parent = old_par;
  old_par->parent = new_par;
  new_par->right_child = old_par;
  UpdateHeight(old_par);
  UpdateHeight(new_par);
  if (old_par == head) {
    head = new_par;
  }
  return new_par;
}

AvlTree::Node* AvlTree::RightRightImbalance(Node* old_par) {
  Node* new_par{old_par->right_child};
  if (old_par->parent) {
    if (old_par->parent->right_child == old_par) {
      old_par->parent->right_child = new_par;
    } else {
      old_par->parent->left_child = new_par;
    }
  }
  new_par->parent = old_par->parent;
  old_par->right_child = new_par->left_child;
  if (new_par->left_child) new_par->left_child->parent = old_par;
  old_par->parent = new_par;
  new_par->left_child = old_par;
  UpdateHeight(old_par);
  UpdateHeight(new_par);
  if (old_par == head) {
    head = new_par;
  }
  return new_par;
}

AvlTree::Node* AvlTree::LeftRightImbalance(Node* old_par) {
  Node* new_par = RightRightImbalance(old_par->left_child);
  new_par = LeftLeftImbalance(old_par);
  return new_par;
}

AvlTree::Node* AvlTree::RightLeftImbalance(Node* old_par) {
  Node* new_par = LeftLeftImbalance(old_par->right_child);
  new_par = RightRightImbalance(old_par);
  return new_par;
}