#include <gtest/gtest.h>
#include "solution.hpp"

TEST(SumOfTwoTest, Simple) {
  std::vector<int> array = {1, 3, 5, 6, 10, 23, 30};
  ASSERT_EQ((SumOfTwo(array, 26) == Answer(3, 23)), true);
  ASSERT_EQ((SumOfTwo(array, 16) == Answer(6, 10)), true);
  ASSERT_EQ((SumOfTwo(array, 53) == Answer(23, 30)), true);
  ASSERT_EQ((SumOfTwo(array, 4) == Answer(1, 3)), true);
  std::vector<int> with_negative = {-12, -10, -4, 0, 2, 5, 10};
  ASSERT_EQ((SumOfTwo(with_negative, -16) == Answer(-12, -4)), true);
  ASSERT_EQ((SumOfTwo(with_negative, 0) == Answer(-10, 10)), true);
  ASSERT_EQ((SumOfTwo(with_negative, 10) == Answer(0, 10)), true);
}

TEST(SumOfTwoTest, NoSolution) {
  std::vector<int> array = {1, 4, 6, 10};
  ASSERT_EQ((SumOfTwo(array, 100) == Answer()), true);
  ASSERT_EQ((SumOfTwo(array, 6) == Answer()), true);
  ASSERT_EQ((SumOfTwo({1}, 2)) == Answer(), true);
}

TEST(SumOfTwoTest, MoreSolutions) {
  std::vector<int> two_sol = {1, 2, 4, 5};
  Answer result = SumOfTwo(two_sol, 6);
  bool check = (result == Answer(1, 5)) || (result == Answer(2, 4));
  ASSERT_EQ(check, true);
  std::vector<int> four_sol = {-10, 0, 1, 3, 4, 6, 7, 17};
  result = SumOfTwo(four_sol, 7);
  check = (result == Answer(-10, 17)) || (result == Answer(0, 7)) || (result == Answer(1, 6)) || (result == Answer(3, 4));
  ASSERT_EQ(check, true);
}