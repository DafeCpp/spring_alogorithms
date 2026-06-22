#include "topology_sort.hpp"

#include <vector>

std::vector<int> DistanceToNextGreaterElement(const std::vector<int>& temp) {
  std::vector<int> result((int)temp.size(), 0);
  std::vector<int> indexes;
  for (int index = 0; index < (int)temp.size(); index++) {
    while (!indexes.empty() && temp[index] > temp[indexes.back()]) {
      result[indexes.back()] = index - indexes.back();
      indexes.pop_back();
    }
    indexes.push_back(index);
  }
  return result;
}