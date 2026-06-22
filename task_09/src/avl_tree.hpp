#pragma once

class AvlTree {
 public:
  AvlTree();
  ~AvlTree();

  void Insert(int key);
  void Remove(int key);
  bool Find(int key) const;
  bool Empty() const;
  int Size() const;

 private:
  struct Node {
    int key;
    int height;
    int size;
    Node* left;
    Node* right;
    Node(int k);
  };

  Node* root_;

  static int Height(Node* node);
  static int SizeOf(Node* node);
  static int BalanceFactor(Node* node);
  static void UpdateNode(Node* node);
  static Node* RotateRight(Node* node);
  static Node* RotateLeft(Node* node);
  static Node* Balance(Node* node);
  static Node* InsertNode(Node* node, int key);
  static Node* FindMin(Node* node);
  static Node* RemoveMin(Node* node);
  static Node* RemoveNode(Node* node, int key);
  static bool FindNode(Node* node, int key);
  static void DestroyTree(Node* node);
};