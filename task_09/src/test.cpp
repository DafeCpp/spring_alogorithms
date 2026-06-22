#include <gtest/gtest.h>

#include "task9.hpp"

TEST(TreapTest, SimpleInsertAndFind) {
  Treap tree;
  tree.Insert(5);
  tree.Insert(3);
  tree.Insert(8);

  ASSERT_TRUE(tree.Find(5));
  ASSERT_TRUE(tree.Find(3));
  ASSERT_TRUE(tree.Find(8));
  ASSERT_FALSE(tree.Find(10));
}

TEST(TreapTest, SimpleRemove) {
  Treap tree;
  tree.Insert(10);
  tree.Insert(20);

  ASSERT_TRUE(tree.Find(10));
  tree.Remove(10);
  ASSERT_FALSE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
}

TEST(TreapTest, DuplicateInsert) {
  Treap tree;
  tree.Insert(7);
  tree.Insert(7);

  ASSERT_TRUE(tree.Find(7));
  tree.Remove(7);
  ASSERT_FALSE(tree.Find(7));
}

TEST(TreapTest, RemoveNonExisting) {
  Treap tree;
  tree.Insert(1);
  tree.Remove(5);

  ASSERT_TRUE(tree.Find(1));
}

TEST(TreapTest, OrderIndependence) {
  Treap tree;
  tree.Insert(15);
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(5);

  ASSERT_TRUE(tree.Find(5));
  ASSERT_TRUE(tree.Find(15));
}
