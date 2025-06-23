#include <iostream>
#include <stdexcept>
#include <vector>

#include "task_01.hpp"

std::vector<int> find_two_nums(int val, std::vector<int> arr) {
  std::vector<int> ans{};
  int* p_begin = &arr[0];
  int* p_end = &arr[arr.size() - 1];
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
  throw std::runtime_error("Нет таких чисел");
};

int main() {
  std::vector<int> test = {1, 2, 4, 5, 7, 10};
  int a = 0;
  // int* p_begin = &test[0];
  // int* p_end = &test[test.size() - 1];
  // std::cout << *p_begin +*p_end << std::endl;
  // std::cout << find_nums(a, test)[0] << " " << find_nums(a, test)[1] <<
  // std::endl;
  test.back();
  a = test.back();
  std::cout << a << std::endl;
  return 0;
}
