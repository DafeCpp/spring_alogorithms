#include <gtest/gtest.h>

#include <vector>

#include "./phone_combinations.h"

TEST(GetPhoneCombinationsTest, HandlesSingleDigit) {
  EXPECT_EQ(
      GetPhoneCombinations("2"),
      (std::vector<std::string>{"a", "b", "c"}));
}

TEST(GetPhoneCombinationsTest, MatchesExampleForTwoDigits) {
  EXPECT_EQ(
      GetPhoneCombinations("23"),
      (std::vector<std::string>{
          "ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"}));
}

TEST(GetPhoneCombinationsTest, SupportsDigitsWithFourLetters) {
  EXPECT_EQ(
      GetPhoneCombinations("79"),
      (std::vector<std::string>{"pw", "px", "py", "pz",
                                "qw", "qx", "qy", "qz",
                                "rw", "rx", "ry", "rz",
                                "sw", "sx", "sy", "sz"}));
}

TEST(GetPhoneCombinationsTest, ReturnsEmptyForEmptyInput) {
  EXPECT_TRUE(GetPhoneCombinations("").empty());
}
