#include "task.hpp"

#include <stdexcept>

std::pair<int, int> SearchNumbers(int search_num,
                                  const std::vector<int>& data) {
  if (data.size() <= 1) {
    throw std::invalid_argument("vector is too small");
  }
  size_t bottom{0};
  size_t top{data.size() - 1};
  while (bottom != top) {
    if (data[bottom] + data[top] == search_num) {
      std::pair<int, int> ans{data[bottom], data[top]};
      return ans;
    } else if (data[bottom] + data[top] > search_num) {
      --top;
    } else {
      ++bottom;
    }
  }
  throw std::invalid_argument("no suitable pair");
}