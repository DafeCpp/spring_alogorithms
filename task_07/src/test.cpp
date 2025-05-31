
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

TEST(AvlIteratorTest, IterationOrder) {
  std::vector<std::pair<int, int>> pairs{{5, 5}, {3, 3}, {7, 7}, {2, 2},
                                         {4, 4}, {6, 6}, {8, 8}};
  AvlTree tree(pairs);

  std::vector<std::pair<int, int>> result;
  for (const auto& kv : tree) {
    result.push_back(kv);
  }

  std::vector<std::pair<int, int>> expected{{2, 2}, {3, 3}, {4, 4}, {5, 5},
                                            {6, 6}, {7, 7}, {8, 8}};

  EXPECT_EQ(result, expected);
}

TEST(AvlIteratorTest, EmptyTree) {
  AvlTree empty_tree;
  std::vector<std::pair<int, int>> result;
  for (const auto& kv : empty_tree) {
    result.push_back(kv);
  }
  EXPECT_TRUE(result.empty());
}

TEST(AvlIteratorTest, SingleElement) {
  AvlTree tree;
  tree.Add(5, 6);
  std::vector<std::pair<int, int>> result;
  for (const auto& kv : tree) {
    result.push_back(kv);
  }
  EXPECT_EQ(result.size(), 1);
  EXPECT_EQ(result[0].first, 5);
  EXPECT_EQ(result[0].second, 6);
}

TEST(AvlIteratorTest, MixedOperations) {
  AvlTree tree;
  tree.Add(5, 5);
  tree.Add(3, 3);
  tree.Add(7, 7);

  std::vector<std::pair<int, int>> result;
  for (const auto& kv : tree) {
    result.push_back(kv);
  }

  std::vector<std::pair<int, int>> expected{{3, 3}, {5, 5}, {7, 7}};

  EXPECT_EQ(result, expected);

  tree.Del(3);

  result.clear();
  for (const auto& kv : tree) {
    result.push_back(kv);
  }

  expected = {{5, 5}, {7, 7}};

  EXPECT_EQ(result, expected);
}