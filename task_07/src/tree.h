#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <algorithm>
#include <memory>
#include <vector>

/*
Особенностью АВЛ-дерева является то, что оно является сбалансированным в
следующем смысле: для любого узла дерева высота его правого поддерева отличается
от высоты левого поддерева не более чем на единицу.
*/

template <typename T>
class AVLTree {
 private:
  struct Node {
    T val;
    int h;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(T val) : val(val), h(1), left(nullptr), right(nullptr) {}
  };

  std::shared_ptr<Node> root;

  int Height(std::shared_ptr<Node> node) const { return node ? node->h : 0; }

  int BalanceFactor(std::shared_ptr<Node> node) const {
    return Height(node->right) - Height(node->left);
  }

  void UpdateHeight(std::shared_ptr<Node> node) {
    node->h = std::max(Height(node->left), Height(node->right)) + 1;
  }

  std::shared_ptr<Node> RotateRight(std::shared_ptr<Node> y) {
    auto x = y->left;
    y->left = x->right;
    x->right = y;
    UpdateHeight(y);
    UpdateHeight(x);
    return x;
  }

  std::shared_ptr<Node> RotateLeft(std::shared_ptr<Node> x) {
    auto y = x->right;
    x->right = y->left;
    y->left = x;
    UpdateHeight(x);
    UpdateHeight(y);
    return y;
  }

  std::shared_ptr<Node> Balance(std::shared_ptr<Node> node) {
    UpdateHeight(node);

    if (BalanceFactor(node) == 2) {
      if (BalanceFactor(node->right) < 0)
        node->right = RotateRight(node->right);
      return RotateLeft(node);
    }

    if (BalanceFactor(node) == -2) {
      if (BalanceFactor(node->left) > 0) node->left = RotateLeft(node->left);
      return RotateRight(node);
    }

    return node;
  }

  std::shared_ptr<Node> Insert(std::shared_ptr<Node> node, T val) {
    if (!node) return std::make_shared<Node>(val);

    if (val < node->val)
      node->left = Insert(node->left, val);
    else
      node->right = Insert(node->right, val);

    return Balance(node);
  }

  std::shared_ptr<Node> FindMin(std::shared_ptr<Node> node) const {
    return node->left ? FindMin(node->left) : node;
  }

  std::shared_ptr<Node> RemoveMin(std::shared_ptr<Node> node) {
    if (!node->left) return node->right;
    node->left = RemoveMin(node->left);
    return Balance(node);
  }

  std::shared_ptr<Node> Remove(std::shared_ptr<Node> node, T val) {
    if (!node) return nullptr;

    if (val < node->val) {
      node->left = Remove(node->left, val);
    } else if (val > node->val) {
      node->right = Remove(node->right, val);
    } else {
      auto left = node->left;
      auto right = node->right;

      if (!right) return left;

      auto min = FindMin(right);
      min->right = RemoveMin(right);
      min->left = left;

      return Balance(min);
    }

    return Balance(node);
  }

  bool Contains(std::shared_ptr<Node> node, T val) const {
    if (!node) return false;
    if (val == node->val) return true;
    return val < node->val ? Contains(node->left, val)
                           : Contains(node->right, val);
  }

  void InOrder(std::shared_ptr<Node> node, std::vector<T>& result) const {
    if (!node) return;
    InOrder(node->left, result);
    result.push_back(node->val);
    InOrder(node->right, result);
  }

 public:
  AVLTree() : root(nullptr) {}

  void Insert(T val) { root = Insert(root, val); }
  void Remove(T val) { root = Remove(root, val); }
  bool Contains(T val) const { return Contains(root, val); }

  std::vector<T> InOrder() const {
    std::vector<T> result;
    InOrder(root, result);
    return result;
  }
};

#endif  // AVL_TREE_H