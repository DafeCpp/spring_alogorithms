#include <gtest/gtest.h>

#include "HashTable.hpp"

TEST(HashTable, Simple) {
  HashTable table;
  table.add("first", 1);
  table.add("second", 2);
  ASSERT_EQ(table.get("first"), 1);
}

TEST(HashTable, DeleteTest) {
  HashTable table;
  table.add("first", 1);
  table.add("second", 2);
  table.add("second_full", 3);
  table.remove("second");
  ASSERT_EQ(table.get("second_full"), 3);
}

TEST(HashTable, FalseDelete) {
  HashTable table;
  table.add("first", 1);
  table.add("second", 2);
  EXPECT_THROW(table.remove("no_second"), std::runtime_error);
}

TEST(HashTable, FalseGet) {
  HashTable table;
  table.add("first", 1);
  table.add("second", 2);
  EXPECT_THROW(table.get("no_second"), std::runtime_error);
}

TEST(HashTable, ResizeTest1) {
  HashTable table;
  table.add("1", -8);
  table.add("2", 2);
  table.add("3", 1);
  table.add("4", 2);
  table.add("5", 1);
  table.add("5", 2);
  table.add("6", 1);
  table.add("7", 2);
  table.add("8", 1);
  table.add("9", 2);
  table.add("10", 1);
  table.add("11", 2);
  table.add("12", 1);
  table.add("13", 2);
  table.add("14", 1);
  table.add("15", 2);
  table.add("16", 1);
  table.add("17", 2);
  ASSERT_EQ(table.get("1"), -8);
}

TEST(HashTable, ResizeTest2) {
  HashTable table;
  table.add("1", -8);
  table.add("2", 2);
  table.add("3", 1);
  table.add("4", 2);
  table.add("5", 1);
  table.add("5", 2);
  table.add("6", 1);
  table.add("7", 2);
  table.add("8", 1);
  table.add("9", 2);
  table.add("10", 1);
  table.add("11", 2);
  table.add("12", 1);
  table.add("13", 2);
  table.add("14", 1);
  table.add("15", 2);
  table.add("16", 1);
  table.add("17", 19);
  ASSERT_EQ(table.get("17"), 19);
}

TEST(HashTable, AddSameKey) {
  HashTable table;
  table.add("first", 1);
  table.add("first", 2);
  ASSERT_EQ(table.get("first"), 2);
}