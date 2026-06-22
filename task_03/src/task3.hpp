#pragma once

#include <memory>
#include <string>
#include <vector>

class KeyboardTree {
 private:
  struct Node {
    char letter;
    std::vector<std::unique_ptr<Node>> children;
    Node(char ch);
  };

  std::unique_ptr<Node> root;
  const std::vector<std::string> Keyboard;
  void build_subTree(Node* current_node, const std::string& digits,
                     size_t index);
  void DFS(Node* current_node, std::string& current_str,
           std::vector<std::string>& result);

 public:
  KeyboardTree();

  void build(const std::string& digits);
  std::vector<std::string> getCombinations();
};

std::vector<std::string> runKeyboardTree(const std::string& digits);
