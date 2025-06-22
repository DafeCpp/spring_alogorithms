#include "hash_table.hpp"

HashTable::HashTable(int size) : size(size), table(size) {}

int HashTable::hash(int key) {
    return key % size;
}

void HashTable::insert(int key, int value) {
    int index = hash(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            it->second = value;
            return;
        }
    }
    table[index].push_back({key, value});
}

bool HashTable::find(int key, int& value) {
    int index = hash(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            value = it->second;
            return true;
        }
    }
    return false;
}

bool HashTable::erase(int key) {
    int index = hash(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (it->first == key) {
            table[index].erase(it);
            return true;
        }
    }
    return false;
}