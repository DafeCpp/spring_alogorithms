
#include <gtest/gtest.h>

#include "splay_tree.hpp"

TEST(Test, Simple) {
  SplayTree tree;

  // Поиск ключа в пустом дереве
  ASSERT_EQ(tree.Find(52), false);
  ASSERT_EQ(tree.Find(0), false);
  ASSERT_EQ(tree.Find(-42), false);

  tree.Remove(67);
  ASSERT_EQ(tree.Find(67), false);  // tree []

  tree.Insert(52);
  ASSERT_EQ(tree.Find(52), true);  // tree [52]
  tree.Remove(52);
  ASSERT_EQ(tree.Find(52), false);  // tree []

  tree.Insert(52);
  tree.Insert(0);
  tree.Insert(67);
  tree.Insert(42);
  tree.Insert(-67);
  tree.Insert(69);
  // tree [52, 0, 67, 42, -67, 69]

  // Значения, которые есть в дереве
  ASSERT_EQ(tree.Find(52), true);
  ASSERT_EQ(tree.Find(-67), true);
  ASSERT_EQ(tree.Find(0), true);
  ASSERT_EQ(tree.Find(67), true);
  ASSERT_EQ(tree.Find(42), true);
  ASSERT_EQ(tree.Find(69), true);

  // Значения, которых нет в дереве
  ASSERT_EQ(tree.Find(4), false);
  ASSERT_EQ(tree.Find(17), false);
  ASSERT_EQ(tree.Find(-34), false);
  ASSERT_EQ(tree.Find(55), false);
  ASSERT_EQ(tree.Find(95), false);
  ASSERT_EQ(tree.Find(-56), false);

  tree.Remove(52);

  // tree [0, 67, 42, -67, 69]
  ASSERT_EQ(tree.Find(52), false);
  ASSERT_EQ(tree.Find(-67), true);
  ASSERT_EQ(tree.Find(0), true);
  ASSERT_EQ(tree.Find(67), true);

  tree.Remove(42);
  tree.Remove(-67);
  tree.Remove(69);
  tree.Remove(42);
  tree.Remove(0);
  tree.Remove(67);

  // tree []
  ASSERT_EQ(tree.Find(-67), false);
  ASSERT_EQ(tree.Find(0), false);
  ASSERT_EQ(tree.Find(67), false);
}

TEST(Test, ReapitingKeys) {
  SplayTree tree;

  tree.Insert(0);
  tree.Insert(67);
  tree.Insert(42);
  tree.Insert(-67);
  tree.Insert(69);
  tree.Insert(8);
  tree.Insert(8);
  tree.Insert(8);

  // tree [0, 67, 42, -67, 69, 8, 8]

  ASSERT_EQ(tree.Find(8), true);
  ASSERT_EQ(tree.Find(-67), true);

  tree.Remove(8);

  // tree [0, 67, 42, -67, 69, 8, 8]
  ASSERT_EQ(tree.Find(8), true);

  tree.Remove(8);

  // tree [0, 67, 42, -67, 69, 8]
  ASSERT_EQ(tree.Find(8), true);

  tree.Remove(8);

  // tree [0, 67, 42, -67, 69]
  ASSERT_EQ(tree.Find(8), false);
}
