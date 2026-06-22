#include <gtest/gtest.h>

#include <stdexcept>

#include "hash_table.h"

TEST(HashTableTest, InsertsAndFindsValues) {
  HashTable table;
  table.Insert(1, 10);
  table.Insert(2, 20);

  EXPECT_TRUE(table.Contains(1));
  EXPECT_TRUE(table.Contains(2));
  EXPECT_EQ(table.Get(1), 10);
  EXPECT_EQ(table.Get(2), 20);
}

TEST(HashTableTest, UpdatesExistingKey) {
  HashTable table;
  table.Insert(5, 100);
  table.Insert(5, 200);

  EXPECT_EQ(table.Get(5), 200);
}

TEST(HashTableTest, RemovesKeys) {
  HashTable table;
  table.Insert(7, 70);
  table.Insert(23, 230);
  table.Remove(7);

  EXPECT_FALSE(table.Contains(7));
  EXPECT_TRUE(table.Contains(23));
}

TEST(HashTableTest, HandlesMissingKey) {
  HashTable table;
  EXPECT_FALSE(table.Contains(42));
  EXPECT_THROW(table.Get(42), std::out_of_range);
}

TEST(HashTableTest, HandlesNegativeKeys) {
  HashTable table;
  table.Insert(-1, 10);
  table.Insert(-2147483647 - 1, 20);
  table.Insert(-100, 30);

  EXPECT_TRUE(table.Contains(-1));
  EXPECT_TRUE(table.Contains(-2147483647 - 1));
  EXPECT_TRUE(table.Contains(-100));
  EXPECT_EQ(table.Get(-1), 10);
  EXPECT_EQ(table.Get(-2147483647 - 1), 20);
  EXPECT_EQ(table.Get(-100), 30);

  table.Remove(-1);
  EXPECT_FALSE(table.Contains(-1));
  EXPECT_TRUE(table.Contains(-100));
}

TEST(HashTableTest, MixesPositiveAndNegativeKeys) {
  HashTable table;
  table.Insert(5, 50);
  table.Insert(-5, -50);

  EXPECT_TRUE(table.Contains(5));
  EXPECT_TRUE(table.Contains(-5));
  EXPECT_EQ(table.Get(5), 50);
  EXPECT_EQ(table.Get(-5), -50);
}

TEST(HashTableTest, SurvivesRehashAndRetainsAllEntries) {
  HashTable table;
  constexpr int kCount = 1000;
  for (int i = 0; i < kCount; ++i) {
    table.Insert(i, i * 3);
  }
  for (int i = 0; i < kCount; ++i) {
    ASSERT_TRUE(table.Contains(i));
    EXPECT_EQ(table.Get(i), i * 3);
  }

  for (int i = 0; i < kCount; i += 2) {
    table.Remove(i);
  }
  for (int i = 0; i < kCount; ++i) {
    if (i % 2 == 0) {
      EXPECT_FALSE(table.Contains(i));
    } else {
      EXPECT_EQ(table.Get(i), i * 3);
    }
  }
}
