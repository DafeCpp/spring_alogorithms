#include "NStatistic.hpp"

#include "../../lib/src/util.hpp"
#include <stdexcept>

int NStatistic(std ::vector<int> data, int n) {
  if (data.size() == 0) throw std::invalid_argument("");
  if (n > data.size()) throw std::invalid_argument("");

  MergeSort(data);
  return data[n];
}