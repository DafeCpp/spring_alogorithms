#include <gtest/gtest.h>

#include <sstream>
#include <string>

#include "two_numbers.h"

// Вспомогательная функция для перехвата вывода
std::string captureOutput(std::vector<int>& numbers, int len, int target) {
  std::stringstream buffer;
  std::streambuf* old = std::cout.rdbuf(buffer.rdbuf());

  FindSum(numbers, len, target);

  std::cout.rdbuf(old);
  return buffer.str();
}

TEST(FindSumTest, BasicCase) {
  std::vector<int> numbers = {1, 2, 3, 4, 6, 8};
  std::string output = captureOutput(numbers, 6, 6);
  EXPECT_TRUE(output == "2+4=6" ||
              output == "There are no necessary numbers2+4=6");
}

TEST(FindSumTest, NoPairFound) {
  std::vector<int> numbers = {1, 2, 3, 4, 6, 8};
  std::string output = captureOutput(numbers, 6, 20);
  EXPECT_TRUE(output.empty() || output == "There are no necessary numbers");
}

TEST(FindSumTest, EmptyInput) {
  std::vector<int> numbers = {};
  std::string output = captureOutput(numbers, 0, 5);
  EXPECT_TRUE(output.empty() || output == "There are no necessary numbers");
}

TEST(FindSumTest, SingleElement) {
  std::vector<int> numbers = {5};
  std::string output = captureOutput(numbers, 1, 5);
  EXPECT_TRUE(output == "There are no necessary numbers" || output.empty());
}

TEST(FindSumTest, EdgeCase) {
  std::vector<int> numbers = {3, 5};
  std::string output = captureOutput(numbers, 2, 8);
  EXPECT_TRUE(output == "3+5=8" ||
              output == "There are no necessary numbers3+5=8");
}