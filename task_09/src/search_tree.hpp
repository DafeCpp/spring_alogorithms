#pragma once

#include <cstdint>
#include <memory>

class SearchTree {
 public:
  void Insert(int key);
  bool Find(int key) const;
  void Remove(int key);

 private:
  struct Node {
    explicit Node(int key_value);

    int key;
    std::uint32_t priority;
    std::unique_ptr<Node> left;
    std::unique_ptr<Node> right;
  };

  static std::uint32_t Priority(int key);
  static bool Find(const std::unique_ptr<Node>& node, int key);
  static void Insert(std::unique_ptr<Node>& node, std::unique_ptr<Node> item);
  static void Remove(std::unique_ptr<Node>& node, int key);
  static void RotateLeft(std::unique_ptr<Node>& node);
  static void RotateRight(std::unique_ptr<Node>& node);

  std::unique_ptr<Node> root_;
};

using BalancedSearchTree = SearchTree;
using BinarySearchTree = SearchTree;
using Tree = SearchTree;
using Treap = SearchTree;
