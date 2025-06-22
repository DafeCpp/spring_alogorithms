#include "avltree.hpp"
#include <cassert>
#include <iostream>

int main() {
    AVLTree tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    assert(tree.search(10));
    assert(tree.search(20));
    assert(tree.search(30));
    assert(!tree.search(5));
    tree.remove(20);
    assert(!tree.search(20));
    tree.insert(25);
    tree.insert(15);
    tree.insert(5);
    assert(tree.search(25));
    assert(tree.search(15));
    assert(tree.search(5));
    tree.remove(10);
    assert(!tree.search(10));
    tree.insert(100);
    tree.remove(100);
    assert(!tree.search(100));
    return 0;
}