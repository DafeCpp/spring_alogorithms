#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(HashTableBasic, EmptyInitially) {
  HashTable table;

  ASSERT_TRUE(table.Empty());
  ASSERT_EQ(table.Size(), 0);
  ASSERT_FALSE(table.Contains(1));
}

TEST(HashTableBasic, InsertOneElement) {
  HashTable table;

  table.Insert(10, 100);

  ASSERT_FALSE(table.Empty());
  ASSERT_EQ(table.Size(), 1);
  ASSERT_TRUE(table.Contains(10));
  ASSERT_EQ(table.Get(10), 100);
}

TEST(HashTableBasic, InsertSeveralElements) {
  HashTable table;

  table.Insert(1, 10);
  table.Insert(2, 20);
  table.Insert(3, 30);

  ASSERT_EQ(table.Size(), 3);

  ASSERT_EQ(table.Get(1), 10);
  ASSERT_EQ(table.Get(2), 20);
  ASSERT_EQ(table.Get(3), 30);
}

TEST(HashTableBasic, ContainsExistingKey) {
  HashTable table;

  table.Insert(42, 123);

  ASSERT_TRUE(table.Contains(42));
}

TEST(HashTableBasic, ContainsMissingKey) {
  HashTable table;

  table.Insert(42, 123);

  ASSERT_FALSE(table.Contains(43));
}

TEST(HashTableBasic, RemoveElement) {
  HashTable table;

  table.Insert(1, 10);
  table.Remove(1);

  ASSERT_FALSE(table.Contains(1));
  ASSERT_EQ(table.Size(), 0);
  ASSERT_TRUE(table.Empty());
}

TEST(HashTableBasic, RemoveOneOfSeveralElements) {
  HashTable table;

  table.Insert(1, 10);
  table.Insert(2, 20);
  table.Insert(3, 30);

  table.Remove(2);

  ASSERT_EQ(table.Size(), 2);

  ASSERT_TRUE(table.Contains(1));
  ASSERT_FALSE(table.Contains(2));
  ASSERT_TRUE(table.Contains(3));
}

TEST(HashTableBasic, NegativeKeys) {
  HashTable table;

  table.Insert(-10, 100);
  table.Insert(-20, 200);

  ASSERT_TRUE(table.Contains(-10));
  ASSERT_TRUE(table.Contains(-20));

  ASSERT_EQ(table.Get(-10), 100);
  ASSERT_EQ(table.Get(-20), 200);
}

TEST(HashTableBasic, ZeroKey) {
  HashTable table;

  table.Insert(0, 42);

  ASSERT_TRUE(table.Contains(0));
  ASSERT_EQ(table.Get(0), 42);
}

TEST(HashTableBasic, LargeKeys) {
  HashTable table;

  table.Insert(1000000000, 1);
  table.Insert(-1000000000, 2);

  ASSERT_EQ(table.Get(1000000000), 1);
  ASSERT_EQ(table.Get(-1000000000), 2);
}

TEST(HashTableCorner, DuplicateInsertUpdatesValue) {
  HashTable table;

  table.Insert(5, 10);
  table.Insert(5, 20);

  ASSERT_TRUE(table.Contains(5));
  ASSERT_EQ(table.Get(5), 20);
  ASSERT_EQ(table.Size(), 1);
}

TEST(HashTableCorner, RemoveMissingKey) {
  HashTable table;

  table.Insert(1, 10);

  table.Remove(100);

  ASSERT_EQ(table.Size(), 1);
  ASSERT_TRUE(table.Contains(1));
}

TEST(HashTableCorner, ManyElements) {
  HashTable table;

  for (int i = 0; i < 1000; ++i) {
    table.Insert(i, i * 10);
  }

  ASSERT_EQ(table.Size(), 1000);

  for (int i = 0; i < 1000; ++i) {
    ASSERT_TRUE(table.Contains(i));
    ASSERT_EQ(table.Get(i), i * 10);
  }
}

TEST(HashTableCorner, ManyInsertAndRemove) {
  HashTable table;

  for (int i = 0; i < 500; ++i) {
    table.Insert(i, i);
  }

  for (int i = 0; i < 250; ++i) {
    table.Remove(i);
  }

  ASSERT_EQ(table.Size(), 250);

  for (int i = 0; i < 250; ++i) {
    ASSERT_FALSE(table.Contains(i));
  }

  for (int i = 250; i < 500; ++i) {
    ASSERT_TRUE(table.Contains(i));
    ASSERT_EQ(table.Get(i), i);
  }
}

TEST(HashTableCorner, RehashPreservesData) {
  HashTable table;

  for (int i = 0; i < 200; ++i) {
    table.Insert(i, i + 1);
  }

  for (int i = 0; i < 200; ++i) {
    ASSERT_TRUE(table.Contains(i));
    ASSERT_EQ(table.Get(i), i + 1);
  }
}

TEST(HashTableCorner, EmptyAfterRemovingEverything) {
  HashTable table;

  for (int i = 0; i < 100; ++i) {
    table.Insert(i, i);
  }

  for (int i = 0; i < 100; ++i) {
    table.Remove(i);
  }

  ASSERT_TRUE(table.Empty());
  ASSERT_EQ(table.Size(), 0);
}