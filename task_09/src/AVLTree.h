#pragma once

class AVLTree {
 private:
  struct Node {
    int key;
    int height;
    Node* left;
    Node* right;

    Node(int k) : key(k), height(1), left(nullptr), right(nullptr) {}
  };

  Node* root;

  int Height(Node* p);
  int BFactor(Node* p);
  void FixHeight(Node* p);
  Node* RotateRight(Node* p);
  Node* RotateLeft(Node* q);
  Node* Balance(Node* p);
  Node* InsertNode(Node* p, int k);
  Node* RemoveNode(Node* p, int k);
  Node* FindMin(Node* p);
  Node* RemoveMin(Node* p);
  void DeleteTree(Node* p);

 public:
  AVLTree();
  ~AVLTree();

  void Insert(int key);
  bool Find(int key);
  void Remove(int key);
};