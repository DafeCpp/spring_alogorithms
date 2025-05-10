
#include <gtest/gtest.h>

#include <vector>

#include "bubble_sort.hpp"
#include "insertion_sort.hpp"
#include "merge_sort.hpp"
#include "q_sort.hpp"
#include "quick_sort.hpp"
#include "selection_sort.hpp"

TEST(BUBBLE, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  BubbleSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}

TEST(BUBBLE, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  BubbleSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(BUBBLE, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  BubbleSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}

TEST(INSERTION, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  InsertionSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}
TEST(INSERTION, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  InsertionSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(INSERTION, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  InsertionSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}
TEST(MERGE, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  MergeSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}
TEST(MERGE, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  MergeSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(MERGE, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  MergeSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}
TEST(QUICK, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  QuickSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}
TEST(QUICK, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  QuickSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(QUICK, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  QuickSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}
TEST(Q, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  QSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}
TEST(Q, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  QSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(Q, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  QSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}
TEST(SELECTION, Simple) {
  std::vector<int> vec1{5, 2, 7, 1, 3, 9, 8, 4, 6, 10};
  std::vector<int> true_answer1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  SelectionSort(vec1);
  ASSERT_EQ(vec1, true_answer1);
}
TEST(SELECTION, NegAndPos) {
  std::vector<int> vec2{-1, 1, 0, 5, 4, -3, 2, -4, -2, 3, -5};
  std::vector<int> true_answer2{-5, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5};
  SelectionSort(vec2);
  ASSERT_EQ(vec2, true_answer2);
}

TEST(SELECTION, RepeatingNumbers) {
  std::vector<int> vec3{2, 3, -1, 4, 4, 3, 2, 4, 3, 4};
  std::vector<int> true_answer3{-1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
  SelectionSort(vec3);
  ASSERT_EQ(vec3, true_answer3);
}