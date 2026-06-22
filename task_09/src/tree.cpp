#include "tree.hpp"
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroy(root);
}

void AVLTree::destroy(Node* node) {
    if (node) {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

int AVLTree::height(Node* node) {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) {
    return node ? height(node->left) - height(node->right) : 0;
}

void AVLTree::updateHeight(Node* node) {
    if (node) {
        node->height = 1 + std::max(height(node->left), height(node->right));
    }
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    updateHeight(y);
    updateHeight(x);
    
    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    updateHeight(x);
    updateHeight(y);
    
    return y;
}

Node* AVLTree::balance(Node* node) {
    if (!node) return nullptr;
    
    updateHeight(node);
    
    int bf = balanceFactor(node);
    
    if (bf > 1) {
        if (balanceFactor(node->left) < 0) {
            node->left = rotateLeft(node->left);
        }
        return rotateRight(node);
    }
    
    if (bf < -1) {
        if (balanceFactor(node->right) > 0) {
            node->right = rotateRight(node->right);
        }
        return rotateLeft(node);
    }
    
    return node;
}

Node* AVLTree::insert(Node* node, int key) {
    if (!node) {
        return new Node(key);
    }
    
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else if (key > node->key) {
        node->right = insert(node->right, key);
    } else {
        return node;
    }
    
    return balance(node);
}

void AVLTree::Insert(int key) {
    root = insert(root, key);
}

Node* AVLTree::find(Node* node, int key) {
    if (!node || node->key == key) {
        return node;
    }
    
    if (key < node->key) {
        return find(node->left, key);
    }
    return find(node->right, key);
}

bool AVLTree::Find(int key) {
    return find(root, key) != nullptr;
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left) {
        current = current->left;
    }
    return current;
}

Node* AVLTree::remove(Node* node, int key) {
    if (!node) {
        return nullptr;
    }
    
    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left || !node->right) {
            Node* temp = node->left ? node->left : node->right;
            delete node;
            return temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }
    
    return balance(node);
}

void AVLTree::Remove(int key) {
    root = remove(root, key);
}