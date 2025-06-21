
#include <gtest/gtest.h>

#include <optional>

#include "HashTable.hpp"

class HashTableTest : public ::testing::Test {
 protected:
  HashTable<int> ht;
};

TEST_F(HashTableTest, InsertAndFind) {
  ht.insert("apple", 10);
  ht.insert("banana", 20);
  ht.insert("orange", 30);

  auto res = ht.find("apple");
  ASSERT_TRUE(res.has_value());
  EXPECT_EQ(res.value(), 10);

  res = ht.find("banana");
  ASSERT_TRUE(res.has_value());
  EXPECT_EQ(res.value(), 20);

  res = ht.find("orange");
  ASSERT_TRUE(res.has_value());
  EXPECT_EQ(res.value(), 30);
}

TEST_F(HashTableTest, FindNonExistentKey) {
  ht.insert("apple", 10);
  auto res = ht.find("pear");
  EXPECT_FALSE(res.has_value());
}

TEST_F(HashTableTest, InsertOverwriteValue) {
  ht.insert("apple", 10);
  ht.insert("apple", 50);

  auto res = ht.find("apple");
  ASSERT_TRUE(res.has_value());
  EXPECT_EQ(res.value(), 50);
}

TEST_F(HashTableTest, EraseExistingKey) {
  ht.insert("apple", 10);
  ht.insert("banana", 20);

  bool erased = ht.erase("apple");
  EXPECT_TRUE(erased);

  auto res = ht.find("apple");
  EXPECT_FALSE(res.has_value());

  res = ht.find("banana");
  ASSERT_TRUE(res.has_value());
  EXPECT_EQ(res.value(), 20);
}

TEST_F(HashTableTest, EraseNonExistentKey) {
  ht.insert("apple", 10);

  bool erased = ht.erase("pear");
  EXPECT_FALSE(erased);
}

TEST_F(HashTableTest, RehashTriggered) {
  HashTable<int> small_ht(2);
  small_ht.insert("key1", 1);
  small_ht.insert("key2", 2);

  EXPECT_TRUE(small_ht.find("key1").has_value());
  EXPECT_TRUE(small_ht.find("key2").has_value());

  small_ht.insert("key3", 3);
  EXPECT_TRUE(small_ht.find("key3").has_value());
}

TEST_F(HashTableTest, InsertManyAndFindAll) {
  for (int i = 0; i < 1000; ++i) {
    ht.insert("key" + std::to_string(i), i);
  }
  for (int i = 0; i < 1000; ++i) {
    auto val = ht.find("key" + std::to_string(i));
    ASSERT_TRUE(val.has_value());
    EXPECT_EQ(val.value(), i);
  }
}