#include <gtest/gtest.h>

#include "balanced_bst.h"

TEST(BalancedBSTTest, FindsInsertedValues) {
  BalancedBST tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);

  EXPECT_TRUE(tree.Find(10));
  EXPECT_TRUE(tree.Find(5));
  EXPECT_TRUE(tree.Find(15));
  EXPECT_FALSE(tree.Find(7));
}

TEST(BalancedBSTTest, RemovesLeafAndRoot) {
  BalancedBST tree;
  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(15);
  tree.Insert(12);

  tree.Remove(5);
  EXPECT_FALSE(tree.Find(5));

  tree.Remove(10);
  EXPECT_FALSE(tree.Find(10));
  EXPECT_TRUE(tree.Find(12));
  EXPECT_TRUE(tree.Find(15));
}

TEST(BalancedBSTTest, IgnoresDuplicateInsertions) {
  BalancedBST tree;
  tree.Insert(3);
  tree.Insert(3);
  tree.Remove(3);
  EXPECT_FALSE(tree.Find(3));
}
