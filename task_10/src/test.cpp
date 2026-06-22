#include <gtest/gtest.h>

#include "task10.hpp"

TEST(HashTableTests, InsertAndGet) {
  HashTable ht;
  ht.Insert(1, 100);

  ht.Insert(2, 200);

  ASSERT_TRUE(ht.Contains(1));
  ASSERT_TRUE(ht.Contains(2));
  ASSERT_EQ(100, ht.Get(1));
  ASSERT_EQ(200, ht.Get(2));
}

TEST(HashTableTests, UpdateExistingKey) {
  HashTable ht;
  ht.Insert(5, 500);
  ht.Insert(5, 999);

  ASSERT_EQ(999, ht.Get(5));
}

TEST(HashTableTests, RemoveElements) {
  HashTable ht;
  ht.Insert(10, 1000);
  ASSERT_TRUE(ht.Contains(10));

  ht.Remove(10);
  ASSERT_FALSE(ht.Contains(10));
  ASSERT_THROW(ht.Get(10), std::out_of_range);
}

TEST(HashTableTests, GetNonExistentKeyThrows) {
  HashTable ht;
  ASSERT_THROW(ht.Get(404), std::out_of_range);
}

TEST(HashTableTests, ForceResize) {
  HashTable ht(2);

  for (int i = 0; i < 20; ++i) {
    ht.Insert(i, i * 10);
  }

  for (int i = 0; i < 20; ++i) {
    ASSERT_TRUE(ht.Contains(i));
    ASSERT_EQ(i * 10, ht.Get(i));
  }
}
