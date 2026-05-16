#include <gtest/gtest.h>

#include "permutation_substring.h"

TEST(PermutationSubstringTest, HandlesBasicExample) {
  EXPECT_EQ(FindPermutationSubstringStart("abcsrlfcxdms", "lrf"), 5);
}

TEST(PermutationSubstringTest, HandlesStartOfString) {
  EXPECT_EQ(FindPermutationSubstringStart("abcabc", "cab"), 1);
}

TEST(PermutationSubstringTest, HandlesEndOfString) {
  EXPECT_EQ(FindPermutationSubstringStart("xyzabc", "bca"), 4);
}

TEST(PermutationSubstringTest, HandlesSingleCharacter) {
  EXPECT_EQ(FindPermutationSubstringStart("a", "a"), 1);
}

TEST(PermutationSubstringTest, ReturnsMinusOneWhenMissing) {
  EXPECT_EQ(FindPermutationSubstringStart("smnkfwlvk", "nmsf"), -1);
}
