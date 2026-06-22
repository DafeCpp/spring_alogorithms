#include <gtest/gtest.h>
#include "substring.hpp"

TEST(SubstringTest, Example1) {
    std::string S = "smnkfwlvk";
    std::string P = "nmsf";
    ASSERT_EQ(findPermutationSubstring(S, P), -1);
}

TEST(SubstringTest, Example2) {
    std::string S = "abcabc";
    std::string P = "cab";
    ASSERT_EQ(findPermutationSubstring(S, P), 1);
}

TEST(SubstringTest, ExactMatch) {
    std::string S = "abcdef";
    std::string P = "abc";
    ASSERT_EQ(findPermutationSubstring(S, P), 1);
}

TEST(SubstringTest, ExactMatchEnd) {
    std::string S = "abcdef";
    std::string P = "def";
    ASSERT_EQ(findPermutationSubstring(S, P), 4);
}

TEST(SubstringTest, PermutationAtStart) {
    std::string S = "bacdef";
    std::string P = "abc";
    ASSERT_EQ(findPermutationSubstring(S, P), 1);
}

TEST(SubstringTest, PermutationInMiddle) {
    std::string S = "xyzabcxyz";
    std::string P = "cab";
    ASSERT_EQ(findPermutationSubstring(S, P), 4);
}

TEST(SubstringTest, NotFound) {
    std::string S = "abcdef";
    std::string P = "xyz";
    ASSERT_EQ(findPermutationSubstring(S, P), -1);
}

TEST(SubstringTest, SingleCharFound) {
    std::string S = "abcdef";
    std::string P = "d";
    ASSERT_EQ(findPermutationSubstring(S, P), 4);
}

TEST(SubstringTest, SingleCharNotFound) {
    std::string S = "abcdef";
    std::string P = "z";
    ASSERT_EQ(findPermutationSubstring(S, P), -1);
}

TEST(SubstringTest, EmptyP) {
    std::string S = "abcdef";
    std::string P = "";
    ASSERT_EQ(findPermutationSubstring(S, P), 1);
}

TEST(SubstringTest, EmptyS) {
    std::string S = "";
    std::string P = "abc";
    ASSERT_EQ(findPermutationSubstring(S, P), -1);
}

TEST(SubstringTest, BothEmpty) {
    std::string S = "";
    std::string P = "";
    ASSERT_EQ(findPermutationSubstring(S, P), 1);
}
