
#include <gtest/gtest.h>

#include "days_before_hot.hpp"

TEST(first_test, ints) {
  std::vector<double> temp{5, 7, 5, 3, 10, 0, 2, -1, 3};
  std::vector<int> ans{1, 3, 2, 1, 0, 1, 2, 1, 0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}

TEST(second_test, doubles) {
  std::vector<double> temp{5.1, 7.656, 5.0, 3, 10, -729.3, 2, -1.4, 3.2};
  std::vector<int> ans{1, 3, 2, 1, 0, 1, 2, 1, 0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}

TEST(third_test, no_hot) {
  std::vector<double> temp{5, 4.7, 4.3, 3, 2, 1.3};
  std::vector<int> ans{0, 0, 0, 0, 0, 0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}

TEST(fourth_test, four) {
  std::vector<double> temp{5, 4, 3, 2, 1, 10};
  std::vector<int> ans{5, 4, 3, 2, 1, 0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}

TEST(fifth_test, one_number) {
  std::vector<double> temp{1};
  std::vector<int> ans{0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}

TEST(sixth_test, same_values) {
  std::vector<double> temp{1, 1, 2, 2, 5, 1, 7};
  std::vector<int> ans{2, 1, 2, 1, 2, 1, 0};
  ASSERT_EQ(DaysBeforeHot(temp), ans);
}