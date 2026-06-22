#include <gtest/gtest.h>

#include "find_subsequence.hpp"

TEST(FindSubsequenceBasic, Example1) {
  ASSERT_EQ(FindSubsequence("abcsrlfcxdms", "lrf"), 5);
}

TEST(FindSubsequenceBasic, Example2) {
  ASSERT_EQ(FindSubsequence("smnkfwlvk", "nmsf"), -1);
}

TEST(FindSubsequenceBasic, Example3) {
  ASSERT_EQ(FindSubsequence("abcabc", "cab"), 1);
}

TEST(FindSubsequenceBasic, ExactMatch) {
  ASSERT_EQ(FindSubsequence("abc", "abc"), 1);
}

TEST(FindSubsequenceBasic, PermutationMatch) {
  ASSERT_EQ(FindSubsequence("cba", "abc"), 1);
}

TEST(FindSubsequenceBasic, MatchInMiddle) {
  ASSERT_EQ(FindSubsequence("xxbacyy", "abc"), 3);
}

TEST(FindSubsequenceBasic, RepeatedCharacters) {
  ASSERT_EQ(FindSubsequence("aabcc", "aba"), 1);
}

TEST(FindSubsequenceBasic, SingleCharacter) {
  ASSERT_EQ(FindSubsequence("abcdef", "d"), 4);
}

TEST(FindSubsequenceBasic, SingleCharacterMissing) {
  ASSERT_EQ(FindSubsequence("abcdef", "z"), -1);
}

TEST(FindSubsequenceBasic, MatchAtEnd) {
  ASSERT_EQ(FindSubsequence("xxxxcab", "abc"), 5);
}

TEST(FindSubsequenceCorner, SequenceShorterThanPattern) {
  ASSERT_EQ(FindSubsequence("ab", "abc"), -1);
}

TEST(FindSubsequenceCorner, AllSameCharactersFound) {
  ASSERT_EQ(FindSubsequence("aaaaaa", "aaa"), 1);
}

TEST(FindSubsequenceCorner, AllSameCharactersNotFound) {
  ASSERT_EQ(FindSubsequence("aaaaaa", "aab"), -1);
}

TEST(FindSubsequenceCorner, FirstPossibleMatchReturned) {
  ASSERT_EQ(FindSubsequence("abcbac", "abc"), 1);
}

TEST(FindSubsequenceCorner, MultipleOccurrences) {
  ASSERT_EQ(FindSubsequence("cbabcab", "abc"), 1);
}

TEST(FindSubsequenceCorner, DuplicateLettersInPattern) {
  ASSERT_EQ(FindSubsequence("bbaac", "aab"), 2);
}

TEST(FindSubsequenceCorner, NoMatchingCounts) {
  ASSERT_EQ(FindSubsequence("abcc", "aabc"), -1);
}

TEST(FindSubsequenceCorner, LongPermutation) {
  ASSERT_EQ(FindSubsequence("zzzyxwvutsrqpon", "wvuts"), 6);
}