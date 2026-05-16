#include <gtest/gtest.h>

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
