#include <gtest/gtest.h>

#include "find.hpp"

TEST(find_nums, simple) {
  std ::vector<int> seq{1, 2, 3, 4, 5};
  std ::vector<int> ans{find_nums(5, seq)};
  ASSERT_EQ(5, ans[0] + ans[1]);
}

TEST(find_nums, negative) {
  std ::vector<int> seq{-100, -10, -9, -8, -1};
  std ::vector<int> ans{find_nums(-9, seq)};
  ASSERT_EQ(-9, ans[0] + ans[1]);
}

TEST(find_nums, with_zeros) {
  std ::vector<int> seq{
      -15, 0, 0, 2, 8,
  };
  std ::vector<int> ans{find_nums(10, seq)};
  ASSERT_EQ(10, ans[0] + ans[1]);
}

TEST(find_nums, no_value) {
  std ::vector<int> seq{0, 0, 2, 8, -15};
  EXPECT_THROW(find_nums(60, seq), no_sum_num);
}

TEST(find_nums, empty) {
  std ::vector<int> seq(0);
  EXPECT_THROW(find_nums(60, seq), no_sum_num);
}