#include <gtest/gtest.h>
#include "finder.hpp"

TEST(SubSeq, Simple) {
    ASSERT_EQ(FindSubSeq("abcsrlfcxdms", "lrf"), 5);
    ASSERT_EQ(FindSubSeq("smnkfwlvk", "nmsf"), -1);
}

TEST(SubSeq, Empty) {
    ASSERT_EQ(FindSubSeq("bibki", ""), 1);
}

TEST(SubSeq, Exact) {
    ASSERT_EQ(FindSubSeq("sixseven", "sixseven"), 1);
}

TEST(SubSeq, End) {
    ASSERT_EQ(FindSubSeq("abxde", "xde"), 3);
}

TEST(SubSeq, Start) {
    ASSERT_EQ(FindSubSeq("abca", "aabc"), 1);
}

TEST(SubSeq, Miss) {
    ASSERT_EQ(FindSubSeq("xyz", "abc"), -1);
}