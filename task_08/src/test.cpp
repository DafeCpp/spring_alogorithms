
#include <gtest/gtest.h>

#include "hash_table.hpp"

TEST(HashTableTest, Simple) {
  HashTable hash_table;
  hash_table.Add("f", 5);
  hash_table.Add("a", -1);
  hash_table.Add("b", 4);
  ASSERT_EQ(hash_table.Get("b"), 4);
  ASSERT_EQ(hash_table.Get("b"), 4);
  ASSERT_EQ(hash_table.Get("a"), -1);
  ASSERT_EQ(hash_table.Get("f"), 5);
}

TEST(HashTableTest, ExceptionLen) {
  ASSERT_THROW(HashTable hash_table(-1), std::length_error);
}

TEST(HashTableTest, ExceptionGet) {
  HashTable hash_table;
  hash_table.Add("f", 5);
  ASSERT_THROW(hash_table.Get("ff"), HashTableError);
  hash_table.Add("qw", 8);
  ASSERT_EQ(hash_table.Get("f"), 5);
  hash_table.Del("f");
  ASSERT_THROW(hash_table.Get("f"), HashTableError);
}

TEST(HashTableTest, ExceptionDel) {
  HashTable hash_table;
  hash_table.Add("f", 5);
  ASSERT_THROW(hash_table.Del("ff"), HashTableError);
}

TEST(HashTableTest, ChangeValue) {
  HashTable hash_table;
  hash_table.Add("42", 42);
  ASSERT_EQ(hash_table.Get("42"), 42);
  hash_table.Add("42", -42);
  ASSERT_EQ(hash_table.Get("42"), -42);
}

TEST(HashTableTest, RehashingWorks) {
  HashTable hash_table(1);
  hash_table.Add("one", 1);
  hash_table.Add("two", 2);
  hash_table.Add("three", 3);
  hash_table.Add("four", 4);

  ASSERT_EQ(hash_table.Get("one"), 1);
  ASSERT_EQ(hash_table.Get("two"), 2);
  ASSERT_EQ(hash_table.Get("three"), 3);
  ASSERT_EQ(hash_table.Get("four"), 4);
}

TEST(HashTableTest, ConstructorVector) {
  std::vector<std::pair<std::string, int>> data = {
      {"a", 1}, {"b", 2}, {"c", 3}};
  HashTable hash_table(data);

  ASSERT_EQ(hash_table.Get("a"), 1);
  ASSERT_EQ(hash_table.Get("b"), 2);
  ASSERT_EQ(hash_table.Get("c"), 3);
}

TEST(HashTableTest, AddAfterDel) {
  HashTable hash_table;
  hash_table.Add("d", 13);
  hash_table.Del("d");
  hash_table.Add("d", 0);
  ASSERT_EQ(hash_table.Get("d"), 0);
}