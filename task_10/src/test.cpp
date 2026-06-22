#include <gtest/gtest.h>

#include "task10.hpp"

TEST(HashTableTest, InsertAndGet) {
  HashTable ht;
  ht.Insert(5, 50);
  ht.Insert(10, 100);

  ASSERT_TRUE(ht.Contains(5));
  ASSERT_EQ(ht.Get(5), 50);
  ASSERT_EQ(ht.Get(10), 100);
}

TEST(HashTableTest, UpdateValue) {
  HashTable ht;
  ht.Insert(7, 70);
  ht.Insert(7, 77);

  ASSERT_EQ(ht.Get(7), 77);
}

TEST(HashTableTest, RemoveKey) {
  HashTable ht;
  ht.Insert(3, 30);
  ht.Remove(3);

  ASSERT_FALSE(ht.Contains(3));
}

TEST(HashTableTest, NegativeKeys) {
  HashTable ht;
  ht.Insert(-5, 500);

  ASSERT_TRUE(ht.Contains(-5));
  ASSERT_EQ(ht.Get(-5), 500);
}

TEST(HashTableTest, CollisionHandling) {
  HashTable ht;
  ht.Insert(1, 10);
  ht.Insert(10008, 80);  // Попадет в тот же бакет, если размер 10007

  ASSERT_TRUE(ht.Contains(1));
  ASSERT_TRUE(ht.Contains(10008));
  ASSERT_EQ(ht.Get(1), 10);
  ASSERT_EQ(ht.Get(10008), 80);
}
