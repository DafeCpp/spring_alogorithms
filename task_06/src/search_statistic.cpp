#include "search_statistic.hpp"

#include <stdexcept>

double SearchNStatistics(const std::vector<double>& input, int order) {
  if (input.empty() || order >= input.size() || order < 0) {
    throw std::invalid_argument("invalid data");
  }
  double elem = input[0];
  std::vector<double> smaller{Smaller(elem, input)};
  if (smaller.size() == order) {
    return elem;
  } else if (smaller.size() > order) {
    return SearchNStatistics(smaller, order);
  }
  std::vector<double> eq{Eq(elem, input)};
  order -= smaller.size();
  if (eq.size() > order) {
    return elem;
  }
  order -= eq.size();
  std::vector<double> bigger{Bigger(elem, input)};
  return SearchNStatistics(bigger, order);
}