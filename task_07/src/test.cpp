
#include <gtest/gtest.h>

#include "avl_tree.hpp"

TEST(AvlTest, Simple) {
  std::vector<std::pair<int, int>> pairs{std::pair<int, int>{5, 5},
                                         std::pair<int, int>{3, 4},
                                         std::pair<int, int>{9, 9}};
  AvlTree tree{pairs};
  ASSERT_EQ(tree[5], 5);
  ASSERT_EQ(tree[3], 4);
  ASSERT_EQ(tree[9], 9);
  EXPECT_THROW({ int a{tree[2]}; }, std::out_of_range);
}

TEST(AvlTest, AddDel) {
  std::vector<std::pair<int, int>> pairs{std::pair<int, int>{5, 5},
                                         std::pair<int, int>{3, 4},
                                         std::pair<int, int>{9, 9}};
  AvlTree tree{pairs};
  tree.Add(7, 1);
  ASSERT_EQ(tree[7], 1);
  tree.Del(5);
  tree.Del(3);
  tree.Add(3, 0);
  ASSERT_EQ(tree[3], 0);
  EXPECT_THROW({ int a{tree[5]}; }, std::out_of_range);
}

TEST(AvlCoutTest, Simple) {
  std::vector<std::pair<int, int>> pairs{std::pair<int, int>{5, 5},
                                         std::pair<int, int>{3, 4},
                                         std::pair<int, int>{9, 9}};
  AvlTree tree{pairs};
  tree.Add(7, 1);

  std::ostringstream oss;
  oss << tree;
  std::string expected = "{(3, 4), (5, 5), (7, 1), (9, 9)}";
  EXPECT_EQ(oss.str(), expected);
}

TEST(AvlCoutTest, Simple2) {
  AvlTree tree;
  tree.Add(3, 30);
  tree.Add(1, 10);
  tree.Add(4, 40);
  tree.Add(2, 20);

  std::ostringstream oss;
  oss << tree;
  std::string expected = "{(1, 10), (2, 20), (3, 30), (4, 40)}";
  EXPECT_EQ(oss.str(), expected);
}

TEST(AvlCoutTest, EmptyTreeOutput) {
  AvlTree empty_tree;
  std::ostringstream oss;
  oss << empty_tree;
  EXPECT_EQ(oss.str(), "{}");
}

TEST(AvlCoutTest, SingleElement) {
  AvlTree tree;
  tree.Add(5, 6);
  std::ostringstream oss;
  oss << tree;
  EXPECT_EQ(oss.str(), "{(5, 6)}");
}