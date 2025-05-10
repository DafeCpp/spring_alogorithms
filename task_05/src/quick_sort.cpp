#include "quick_sort.hpp"

std::vector<double> QuickSort(std::vector<double> input) {
  if (input.size() <= 1) {
    return input;
  }
  double elem = input[0];
  std::vector<double> eq{Eq(elem, input)};
  std::vector<double> bigger{QuickSort(Bigger(elem, input))};
  std::vector<double> ans{QuickSort(Smaller(elem, input))};
  ans.insert(ans.end(), eq.begin(), eq.end());
  ans.insert(ans.end(), bigger.begin(), bigger.end());
  return ans;
}