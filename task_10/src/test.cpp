#include <gtest/gtest.h>

#include "hashTable.hpp"
TEST(HashTableTest, Basic) {
  HashTable ht;

  ht.Insert(1, 100);
  ht.Insert(2, 200);
  ht.Insert(3, 300);
  ASSERT_EQ(true, ht.Contains(1));
  ASSERT_EQ(true, ht.Contains(2));
  ASSERT_EQ(true, ht.Contains(3));
  ASSERT_EQ(false, ht.Contains(4));
  ASSERT_EQ(false, ht.Contains(-1));
}
TEST(HashTableTest, Basicv2) {
  HashTable ht;
  ht.Insert(10, 1000);
  ht.Insert(20, 2000);
  ASSERT_EQ(1000, ht.Get(10));
  ASSERT_EQ(2000, ht.Get(20));
  ht.Insert(10, 9999);
  ASSERT_EQ(9999, ht.Get(10));
  ASSERT_THROW(ht.Get(50), std::runtime_error);
}
TEST(HashTableTest, BasicRemove) {
  HashTable ht;
  ht.Insert(5, 50);
  ht.Insert(15, 150);
  ht.Insert(25, 250);
  ASSERT_EQ(true, ht.Contains(15));
  ht.Remove(15);
  ASSERT_EQ(false, ht.Contains(15));
  ASSERT_EQ(true, ht.Contains(5));
  ASSERT_EQ(true, ht.Contains(25));
  ASSERT_NO_THROW(ht.Remove(999));
}
TEST(HashTableTest, JustKys) {
  HashTable ht(4);
  const int num_elements = 1000;
  for (int i = 0; i < num_elements; ++i) {
    ht.Insert(i, i * 10);
  }
  for (int i = 0; i < num_elements; ++i) {
    ASSERT_EQ(true, ht.Contains(i));
    ASSERT_EQ(i * 10, ht.Get(i));
  }
  for (int i = 0; i < num_elements; i += 2) {
    ht.Remove(i);
  }
  for (int i = 0; i < num_elements; ++i) {
    if (i % 2 != 0) {
      ASSERT_EQ(true, ht.Contains(i));
    } else {
      ASSERT_EQ(false, ht.Contains(i));
    }
  }
}
