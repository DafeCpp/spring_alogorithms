#pragma once

#include <vector>
#include <list>
#include <utility>

class HashMap {
public:
    HashMap();
    ~HashMap();
    
    void Insert(int key, int value);
    int Get(int key);
    void Remove(int key);
    bool Contains(int key);

private:
    std::vector<std::list<std::pair<int, int>>> table;
    int size;
    int capacity;
    
    int hash(int key) const;
    void rehash();
};