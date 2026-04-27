#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "nondecreasing_segment.h"

TEST(CanReachNonDecreasingSegmentTest, HandlesExample) {
  EXPECT_EQ(CanReachNonDecreasingSegment(
                {{1, 2, 3, 5},
                 {3, 1, 3, 2},
                 {4, 5, 2, 3},
                 {5, 5, 3, 2},
                 {4, 4, 3, 4}},
                {{1, 1}, {2, 5}, {4, 5}, {3, 5}, {1, 3}, {1, 5}}),
            (std::vector<std::string>{"Yes", "No", "Yes", "Yes", "Yes", "No"}));
}

TEST(CanReachNonDecreasingSegmentTest, HandlesSingleCell) {
  EXPECT_EQ(CanReachNonDecreasingSegment({{5}}, {{1, 1}}),
            (std::vector<std::string>{"Yes"}));
}

TEST(CanReachNonDecreasingSegmentTest, HandlesAllEqual) {
  EXPECT_EQ(CanReachNonDecreasingSegment({{5, 5, 5}, {5, 5, 5}, {5, 5, 5}},
                                         {{1, 3}, {2, 3}}),
            (std::vector<std::string>{"Yes", "Yes"}));
}
