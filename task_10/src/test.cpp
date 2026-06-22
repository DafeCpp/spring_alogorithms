#include <gtest/gtest.h>
#include "hashmap.hpp"

TEST(HashMapTest, InsertAndGet) {
    HashMap map;
    
    map.Insert(1, 10);
    map.Insert(2, 20);
    map.Insert(3, 30);
    
    ASSERT_EQ(map.Get(1), 10);
    ASSERT_EQ(map.Get(2), 20);
    ASSERT_EQ(map.Get(3), 30);
    ASSERT_EQ(map.Get(4), -1);
}

TEST(HashMapTest, Contains) {
    HashMap map;
    
    map.Insert(1, 10);
    map.Insert(2, 20);
    
    ASSERT_TRUE(map.Contains(1));
    ASSERT_TRUE(map.Contains(2));
    ASSERT_FALSE(map.Contains(3));
}

TEST(HashMapTest, Remove) {
    HashMap map;
    
    map.Insert(1, 10);
    map.Insert(2, 20);
    map.Insert(3, 30);
    
    ASSERT_TRUE(map.Contains(2));
    map.Remove(2);
    ASSERT_FALSE(map.Contains(2));
    ASSERT_EQ(map.Get(2), -1);
    ASSERT_TRUE(map.Contains(1));
    ASSERT_TRUE(map.Contains(3));
}

TEST(HashMapTest, UpdateValue) {
    HashMap map;
    
    map.Insert(1, 10);
    ASSERT_EQ(map.Get(1), 10);
    
    map.Insert(1, 100);
    ASSERT_EQ(map.Get(1), 100);
}

TEST(HashMapTest, CollisionHandling) {
    HashMap map;
    
    for (int i = 0; i < 100; ++i) {
        map.Insert(i, i * 10);
    }
    
    for (int i = 0; i < 100; ++i) {
        ASSERT_EQ(map.Get(i), i * 10);
    }
}

TEST(HashMapTest, RemoveNonExistent) {
    HashMap map;
    
    map.Insert(1, 10);
    map.Remove(5);
    ASSERT_TRUE(map.Contains(1));
    ASSERT_FALSE(map.Contains(5));
}

TEST(HashMapTest, RehashTest) {
    HashMap map;
    
    for (int i = 0; i < 1000; ++i) {
        map.Insert(i, i);
    }
    
    for (int i = 0; i < 1000; ++i) {
        ASSERT_EQ(map.Get(i), i);
    }
}
