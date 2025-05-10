#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "sum_two_num.h"

static std::string captureOutput(std::vector<int>& vec, int len, int num) {
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  FindSumTwoNum(vec, len, num);

  std::cout.rdbuf(old);
  return buffer.str();
}

TEST(SumTwoNum, Simple) {
  std::vector<int> vec = {1, 2, 3, 4, 6, 8};
  std::string output = captureOutput(vec, 6, 6);
  EXPECT_TRUE(output == "2+4=6" ||
              output == "There are no necessary numbers 2+4=6");
}

TEST(SumTwoNum, NoPairFound) {
  std::vector<int> vec = {1, 2, 3, 4, 6, 8};
  std::string output = captureOutput(vec, 6, 20);
  EXPECT_TRUE(output.empty() || output == "There are no necessary numbers");
}

TEST(SumTwoNum, EmptyInput) {
  std::vector<int> vec = {};
  std::string output = captureOutput(vec, 0, 5);
  EXPECT_TRUE(output.empty() || output == "There are no necessary numbers");
}

TEST(SumTwoNum, SingleElement) {
  std::vector<int> vec = {5};
  std::string output = captureOutput(vec, 1, 5);
  EXPECT_TRUE(output == "There are no necessary numbers" || output.empty());
}

TEST(SumTwoNum, EdgeCase) {
  std::vector<int> vec = {3, 5};
  std::string output = captureOutput(vec, 2, 8);
  EXPECT_TRUE(output == "3+5=8" ||
              output == "There are no necessary numbers 3+5=8");
}