#include <gtest/gtest.h>

#include "task14.hpp"

TEST(TableTest, Example) {
  int n = 5, m = 4;
  int** table = new int*[n];
  for (int i = 0; i < n; i++) {
    table[i] = new int[m];
  }

  int data[5][4] = {
      {1, 2, 3, 5}, {3, 1, 3, 2}, {4, 5, 2, 3}, {5, 5, 3, 2}, {4, 4, 3, 4}};

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      table[i][j] = data[i][j];
    }
  }

  TableChecker checker(n, m, table);

  EXPECT_EQ(checker.check(1, 1), true);
  EXPECT_EQ(checker.check(2, 5), false);
  EXPECT_EQ(checker.check(4, 5), true);
  EXPECT_EQ(checker.check(3, 5), true);
  EXPECT_EQ(checker.check(1, 3), true);
  EXPECT_EQ(checker.check(1, 5), false);

  for (int i = 0; i < n; i++) {
    delete[] table[i];
  }
  delete[] table;
}

TEST(TableTest, OneRow) {
  int n = 1, m = 3;
  int** table = new int*[n];
  table[0] = new int[m];
  table[0][0] = 1;
  table[0][1] = 2;
  table[0][2] = 3;

  TableChecker checker(n, m, table);
  EXPECT_EQ(checker.check(1, 1), true);

  delete[] table[0];
  delete[] table;
}

TEST(TableTest, TwoRows) {
  int n = 2, m = 2;
  int** table = new int*[n];
  for (int i = 0; i < n; i++) {
    table[i] = new int[m];
  }
  table[0][0] = 1;
  table[0][1] = 5;
  table[1][0] = 2;
  table[1][1] = 3;

  TableChecker checker(n, m, table);
  EXPECT_EQ(checker.check(1, 2), true);

  for (int i = 0; i < n; i++) {
    delete[] table[i];
  }
  delete[] table;
}

TEST(TableTest, OneColumn) {
  int n = 5, m = 1;
  int** table = new int*[n];
  for (int i = 0; i < n; i++) {
    table[i] = new int[m];
  }

  int data[5] = {1, 2, 3, 2, 5};
  for (int i = 0; i < n; i++) {
    table[i][0] = data[i];
  }

  TableChecker checker(n, m, table);
  EXPECT_EQ(checker.check(1, 3), true);
  EXPECT_EQ(checker.check(3, 4), false);
  EXPECT_EQ(checker.check(4, 5), true);

  for (int i = 0; i < n; i++) {
    delete[] table[i];
  }
  delete[] table;
}