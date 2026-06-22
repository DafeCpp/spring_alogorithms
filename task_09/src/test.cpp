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

TEST(BalancedBSTTest, FindOnEmptyTreeReturnsFalse) {
  BalancedBST tree;
  EXPECT_FALSE(tree.Find(42));
  EXPECT_FALSE(tree.Find(0));
  EXPECT_FALSE(tree.Find(-1));
}

TEST(BalancedBSTTest, RemoveNonExistentKeyIsNoop) {
  BalancedBST tree;
  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);

  tree.Remove(99);
  tree.Remove(-5);
  tree.Remove(15);

  EXPECT_TRUE(tree.Find(10));
  EXPECT_TRUE(tree.Find(20));
  EXPECT_TRUE(tree.Find(30));
}

TEST(BalancedBSTTest, RemoveOnEmptyTreeDoesNotCrash) {
  BalancedBST tree;
  tree.Remove(1);
  EXPECT_FALSE(tree.Find(1));
}

TEST(BalancedBSTTest, StaysCorrectAfterManyMixedOperations) {
  BalancedBST tree;
  for (int i = 0; i < 1000; ++i) {
    tree.Insert(i);
  }
  for (int i = 0; i < 1000; ++i) {
    EXPECT_TRUE(tree.Find(i));
  }
  for (int i = 0; i < 1000; i += 2) {
    tree.Remove(i);
  }
  for (int i = 0; i < 1000; ++i) {
    if (i % 2 == 0) {
      EXPECT_FALSE(tree.Find(i));
    } else {
      EXPECT_TRUE(tree.Find(i));
    }
  }

  for (int i = -500; i < 0; ++i) {
    tree.Insert(i);
  }
  for (int i = -500; i < 0; ++i) {
    EXPECT_TRUE(tree.Find(i));
  }
}
