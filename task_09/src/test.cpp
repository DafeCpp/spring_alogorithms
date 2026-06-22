#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AVLTreeBasic, EmptyInitially) {
  AvlTree tree;
  ASSERT_TRUE(tree.Empty());
  ASSERT_EQ(tree.Size(), 0);
  ASSERT_FALSE(tree.Find(10));
}

TEST(AVLTreeBasic, InsertAndFind) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(5);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
  ASSERT_TRUE(tree.Find(5));
  ASSERT_FALSE(tree.Find(100));
}

TEST(AVLTreeBasic, SizeAfterInsert) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(5);

  ASSERT_EQ(tree.Size(), 3);
}

TEST(AVLTreeBasic, RemoveLeaf) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(20);

  tree.Remove(5);

  ASSERT_FALSE(tree.Find(5));
  ASSERT_EQ(tree.Size(), 2);
}

TEST(AVLTreeBasic, RemoveRoot) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(5);
  tree.Insert(20);

  tree.Remove(10);

  ASSERT_FALSE(tree.Find(10));
  ASSERT_EQ(tree.Size(), 2);
}

TEST(AVLTreeBalance, LeftHeavy) {
  AvlTree tree;

  tree.Insert(30);
  tree.Insert(20);
  tree.Insert(10);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
  ASSERT_TRUE(tree.Find(30));
  ASSERT_EQ(tree.Size(), 3);
}

TEST(AVLTreeBalance, RightHeavy) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(20);
  tree.Insert(30);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
  ASSERT_TRUE(tree.Find(30));
  ASSERT_EQ(tree.Size(), 3);
}

TEST(AVLTreeBalance, LeftRightRotation) {
  AvlTree tree;

  tree.Insert(30);
  tree.Insert(10);
  tree.Insert(20);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
  ASSERT_TRUE(tree.Find(30));
}

TEST(AVLTreeBalance, RightLeftRotation) {
  AvlTree tree;

  tree.Insert(10);
  tree.Insert(30);
  tree.Insert(20);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_TRUE(tree.Find(20));
  ASSERT_TRUE(tree.Find(30));
}

TEST(AVLTreeStress, IncreasingOrder) {
  AvlTree tree;

  for (int i = 0; i < 1000; ++i) {
    tree.Insert(i);
  }

  ASSERT_EQ(tree.Size(), 1000);

  for (int i = 0; i < 1000; ++i) {
    ASSERT_TRUE(tree.Find(i));
  }
}

TEST(AVLTreeStress, InsertAndRemove) {
  AvlTree tree;

  for (int i = 0; i < 500; ++i) {
    tree.Insert(i);
  }

  for (int i = 0; i < 250; ++i) {
    tree.Remove(i);
  }

  ASSERT_EQ(tree.Size(), 250);

  for (int i = 250; i < 500; ++i) {
    ASSERT_TRUE(tree.Find(i));
  }
}

TEST(AVLTreeEdge, RemoveNonExisting) {
  AvlTree tree;

  tree.Insert(10);
  tree.Remove(999);

  ASSERT_TRUE(tree.Find(10));
  ASSERT_EQ(tree.Size(), 1);
}