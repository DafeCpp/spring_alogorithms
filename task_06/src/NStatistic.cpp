#include "NStatistic.hpp"

#include <algorithm>
#include <stdexcept>

int NStatistic(std ::vector<int> data, int n) {
  if (data.size() == 0) throw std::invalid_argument("");
  if (n > data.size()) throw std::invalid_argument("");

  std::sort(data.begin(), data.end());
  return data[n];
}