#include <gtest/gtest.h>

#include <string>
#include <utility>
#include <vector>

#include "task11.hpp"

using namespace std;

TEST(Task11Test, FromExample1) { EXPECT_EQ(func("abcsrlfcxdms", "lrf"), 5); }

TEST(Task11Test, FromExample2) { EXPECT_EQ(func("smnkfwlvk", "nmsf"), -1); }

TEST(Task11Test, FromExample3) { EXPECT_EQ(func("abcabc", "acb"), 1); }

TEST(Task11Test, NotFound) { EXPECT_EQ(func("abcdef", "xyz"), -1); }

TEST(Task11Test, ExactMatch) { EXPECT_EQ(func("hello", "hello"), 1); }

TEST(Task11Test, SingleCharacter) { EXPECT_EQ(func("abcdef", "d"), 4); }

TEST(Task11Test, MiddlePosition) { EXPECT_EQ(func("xyzabcdefxyz", "abc"), 4); }

TEST(Task11Test, RepeatedCharacters) {
  EXPECT_EQ(func("aaabbbccc", "abc"), -1);
}