#include <gtest/gtest.h>
#include "tree.hpp"

TEST(AVLTreeTest, InsertFindSimple) {
  AVLTree tree;
  std::vector<int> keys = {10, 20, 5, 15, 25, 2, 7};
  for (int k : keys) tree.Insert(k);

  for (int k : keys) EXPECT_TRUE(tree.Find(k));
  EXPECT_FALSE(tree.Find(0));
  EXPECT_FALSE(tree.Find(3));
  EXPECT_FALSE(tree.Find(8));
  EXPECT_FALSE(tree.Find(30));
}

TEST(AVLTreeTest, RemoveLeaf) {
  AVLTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  tree.Remove(5);
  EXPECT_FALSE(tree.Find(5));
  EXPECT_TRUE(tree.Find(10));
  EXPECT_TRUE(tree.Find(15));
}

TEST(AVLTreeTest, RemoveNodeWithOneChild) {
  AVLTree tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(2); // child of 5
  tree.Insert(15);

  tree.Remove(5);
  EXPECT_FALSE(tree.Find(5));
  EXPECT_TRUE(tree.Find(2));
  EXPECT_TRUE(tree.Find(10));
  EXPECT_TRUE(tree.Find(15));
}

TEST(AVLTreeTest, RemoveNodeWithTwoChildren) {
  AVLTree tree;
  std::vector<int> keys = {20, 10, 30, 5, 15, 25, 35};
  for (int k : keys) tree.Insert(k);

  tree.Remove(20); // root with two children
  EXPECT_FALSE(tree.Find(20));
  for (int k : keys) if (k != 20) EXPECT_TRUE(tree.Find(k));
}

TEST(AVLTreeTest, BulkInsertRemove) {
  AVLTree tree;
  for (int i = 1; i <= 100; ++i) tree.Insert(i);
  for (int i = 2; i <= 100; i += 2) tree.Remove(i);

  for (int i = 1; i <= 100; ++i) {
    if (i % 2 == 0) EXPECT_FALSE(tree.Find(i));
    else EXPECT_TRUE(tree.Find(i));
  }
}
