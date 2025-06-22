#include "avltree.hpp"
#include <algorithm>

AVLTree::AVLTree() : root(nullptr) {}

AVLTree::~AVLTree() {
    destroyTree(root);
}

void AVLTree::destroyTree(Node* node) {
    if (node) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

int AVLTree::height(Node* node) const {
    return node ? node->height : 0;
}

int AVLTree::balanceFactor(Node* node) const {
    return node ? height(node->left) - height(node->right) : 0;
}

void AVLTree::insert(int key) {
    root = insert(root, key);
}

void AVLTree::remove(int key) {
    root = remove(root, key);
}

bool AVLTree::search(int key) const {
    return search(root, key);
}

Node* AVLTree::insert(Node* node, int key) {
    if (!node) {
        return new Node{key, nullptr, nullptr, 1};
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

Node* AVLTree::remove(Node* node, int key) {
    if (!node) {
        return nullptr;
    }
    if (key < node->key) {
        node->left = remove(node->left, key);
    } else if (key > node->key) {
        node->right = remove(node->right, key);
    } else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        } else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }
    if (!node) {
        return node;
    }
    return balance(node);
}

Node* AVLTree::minValueNode(Node* node) {
    Node* current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

bool AVLTree::search(Node* node, int key) const {
    if (!node) {
        return false;
    }
    if (key == node->key) {
        return true;
    } else if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

Node* AVLTree::rotateRight(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    return x;
}

Node* AVLTree::rotateLeft(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;
    return y;
}

Node* AVLTree::balance(Node* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
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