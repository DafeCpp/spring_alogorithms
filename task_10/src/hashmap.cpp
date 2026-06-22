#include "hashmap.hpp"
#include <functional>

HashMap::HashMap() : size(0), capacity(16) {
    table.resize(capacity);
}

HashMap::~HashMap() {}

int HashMap::hash(int key) const {
    return std::hash<int>{}(key) % capacity;
}

void HashMap::rehash() {
    int oldCapacity = capacity;
    capacity *= 2;
    std::vector<std::list<std::pair<int, int>>> newTable(capacity);
    
    for (int i = 0; i < oldCapacity; ++i) {
        for (auto& pair : table[i]) {
            int newIndex = std::hash<int>{}(pair.first) % capacity;
            newTable[newIndex].push_back(pair);
        }
    }
    
    table = std::move(newTable);
}

void HashMap::Insert(int key, int value) {
    if (size >= capacity * 0.75) {
        rehash();
    }
    
    int index = hash(key);
    
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            pair.second = value;
            return;
        }
    }
    
    table[index].push_back({key, value});
    ++size;
}

int HashMap::Get(int key) {
    int index = hash(key);
    
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return pair.second;
        }
    }
    
    return -1;
}

void HashMap::Remove(int key) {
    int index = hash(key);
    
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            --size;
            return;
        }
    }
}

bool HashMap::Contains(int key) {
    int index = hash(key);
    
    for (auto& pair : table[index]) {
        if (pair.first == key) {
            return true;
        }
    }
    
    return false;
}