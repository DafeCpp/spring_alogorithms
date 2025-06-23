
#include <gtest/gtest.h>

#include "tree.hpp"

TEST(SplayTree, Simple) {
  SplayTree tree;

  tree.Insert(0, 0);

  ASSERT_EQ(tree.SearchExact(0), 0);

  tree.Insert(1, 1);
  tree.Insert(2, 2);
  tree.Insert(3, 3);
  tree.Insert(4, 4);

  ASSERT_EQ(tree.SearchExact(1), 1);
  ASSERT_EQ(tree.SearchExact(2), 2);
  ASSERT_EQ(tree.SearchExact(3), 3);
  ASSERT_EQ(tree.SearchExact(4), 4);

  ASSERT_EQ(tree.SearchMin().second, 0);
  ASSERT_EQ(tree.SearchMax().second, 4);
}

TEST(SplayTree, SimpleDelete) {
  SplayTree tree;

  tree.Insert(0, 0);

  ASSERT_EQ(tree.SearchExact(0), 0);

  tree.Insert(1, 1);
  tree.Insert(2, 2);
  tree.Insert(3, 3);
  tree.Insert(4, 4);

  ASSERT_EQ(tree.SearchExact(1), 1);
  ASSERT_EQ(tree.SearchExact(2), 2);
  ASSERT_EQ(tree.SearchExact(3), 3);
  ASSERT_EQ(tree.SearchExact(4), 4);

  ASSERT_EQ(tree.SearchMin().second, 0);
  ASSERT_EQ(tree.SearchMax().second, 4);

  tree.Delete(0);

  ASSERT_EQ(tree.SearchExact(1), 1);
  ASSERT_EQ(tree.SearchExact(2), 2);
  ASSERT_EQ(tree.SearchExact(3), 3);
  ASSERT_EQ(tree.SearchExact(4), 4);

  ASSERT_EQ(tree.SearchMin().second, 1);
  ASSERT_EQ(tree.SearchMax().second, 4);

  tree.Delete(3);
  tree.Delete(4);

  ASSERT_EQ(tree.SearchExact(1), 1);
  ASSERT_EQ(tree.SearchExact(2), 2);

  ASSERT_EQ(tree.SearchMin().second, 1);
  ASSERT_EQ(tree.SearchMax().second, 2);
}
