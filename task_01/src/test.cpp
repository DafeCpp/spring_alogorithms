#include <gtest/gtest.h>

#include <get_terms.hpp>
#include <stdexcept>

TEST(Test, Simple) {
  std::vector<int> v = {1, 2, 4};
  ASSERT_EQ(get_terms(v, 52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v, -52), std::make_pair(-1, -1));
  ASSERT_EQ(get_terms(v, 0), std::make_pair(-1, -1));
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