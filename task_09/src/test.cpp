#include <gtest/gtest.h>

#include "search_tree.hpp"

TEST(SearchTree, InsertsFindsAndRemoves) {
  SearchTree tree;
  tree.Insert(5);
  tree.Insert(2);
  tree.Insert(8);
  EXPECT_TRUE(tree.Find(2));
  EXPECT_TRUE(tree.Find(5));
  EXPECT_FALSE(tree.Find(3));

  tree.Remove(5);
  EXPECT_FALSE(tree.Find(5));
  EXPECT_TRUE(tree.Find(2));
  EXPECT_TRUE(tree.Find(8));
}
