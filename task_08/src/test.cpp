#include "hash_table.hpp"
#include <gtest/gtest.h>

TEST(HashTableTests, AddElementAndContains) {
    HashTable<int, std::string> ht;
    ht.AddElement(1, "one");
    
    EXPECT_TRUE(ht.Contains(1));
    EXPECT_FALSE(ht.Contains(2));
}

TEST(HashTableTests, SearchOperation) {
    HashTable<int, std::string> ht;
    ht.AddElement(1, "one");
    
    EXPECT_EQ(ht.Search(1), "one");
    EXPECT_THROW(ht.Search(2), std::runtime_error);
}

TEST(HashTableTests, DelElementOperation) {
    HashTable<int, std::string> ht;
    ht.AddElement(1, "one");
    
    ht.DelElement(1);
    EXPECT_FALSE(ht.Contains(1));
    EXPECT_THROW(ht.DelElement(1), std::runtime_error);
}

TEST(HashTableTests, SubscriptOperator) {
    HashTable<int, std::string> ht;
    
    ht[3] = "three";
    EXPECT_EQ(ht[3], "three");
}

TEST(HashTableTests, RehashOperation) {
    HashTable<int, std::string> ht;
    
    // Добавляем элементы для проверки rehash
    for (int i = 0; i < 12; ++i) {
        ht.AddElement(i*i+i, std::to_string(i*i+i));
    }
    
    // Проверяем доступность элементов
    for (int i = 0; i < 12; ++i) {
        EXPECT_TRUE(ht.Contains(i*i+i));
        EXPECT_EQ(ht.Search(i*i+i), std::to_string(i*i+i));
    }
}