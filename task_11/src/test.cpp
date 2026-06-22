#include <gtest/gtest.h>

#include "substring_search.hpp"

TEST(Test, Simple) {
  std::string S1 = "abbbc";
  std::string P1 = "abc";
  ASSERT_EQ(SubstringSearch(S1, P1), -1);

  std::string S2 = "xyzacbdef";
  std::string P2 = "abc";
  ASSERT_EQ(SubstringSearch(S2, P2), 4);

  std::string S3 = "aabbcc";
  std::string P3 = "abc";
  ASSERT_EQ(SubstringSearch(S3, P3), -1);
}

TEST(Test, SingleCharacter) {
  // Один символ
  std::string S1 = "abcdef";
  std::string P1 = "d";
  ASSERT_EQ(SubstringSearch(S1, P1), 4);

  std::string S2 = "abcdef";
  std::string P2 = "z";
  ASSERT_EQ(SubstringSearch(S2, P2), -1);

  std::string S3 = "a";
  std::string P3 = "a";
  ASSERT_EQ(SubstringSearch(S3, P3), 1);
}

TEST(Test, MultipleOccurrences) {
  // Несколько вхождений
  std::string S = "abcabcabc";
  std::string P = "cab";
  ASSERT_EQ(SubstringSearch(S, P), 1);
}

TEST(Test, AllSameLetters) {
  // Все буквы одинаковые
  std::string S = "aaaaaa";
  std::string P1 = "aaa";
  std::string P2 = "bbb";
  ASSERT_EQ(SubstringSearch(S, P1), 1);
  ASSERT_EQ(SubstringSearch(S, P2), -1);
}

TEST(Test, End) {
  // В конце
  std::string S = "abcdefgh";
  std::string P = "fgh";
  ASSERT_EQ(SubstringSearch(S, P), 6);
}

TEST(Test, Start) {
  // В начале
  std::string S = "jhktruopfd";
  std::string P = "trkjh";
  ASSERT_EQ(SubstringSearch(S, P), 1);
}

TEST(Test, SubstringGreater) {
  // Подстрока больше строки
  std::string S1 = "abcd";
  std::string P1 = "skfdksdkf";
  ASSERT_EQ(SubstringSearch(S1, P1), -1);

  std::string S2 = "abcd";
  std::string P2 = "abcde";
  ASSERT_EQ(SubstringSearch(S2, P2), -1);
}
