#include <stdexcept>
#include <vector>

class AvlTree {
 public:
  AvlTree(){};
  AvlTree(std::vector<std::pair<int, int>> key_values);
  int operator[](int key) {
    Node* node{Search(key)};
    if (node == nullptr) {
      throw std::out_of_range("dont exist");
    } else {
      return node->data;
    }
  }

  void del(int del_key);
  void add(int new_key, int data);

 private:
  struct Node {
    int key;
    int data;
    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int height = 1;
    Node(int key, int data) {
      this->key = key;
      this->data = data;
    }
  };
  Node* head = nullptr;
  Node* Search(int key) const;
  Node* SearchMin(Node* cur) const;
  Node* SearchSuccessor(Node* cur) const;

  int GetHeight(Node* node) {
    if (node) {
      UpdateHeight(node);
      return node->height;
    }
    return 0;
  }

  int GetDifference(Node* node) {
    if (node) {
      return (GetHeight(node->left_child) - GetHeight(node->right_child));
    }
    return 0;
  }

  void UpdateHeight(Node* node) {
    if (node) {
      node->height = 1 + std::max(GetHeight(node->left_child),
                                  GetHeight(node->right_child));
    }
  }

  Node* Balance(Node* old_par);
  Node* LeftLeftImbalance(Node* old_par);
  Node* RightRightImbalance(Node* old_par);
  Node* LeftRightImbalance(Node* old_par);
  Node* RightLeftImbalance(Node* old_par);

 public:
  friend std::ostream& operator<<(std::ostream& os, const AvlTree& tree);
  class Iterator {
   public:
    Iterator(Node* node, const AvlTree& tree)
        : current_node(node), tree(tree){};

    std::pair<int, int> operator*() const {
      if (!current_node) {
        throw std::out_of_range("dont exist");
      }
      return {current_node->key, current_node->data};
    }

    Iterator& operator++() {
      current_node = tree.SearchSuccessor(current_node);
      return *this;
    }

    bool operator==(const Iterator& other) const {
      return current_node == other.current_node;
    }

    bool operator!=(const Iterator& other) const {
      return current_node != other.current_node;
    }

   private:
    Node* current_node;
    const AvlTree& tree;
  };
  Iterator begin() const {
    return Iterator(head ? SearchMin(head) : nullptr, *this);
  }
  Iterator end() const { return Iterator(nullptr, *this); }
};