#include "util.hpp"

std::vector<double> Smaller(double elem, const std::vector<double>& input) {
  std::vector<double> smaller{};
  for (auto i : input) {
    if (i < elem) {
      smaller.push_back(i);
    }
  }
  return smaller;
}

std::vector<double> Bigger(double elem, const std::vector<double>& input) {
  std::vector<double> bigger{};
  for (auto i : input) {
    if (i > elem) {
      bigger.push_back(i);
    }
  }
  return bigger;
}

std::vector<double> Eq(double elem, const std::vector<double>& input) {
  std::vector<double> eq{};
  for (auto i : input) {
    if (i == elem) {
      eq.push_back(i);
    }
  }
  return eq;
}