#ifndef TASK9_HPP
#define TASK9_HPP

struct Node {
  int key;
  int prior;
  Node* left;
  Node* right;
  Node(int k);
};

class Treap {
 private:
  Node* root;
  void split(Node* t, int k, Node*& l, Node*& r);
  Node* merge(Node* l, Node* r);
  void clear(Node* t);

 public:
  Treap();
  ~Treap();
  void Insert(int key);
  bool Find(int key);
  void Remove(int key);
};

#endif
