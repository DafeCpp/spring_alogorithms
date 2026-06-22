
#include <gtest/gtest.h>

#include <stdexcept>

#include "HashTable.h"

TEST(HashTable, InsertGetContains) {
  HashTable ht(10);
  ht.Insert(1, 10);
  ht.Insert(2, 20);
  ht.Insert(3, 30);

  EXPECT_TRUE(ht.Contains(1));
  EXPECT_TRUE(ht.Contains(2));
  EXPECT_TRUE(ht.Contains(3));

  EXPECT_EQ(ht.Get(1), 10);
  EXPECT_EQ(ht.Get(2), 20);
  EXPECT_EQ(ht.Get(3), 30);
}

TEST(HashTable, UpdateValue) {
  HashTable ht(10);
  ht.Insert(1, 10);
  EXPECT_EQ(ht.Get(1), 10);
  ht.Insert(1, 100);
  EXPECT_EQ(ht.Get(1), 100);
}

TEST(HashTable, RemoveAndExceptions) {
  HashTable ht(10);
  ht.Insert(5, 50);
  EXPECT_TRUE(ht.Contains(5));
  ht.Remove(5);
  EXPECT_FALSE(ht.Contains(5));
  EXPECT_THROW(ht.Get(5), std::out_of_range);
  EXPECT_THROW(ht.Get(999), std::out_of_range);
}

TEST(HashTable, ManyCollisions) {
  HashTable ht(1);  // all keys map to same bucket
  for (int i = 0; i < 20; ++i) ht.Insert(i, i * 10);
  for (int i = 0; i < 20; ++i) {
    EXPECT_TRUE(ht.Contains(i));
    EXPECT_EQ(ht.Get(i), i * 10);
  }

  for (int i = 0; i < 20; i += 2) ht.Remove(i);
  for (int i = 0; i < 20; ++i) {
    if (i % 2 == 0) {
      EXPECT_FALSE(ht.Contains(i));
      EXPECT_THROW(ht.Get(i), std::out_of_range);
    } else {
      EXPECT_TRUE(ht.Contains(i));
      EXPECT_EQ(ht.Get(i), i * 10);
    }
  }
}
