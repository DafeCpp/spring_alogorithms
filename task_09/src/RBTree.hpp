#pragma once

enum Color { red, black };

struct Node {
  int data;
  Color color;
  Node* left;
  Node* right;
  Node* parent;
  Node(int val)
      : data(val), color(red), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RBtree {
 private:
  Node* root;
  Node* TNULL;
  void destroyTree(Node* node);
  void initEmptyNode(Node* node, Node* parent);
  void leftRotate(Node* x);
  void rightRotate(Node* x);
  void insertBalance(Node* k);
  void rbChange(Node* u, Node* v);
  Node* minimum(Node* node);
  void deleteBalance(Node* x);
  void deleteNodeKey(Node* node, int key);

 public:
  ~RBtree();
  RBtree();
  void Insert(int key);
  bool Find(int key);
  void Remove(int key);
};