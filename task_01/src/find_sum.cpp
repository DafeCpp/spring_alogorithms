#include "find_sum.hpp"

#include <unordered_map>

Result FindSumHash(int sum, std::size_t size, const std::vector<int>& vec) {
  if (size == 1) return Result();

  std::unordered_map<int, std::size_t> map;

  for (std::size_t i{0}; i != vec.size(); ++i) {
    if (auto ptr = map.find(vec[i]); ptr != map.end()) {
      return {vec[ptr->second], vec[i], true};
    }
    map[sum - vec[i]] = i;
  }
  return Result{};
}