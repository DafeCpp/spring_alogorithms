#include "order_statistic.hpp"

int QuickSelect(std::size_t begin, std::size_t end, std::vector<int>& arr,
                std::size_t K) {
  int pivot = arr[end - 1];
  std::size_t pos = begin;

  for (std::size_t i{begin}; i < end - 1; ++i) {
    if (arr[i] <= pivot) {
      std::swap(arr[i], arr[pos]);
      ++pos;
    }
  }

  std::swap(arr[pos], arr[end - 1]);

  if (K > pos) return QuickSelect(pos + 1, end, arr, K);

  if (K < pos) return QuickSelect(begin, pos, arr, K);

  return arr[pos];
}

int OrderStatistic(std::size_t N, std::size_t K, const std::vector<int>& arr) {
  auto arr_copy = arr;
  return QuickSelect(0, arr.size(), arr_copy, K - 1);
}