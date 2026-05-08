#include <gtest/gtest.h>

#include <utility>
#include <vector>

#include "task1.hpp"

using namespace std;

TEST(Task1Test, SimpleTest1) {
  vector<int> arr = {2, 7, 11, 15};
  int S = 9;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, 2);
  EXPECT_EQ(result.second, 7);
}

TEST(Task1Test, SimpleTEst2) {
  vector<int> arr = {1, 2, 4};
  int S = 6;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, 2);
  EXPECT_EQ(result.second, 4);
}

TEST(Task1Test, NoSolution) {
  vector<int> arr = {1, 2, 3};
  int S = 100;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(Task1Test, NegativeNumbers) {
  vector<int> arr = {-5, -3, 0, 2, 4};
  int S = -1;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, -5);
  EXPECT_EQ(result.second, 4);
}

TEST(Task1Test, OnlyTwo) {
  vector<int> arr = {5, 10};
  int S = 15;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, 5);
  EXPECT_EQ(result.second, 10);
}

TEST(Task1Test, OneElement) {
  vector<int> arr = {5};
  int S = 5;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(Task1Test, EmptyArray) {
  vector<int> arr;
  int S = 10;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, -1);
  EXPECT_EQ(result.second, -1);
}

TEST(Task1Test, AllNumbersSame) {
  vector<int> arr = {3, 3, 3, 3};
  int S = 6;
  pair<int, int> result = func(arr, S);
  EXPECT_EQ(result.first, 3);
  EXPECT_EQ(result.second, 3);
}