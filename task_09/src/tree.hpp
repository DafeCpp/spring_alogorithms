#pragma once

struct Node {
    int key;
    Node* left;
    Node* right;
    int height;
    
    Node(int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
public:
    AVLTree();
    ~AVLTree();
    
    void Insert(int key);
    bool Find(int key);
    void Remove(int key);

private:
    Node* root;
    
    int height(Node* node);
    int balanceFactor(Node* node);
    void updateHeight(Node* node);
    
    Node* rotateRight(Node* y);
    Node* rotateLeft(Node* x);
    Node* balance(Node* node);
    
    Node* insert(Node* node, int key);
    Node* find(Node* node, int key);
    Node* remove(Node* node, int key);
    Node* minValueNode(Node* node);
    
    void destroy(Node* node);
};