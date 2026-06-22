#pragma once

class BalancedBST {
 public:
  BalancedBST() = default;
  ~BalancedBST();

  void Insert(int key);
  bool Find(int key) const;
  void Remove(int key);

 private:
  struct Node {
    int key;
    int height = 1;
    Node* left = nullptr;
    Node* right = nullptr;
  };

  Node* root_ = nullptr;

  static int Height(Node* node);
  static int BalanceFactor(Node* node);
  static void UpdateHeight(Node* node);
  static Node* RotateLeft(Node* node);
  static Node* RotateRight(Node* node);
  static Node* Balance(Node* node);
  static Node* Insert(Node* node, int key);
  static Node* Remove(Node* node, int key);
  static Node* FindMin(Node* node);
  static Node* RemoveMin(Node* node);
  static bool Find(Node* node, int key);
  static void Destroy(Node* node);
};
