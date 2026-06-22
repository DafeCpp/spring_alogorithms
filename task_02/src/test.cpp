#include <gtest/gtest.h>

#include <get_border_index.hpp>
#include <vector>

TEST(Test, Simple) {
  std::vector<int> v1{0, 1};
  std::vector<int> v2{0, 0, 0, 1, 1};
  std::vector<int> v3{0, 0, 0, 0, 0, 1};
  std::vector<int> v4{0, 1, 1, 1, 1};
  std::vector<int> v5{0, 0, 1, 1, 1, 1};
  std::vector<int> v6{0, 0, 0, 1};
  std::vector<int> v7{0, 0, 1};
  std::vector<int> v8{0, 1, 1};
  std::vector<int> v9{0, 0, 0, 0, 1, 1, 1};
  std::vector<int> v10{0, 0, 0, 0, 0, 0, 0, 0, 1};
  std::vector<int> v11{0, 0, 0, 0, 1};
  std::vector<int> v12{0, 0, 1, 1};
  std::vector<int> v13{0, 1, 1, 1};
  std::vector<int> v14{0, 1, 0, 1, 0, 1, 0, 1};

  ASSERT_EQ(GetBorderIndex(v1), 0);
  ASSERT_EQ(GetBorderIndex(v2), 2);
  ASSERT_EQ(GetBorderIndex(v3), 4);
  ASSERT_EQ(GetBorderIndex(v4), 0);
  ASSERT_EQ(GetBorderIndex(v5), 1);
  ASSERT_EQ(GetBorderIndex(v6), 2);
  ASSERT_EQ(GetBorderIndex(v7), 1);
  ASSERT_EQ(GetBorderIndex(v8), 0);
  ASSERT_EQ(GetBorderIndex(v9), 3);
  ASSERT_EQ(GetBorderIndex(v10), 7);
  ASSERT_EQ(GetBorderIndex(v11), 3);
  ASSERT_EQ(GetBorderIndex(v12), 1);
  ASSERT_EQ(GetBorderIndex(v13), 0);
}

void CheckAnswer(int i, std::vector<int> v) {
  ASSERT_EQ(v[i], 0);
  ASSERT_EQ(v[i] + 1, 1);
}

TEST(Test, OutOfSync) {
  std::vector<int> v1{0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1};
  std::vector<int> v2{0, 1, 0, 1, 0, 1, 0, 1};
  std::vector<int> v3{0, 0, 0, 1, 0, 0, 0, 1};
  std::vector<int> v4{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};
  std::vector<int> v5{0, 1, 0, 1};
  std::vector<int> v6{0, 1, 1, 1, 1, 0, 1};

  CheckAnswer(GetBorderIndex(v1), v1);
  CheckAnswer(GetBorderIndex(v2), v2);
  CheckAnswer(GetBorderIndex(v3), v3);
  CheckAnswer(GetBorderIndex(v4), v4);
  CheckAnswer(GetBorderIndex(v5), v5);
  CheckAnswer(GetBorderIndex(v6), v6);
}