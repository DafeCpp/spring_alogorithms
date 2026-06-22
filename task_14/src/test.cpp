#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "spreadsheet.hpp"

TEST(CanReachNonDecreasingSegment, HandlesExample) {
  EXPECT_EQ(AnswerSortedColumnQueries(
                {{1, 2, 3, 5},
                 {3, 1, 3, 2},
                 {4, 5, 2, 3},
                 {5, 5, 3, 2},
                 {4, 4, 3, 4}},
                {{1, 1}, {2, 5}, {4, 5}, {3, 5}, {1, 3}, {1, 5}}),
            (std::vector<std::string>{"Yes", "No", "Yes", "Yes", "Yes", "No"}));
}

TEST(CanReachNonDecreasingSegment, HandlesSingleCell) {
  EXPECT_EQ(AnswerSortedColumnQueries({{5}}, {{1, 1}}),
            (std::vector<std::string>{"Yes"}));
}
