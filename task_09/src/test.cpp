#include <gtest/gtest.h>

#include "RBTree.hpp"  // Убедитесь, что название файла совпадает с вашим

TEST(RBTreeTest, InsertAndFind) {
  RBtree tree;

  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(5);

  ASSERT_EQ(true, tree.Find(10));
  ASSERT_EQ(true, tree.Find(20));
  ASSERT_EQ(true, tree.Find(5));

  ASSERT_EQ(false, tree.Find(15));
  ASSERT_EQ(false, tree.Find(100));
  ASSERT_EQ(false, tree.Find(0));
}

TEST(RBTreeTest, SimpleRemove) {
  RBtree tree;

  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(5);
  tree.Remove(5);

  ASSERT_EQ(false, tree.Find(5));
  ASSERT_EQ(true, tree.Find(10));
  ASSERT_EQ(true, tree.Find(20));

  tree.Remove(10);
  ASSERT_EQ(false, tree.Find(10));
  ASSERT_EQ(true, tree.Find(20));
}

TEST(RBTreeTest, RemoveTwoChildren) {
  RBtree tree;
  tree.Insert(20);
  tree.Insert(10);
  tree.Insert(30);
  tree.Insert(5);
  tree.Insert(15);

  tree.Remove(10);

  ASSERT_EQ(false, tree.Find(10));
  ASSERT_EQ(true, tree.Find(20));
  ASSERT_EQ(true, tree.Find(30));
  ASSERT_EQ(true, tree.Find(5));
  ASSERT_EQ(true, tree.Find(15));
}

TEST(RBTreeTest, HardBalanceCheck) {
  RBtree tree;
  const int num_elements = 1000;

  for (int i = 1; i <= num_elements; ++i) {
    tree.Insert(i);
  }

  for (int i = 1; i <= num_elements; ++i) {
    ASSERT_EQ(true, tree.Find(i));
  }

  for (int i = 2; i <= num_elements; i += 2) {
    tree.Remove(i);
  }

  for (int i = 1; i <= num_elements; ++i) {
    if (i % 2 != 0) {
      ASSERT_EQ(true, tree.Find(i));
    } else {
      ASSERT_EQ(false, tree.Find(i));
    }
  }
}