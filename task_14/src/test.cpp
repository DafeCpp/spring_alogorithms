#include <gtest/gtest.h>

#include "non_decreasing_ranges.hpp"

TEST(CanReachNonDecreasingSegment, Simple) {
  std::vector<std::string> answers = {"Yes", "No", "Yes", "Yes", "Yes", "No"};
  std::vector<std::pair<int, int>> ranges = {{1, 1}, {2, 5}, {4, 5},
                                             {3, 5}, {1, 3}, {1, 5}};
  std::vector<std::vector<int>> table = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}

TEST(CanReachNonDecreasingSegment, OneRow) {
  std::vector<std::string> answers = {"Yes"};
  std::vector<std::pair<int, int>> ranges = {{1, 1}};
  std::vector<std::vector<int>> table = {{1, 1}};

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}

TEST(CanReachNonDecreasingSegment, EmptyTable) {
  std::vector<std::string> answers = {"No", "No"};
  std::vector<std::pair<int, int>> ranges = {{52, 67}, {4, 2}};
  std::vector<std::vector<int>> table = {{}};

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}

TEST(CanReachNonDecreasingSegment, NegativeNumbers) {
  std::vector<std::string> answers = {"Yes", "No", "Yes", "No", "Yes", "Yes"};
  std::vector<std::pair<int, int>> ranges = {{1, 1}, {2, 4}, {3, 4},
                                             {1, 4}, {1, 3}, {1, 2}};
  std::vector<std::vector<int>> table = {
      {1, 2, 3, 0},
      {-3, 6, 3, 2},
      {4, 5, 52, 3},
      {0, 5, 3, 2},
  };

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}

TEST(CanReachNonDecreasingSegment, AllSame) {
  std::vector<std::string> answers = {"Yes", "Yes", "Yes", "Yes", "Yes", "Yes"};
  std::vector<std::pair<int, int>> ranges = {{1, 1}, {2, 5}, {4, 5},
                                             {3, 5}, {1, 3}, {1, 5}};
  std::vector<std::vector<int>> table = {
      {5, 5, 5, 5}, {5, 5, 5, 5}, {5, 5, 5, 5}, {5, 5, 5, 5}, {5, 5, 5, 5}};

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}

TEST(CanReachNonDecreasingSegment, OneColumn) {
  std::vector<std::string> answers = {"Yes", "Yes", "No", "No", "No", "No"};
  std::vector<std::pair<int, int>> ranges = {{1, 1}, {2, 3}, {4, 5},
                                             {3, 5}, {1, 3}, {1, 5}};
  std::vector<std::vector<int>> table = {{5}, {2}, {4}, {4}, {0}};

  std::vector<int> max_right_rows = GetNonDecreasingRanges(table);
  for (int i = 0; i < answers.size(); ++i) {
    ASSERT_EQ(IsThereNonDecreasingColumn(ranges[i].first, ranges[i].second,
                                         max_right_rows),
              answers[i]);
  }
}
