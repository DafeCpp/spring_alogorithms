#include <gtest/gtest.h>

#include <get_terms.hpp>
#include <stdexcept>
#include <vector>

TEST(Test, Simple) {
  std::vector<int> v = {1, 2, 4};
  std::vector<int> v1 = {2, 7, 11, 15};
  std::vector<int> v2 = {3, 7, 12};
  std::vector<int> v3 = {-67, -42, 0, 52, 108, 252};
  std::vector<int> v4 = {2, 4};
  ASSERT_EQ(get_terms(v, 52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v, -52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v, 0), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v1, 9), std::make_pair(2, 7));
  ASSERT_EQ(get_terms(v2, 19), std::make_pair(7, 12));
  ASSERT_EQ(get_terms(v3, 10), std::make_pair(-42, 52));
  ASSERT_EQ(get_terms(v3, 1), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v4, 6), std::make_pair(2, 4));
}

TEST(Test, Empty) {
  std::vector<int> v_empty = {};
  ASSERT_EQ(get_terms(v_empty, 52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v_empty, -52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v_empty, 0), std::make_pair(-1, -1));
}

TEST(Test, Single) {
  std::vector<int> v_single = {0};
  ASSERT_EQ(get_terms(v_single, 52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v_single, -52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v_single, 0), std::make_pair(-1, -1));
}