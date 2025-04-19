#include "quick_sort.hpp"

std::vector<double> Smaller(double elem, std::vector<double> input) {
  std::vector<double> smaller{};
  for (auto i : input) {
    if (i < elem) {
      smaller.push_back(i);
    }
  }
  return smaller;
}

std::vector<double> Bigger(double elem, std::vector<double> input) {
  std::vector<double> bigger{};
  for (auto i : input) {
    if (i > elem) {
      bigger.push_back(i);
    }
  }
  return bigger;
}

std::vector<double> Eq(double elem, std::vector<double> input) {
  std::vector<double> eq{};
  for (auto i : input) {
    if (i == elem) {
      eq.push_back(i);
    }
  }
  return eq;
}

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