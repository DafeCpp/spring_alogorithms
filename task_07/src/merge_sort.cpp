#include "merge_sort.h"

template <typename T>
void Merge(std::vector<T>& data, const std::uint64_t left,
           const std::uint64_t mid, const std::uint64_t right) {
  std::vector<T> temp;
  std::uint64_t i = left;
  std::uint64_t j = mid + 1;

  while (i <= mid && j <= right) {
    if (data[i] <= data[j]) {
      temp.push_back(data[i++]);
    } else {
      temp.push_back(data[j++]);
    }
  }

  while (i <= mid) {
    temp.push_back(data[i++]);
  }
  while (j <= right) {
    temp.push_back(data[j++]);
  }

  for (std::uint64_t k = 0; k < temp.size(); ++k) {
    data[left + k] = temp[k];
  }
}

template <typename T>
void MergeSort(std::vector<T>& vec, std::uint64_t left, std::uint64_t right) {
  if (left >= right) return;

  std::uint64_t mid = left + (right - left) / 2;
  MergeSort<T>(vec, left, mid);
  MergeSort<T>(vec, mid + 1, right);
  Merge<T>(vec, left, mid, right);
}

template void Merge<int>(std::vector<int>& data, std::uint64_t left,
                         std::uint64_t mid, std::uint64_t right);

template void MergeSort<int>(std::vector<int>& vec, std::uint64_t left,
                             std::uint64_t right);
