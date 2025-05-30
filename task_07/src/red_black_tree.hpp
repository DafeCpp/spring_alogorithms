#pragma once
#include <string>
#include <vector>
using namespace std;

class Black_Red_Tree {
private:
    struct Node {
        int key;
        string colour;
        Node *left_child;
        Node *right_child;
        Node *parent;

        Node(int key, string colour, Node *left_child, Node *right_child, Node *parent = nullptr)
            : key(key), colour(colour), left_child(left_child), right_child(right_child), parent(parent) {}
        
        bool operator!=(const Node &other) const {
            return this->key != other.key;
        }
    };

    Node *root;
    Node *nil;

public:
    Black_Red_Tree() {
        nil = new Node(0, "BLACK", nullptr, nullptr);
        root = nil;
    }

    void insert(int key);
    void del(int key);
    void fixInsert(Node *z);
    void fixDel(Node *x);
    void leftRotate(Node *x);
    void rightRotate(Node *y);
    Node* search(int key);
};