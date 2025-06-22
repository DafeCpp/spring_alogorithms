#include "hash_table.hpp"
#include <cassert>

int main() {
    HashTable ht;

    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(3, 300);

    int value = 0;
    assert(ht.find(1, value) && value == 100);
    assert(ht.find(2, value) && value == 200);
    assert(ht.find(3, value) && value == 300);
    assert(!ht.find(4, value));

    ht.insert(1, 111);
    assert(ht.find(1, value) && value == 111);

    assert(ht.erase(2));
    assert(!ht.find(2, value));
    assert(!ht.erase(2));

    return 0;
}