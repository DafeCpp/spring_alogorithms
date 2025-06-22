#ifndef HASH_TABLE_HPP
#define HASH_TABLE_HPP

#include <vector>
#include <list>

class HashTable {
public:
    HashTable(int size = 10);
    void insert(int key, int value);
    bool find(int key, int& value);
    bool erase(int key);

private:
    int size;
    std::vector<std::list<std::pair<int, int>>> table;
    int hash(int key);
};

#endif