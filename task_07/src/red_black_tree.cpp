#include "red_black_tree.hpp"

void Black_Red_Tree::insert(int key) {
    Node *z = new Node(key, "RED", nil, nil, nil);
    Node *y = nil;
    Node *x = root;

    while (x != nil) {
        y = x;
        if (z->key < x->key) {
            x = x->left_child;
        } else {
            x = x->right_child;
        }
    }

    z->parent = y;
    if (y == nil) {
        root = z;
    } else if (z->key < y->key) {
        y->left_child = z;
    } else {
        y->right_child = z;
    }

    fixInsert(z);
}

void Black_Red_Tree::fixInsert(Node *z) {
    while (z->parent->colour == "RED") {
        if (z->parent == z->parent->parent->left_child) {
            Node *y = z->parent->parent->right_child;
            if (y->colour == "RED") {
                z->parent->colour = "BLACK";
                y->colour = "BLACK";
                z->parent->parent->colour = "RED";
                z = z->parent->parent;
            } else {
                if (z == z->parent->right_child) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->colour = "BLACK";
                z->parent->parent->colour = "RED";
                rightRotate(z->parent->parent);
            }
        } else {
            // Симметричный случай
            Node *y = z->parent->parent->left_child;
            if (y->colour == "RED") {
                z->parent->colour = "BLACK";
                y->colour = "BLACK";
                z->parent->parent->colour = "RED";
                z = z->parent->parent;
            } else {
                if (z == z->parent->left_child) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->colour = "BLACK";
                z->parent->parent->colour = "RED";
                leftRotate(z->parent->parent);
            }
        }
    }
    root->colour = "BLACK";
}

void Black_Red_Tree::leftRotate(Node *x) {
    Node *y = x->right_child;
    x->right_child = y->left_child;
    if (y->left_child != nil) {
        y->left_child->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nil) {
        root = y;
    } else if (x == x->parent->left_child) {
        x->parent->left_child = y;
    } else {
        x->parent->right_child = y;
    }
    y->left_child = x;
    x->parent = y;
}

void Black_Red_Tree::rightRotate(Node *y) {
    Node *x = y->left_child;
    y->left_child = x->right_child;
    if (x->right_child != nil) {
        x->right_child->parent = y;
    }
    x->parent = y->parent;
    if (y->parent == nil) {
        root = x;
    } else if (y == y->parent->right_child) {
        y->parent->right_child = x;
    } else {
        y->parent->left_child = x;
    }
    x->right_child = y;
    y->parent = x;
}