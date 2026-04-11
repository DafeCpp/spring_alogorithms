#include <gtest/gtest.h>

#include <get_border_index.hpp>

TEST(Test, Simple) {
  vector<int> v1{0, 1};
  vector<int> v2{0, 0, 0, 1, 1};
  vector<int> v3{0, 0, 0, 0, 0, 1};
  vector<int> v4{0, 1, 1, 1, 1};
  vector<int> v5{0, 0, 1, 1, 1, 1};
  vector<int> v6{0, 0, 0, 1};
  vector<int> v7{0, 0, 1};
  vector<int> v8{0, 1, 1};
  vector<int> v9{0, 0, 0, 0, 1, 1, 1};
  vector<int> v10{0, 0, 0, 0, 0, 0, 0, 0, 1};
  vector<int> v11{0, 0, 0, 0, 1};
  vector<int> v12{0, 0, 1, 1};
  vector<int> v13{0, 1, 1, 1};
  vector<int> v14{0, 1, 0, 1, 0, 1, 0, 1};

  ASSERT_EQ(get_border_index(v1), 0);
  ASSERT_EQ(get_border_index(v2), 2);
  ASSERT_EQ(get_border_index(v3), 4);
  ASSERT_EQ(get_border_index(v4), 0);
  ASSERT_EQ(get_border_index(v5), 1);
  ASSERT_EQ(get_border_index(v6), 2);
  ASSERT_EQ(get_border_index(v7), 1);
  ASSERT_EQ(get_border_index(v8), 0);
  ASSERT_EQ(get_border_index(v9), 3);
  ASSERT_EQ(get_border_index(v10), 7);
  ASSERT_EQ(get_border_index(v11), 3);
  ASSERT_EQ(get_border_index(v12), 1);
  ASSERT_EQ(get_border_index(v13), 0);
}
