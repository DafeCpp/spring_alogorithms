#include"heap.hpp"

#include<vector>
#include <algorithm>
#include<string>

#include <gtest/gtest.h>

TEST(Heap_sort , ints){
  std::vector<int> list = {2,3,1,4,1};
  std::vector<int> sorted_list = Heap_sort(list);
  std::sort(begin(list), end(list));
  ASSERT_EQ(sorted_list, list);
}
TEST(Heap_sort, empty_list){
  std::vector<int> list = {};
  std::vector<int> sorted_list = Heap_sort(list);
  std::vector<int> expected_list = {};
  ASSERT_EQ(sorted_list, expected_list);
}
TEST(Heap_sort, doubles){
  std::vector<double> list = {1.1, 2.4, 0.7, 5.6, -23.4};
  std::vector<double> sorted_list = Heap_sort(list);
  std::sort(begin(list), end(list));
  ASSERT_EQ(sorted_list, list);
}
TEST(Heap_sort, string){
  std::vector<std::string> list = {"a", "s", "a", "c", "b"};
  std::vector<std::string> sorted_list = Heap_sort(list);
  std::sort(begin(list), end(list));
  ASSERT_EQ(sorted_list, list);
}