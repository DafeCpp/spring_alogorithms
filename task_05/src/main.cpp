#include <iostream>
#include <vector>

std::vector<int> a = {1, 2, 5};

std::vector<int> merge_arrs(std::vector<int>& left, std::vector<int>& right) {
  auto p_left = &left[0];
  auto p_right = &right[0];
  std::vector<int> result{};
  while (p_left != &left.back() && p_right != &right.back()) {
    if (*p_left <= *p_right) {
      result.push_back(*p_left);
      p_left += 1;
    } else {
      result.push_back(*p_right);
      p_right += 1;
    }
  }
  return result;
}

std::vector<int> merge_sort(std::vector<int>& vec) {
  if (vec.size() == 1) {
    return vec;
  }

  std::vector<int> left =
      std::vector<int>(vec.begin(), vec.end() - int(vec.size() / 2));
  std::vector<int> right =
      std::vector<int>(vec.end() - int(vec.size() / 2) + 1, vec.end());
  left = merge_sort(left);
  right = merge_sort(right);
  std::vector<int> result = merge_arrs(left, right);
  return result;
};

int main() {
  std::vector<int> a = {1, 5, 3, 7, 9};
  a = merge_sort(a);
  for (int i : a) {
    std::cout << i << " ";
  }
  return 0;
}
