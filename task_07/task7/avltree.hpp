#ifndef AVLTREE_HPP
#define AVLTREE_HPP

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    void insert(int key);
    void remove(int key);
    bool search(int key) const;

private:
    Node* root;
    Node* insert(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* minValueNode(Node* node);
    bool search(Node* node, int key) const;
    int height(Node* node) const;
    int balanceFactor(Node* node) const;
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    void destroyTree(Node* node);
};

#endif