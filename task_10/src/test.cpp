#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(HashTable, InsertsGetsUpdatesAndRemoves) {
  HashTable table;
  table.Insert(1, 10);
  table.Insert(9, 90);
  EXPECT_TRUE(table.Contains(1));
  EXPECT_EQ(table.Get(1), 10);
  table.Insert(1, 11);
  EXPECT_EQ(table.Get(1), 11);
  table.Remove(1);
  EXPECT_FALSE(table.Contains(1));
  EXPECT_TRUE(table.Contains(9));
}
