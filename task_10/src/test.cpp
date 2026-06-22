#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(Test, Simple) {
  HashTable table;

  ASSERT_EQ(table.Get(52), std::nullopt);
  ASSERT_EQ(table.Contains(52), false);

  table.Remove(52);
  table.Insert(0, 52);
  ASSERT_EQ(table.Get(0), 52);
  ASSERT_EQ(table.Contains(0), true);
}

TEST(Test, UpdateValue) {
  HashTable table;

  table.Insert(1, 42);
  ASSERT_EQ(table.Get(1), 42);

  table.Insert(1, 52);  // обновляем значение
  ASSERT_EQ(table.Get(1), 52);
  ASSERT_EQ(table.Contains(1), true);
}

TEST(Test, RemoveKey) {
  HashTable table;

  table.Insert(1, 67);
  table.Insert(2, 200);
  table.Insert(3, 0);

  ASSERT_EQ(table.Contains(2), true);
  table.Remove(2);
  ASSERT_EQ(table.Contains(2), false);
  ASSERT_EQ(table.Get(2), std::nullopt);

  ASSERT_EQ(table.Get(1), 67);
  ASSERT_EQ(table.Get(3), 0);
}

TEST(Test, Collisions) {
  HashTable table(5);  // маленький размер для коллизий

  // 1 % 5 = 1, 6 % 5 = 1, 11 % 5 = 1
  table.Insert(1, 52);
  table.Insert(6, 42);
  table.Insert(11, 67);

  ASSERT_EQ(table.Get(1), 52);
  ASSERT_EQ(table.Get(6), 42);
  ASSERT_EQ(table.Get(11), 67);
  ASSERT_EQ(table.Contains(1), true);
  ASSERT_EQ(table.Contains(6), true);
  ASSERT_EQ(table.Contains(11), true);

  table.Remove(6);

  ASSERT_EQ(table.Contains(6), false);
  ASSERT_EQ(table.Get(6), std::nullopt);
  ASSERT_EQ(table.Get(1), 52);
  ASSERT_EQ(table.Get(11), 67);
}

TEST(Test, NegativeKeys) {
  HashTable table;

  table.Insert(-5, 42);
  table.Insert(-10, 52);

  ASSERT_EQ(table.Get(-5), 42);
  ASSERT_EQ(table.Get(-10), 52);
  ASSERT_EQ(table.Contains(-5), true);

  table.Remove(-10);
  ASSERT_EQ(table.Contains(-10), false);
  ASSERT_EQ(table.Get(-10), std::nullopt);
  ASSERT_EQ(table.Get(-5), 42);
}