#include <gtest/gtest.h>

#include "permutation_substring.hpp"

TEST(PermutationSubstring, FindsExample) {
  EXPECT_EQ(FindPermutationSubstring("abcsrlfcxdms", "lrf"), 5);
}

TEST(PermutationSubstring, ReturnsMinusOneWhenAbsent) {
  EXPECT_EQ(FindPermutationSubstring("smnkfwlvk", "nmsf"), -1);
}
