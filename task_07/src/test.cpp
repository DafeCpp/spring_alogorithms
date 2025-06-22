
#include <gtest/gtest.h>

#include <algorithm>
#include <iostream>
#include <vector>

#include "AVLTree.hpp"

class AVLTreeTest : public ::testing::Test {
 protected:
  AVLTree tree;

  void collectInorder(std::vector<int>& out) {}
};

TEST_F(AVLTreeTest, InsertAndFind) {
  tree.insert(10);
  tree.insert(20);
  tree.insert(5);

  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(20));
  EXPECT_TRUE(tree.find(5));
  EXPECT_FALSE(tree.find(15));
}

TEST_F(AVLTreeTest, InsertDuplicates) {
  tree.insert(10);
  tree.insert(10);
  tree.insert(10);

  EXPECT_TRUE(tree.find(10));
}

TEST_F(AVLTreeTest, EraseLeaf) {
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.erase(5);

  EXPECT_FALSE(tree.find(5));
  EXPECT_TRUE(tree.find(10));
  EXPECT_TRUE(tree.find(15));
}

TEST_F(AVLTreeTest, EraseNodeWithOneChild) {
  tree.insert(10);
  tree.insert(5);
  tree.insert(7);
  tree.erase(5);

  EXPECT_FALSE(tree.find(5));
  EXPECT_TRUE(tree.find(7));
  EXPECT_TRUE(tree.find(10));
}

TEST_F(AVLTreeTest, EraseNodeWithTwoChildren) {
  tree.insert(10);
  tree.insert(5);
  tree.insert(15);
  tree.insert(12);
  tree.insert(18);
  tree.erase(15);

  EXPECT_FALSE(tree.find(15));
  EXPECT_TRUE(tree.find(12));
  EXPECT_TRUE(tree.find(18));
  EXPECT_TRUE(tree.find(10));
}

TEST_F(AVLTreeTest, BalanceProperty) {
  for (int i = 1; i <= 1000; ++i) {
    tree.insert(i);
  }

  for (int i = 1; i <= 1000; ++i) {
    EXPECT_TRUE(tree.find(i));
  }
}
