
#include <gtest/gtest.h>

#include <vector>

#include "solution.hpp"

TEST(DaysToWarming, Case_One) {
  /*
   *   .-------------------x
   * 8 #           .-------x
   * 7 #           #
   * 6 # .--8--->###
   * 5 #1#     ##### .-.---x
   * 4 ###   .2##### #1#.-.x
   * 3 ###321#1##### ####1##
   * 2 #############1#######
   * 1 #####################
   *
   *   012345678901234567890
   */

  std::vector<float> temps{8, 4, 5, 2, 2, 2, 3, 2, 5, 5, 6,
                           6, 7, 1, 4, 3, 4, 3, 2, 3, 3};
  std::vector<int> exprected_res{0, 1, 8, 3, 2, 1, 2, 1, 2, 1, 2,
                                 1, 0, 1, 0, 1, 0, 0, 1, 0, 0};
  auto res = DaysToWarming(temps);

  ASSERT_EQ(res.size(), exprected_res.size());
  for (int i = 0; i < res.size(); ++i)
    ASSERT_EQ(res[i], exprected_res[i]) << "Result wrong at index " << i;
}
