#include "task_01.hpp"

std::vector<int> find_nums(int val, std::vector<int> arr) {
  std::vector<int> ans{};
  int* p_begin = &arr[0];
  int* p_end = &arr[-1];
  while (p_begin != p_end) {
    int real_val = *p_begin + *p_end;
    if (real_val < val) {
      p_begin += 1;
    } else if (real_val > val) {
      p_end -= 1;
    } else {
      ans.push_back(*p_begin);
      ans.push_back(*p_end);
      return ans;
    }
  }
};