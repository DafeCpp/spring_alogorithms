#include <gtest/gtest.h>
#include "smallest.hpp"
#include <vector>

TEST(QuickSelect, ExamplesFromReadme) {
  std::vector<int> a1 = {7, 10, 4, 3, 20};
  EXPECT_EQ(Smallest(a1, 3), 7);

  std::vector<int> a2 = {7, 10, 4, 3, 20};
  EXPECT_EQ(Smallest(a2, 1), 3);

  std::vector<int> a3 = {7, 10, 4, 3, 20};
  EXPECT_EQ(Smallest(a3, 5), 20);
}

TEST(QuickSelect, DuplicatesAndNegatives) {
  std::vector<int> v = {5, -1, 5, 2, 2, -1};
  EXPECT_EQ(Smallest(v, 1), -1);
  EXPECT_EQ(Smallest(v, 2), -1);
  EXPECT_EQ(Smallest(v, 3), 2);
  EXPECT_EQ(Smallest(v, 6), 5);
}


TEST(QuickSelect, AlreadySorted) {
  std::vector<int> v = {1,2,3,4,5,6,7,8,9};
  EXPECT_EQ(Smallest(v,4), 4);
  EXPECT_EQ(Smallest(v, 9), 9);
}
