#include "../heared/mergeSort.h"

template <typename T>
void merge(std::vector<T>& data, const std::uint64_t left,
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
void mergeSort(std::vector<T>& vec, std::uint64_t left, std::uint64_t right) {
  if (left >= right) return;

  std::uint64_t mid = left + (right - left) / 2;
  mergeSort<T>(vec, left, mid);
  mergeSort<T>(vec, mid + 1, right);
  merge<T>(vec, left, mid, right);
}

template void merge<int>(std::vector<int>& data, std::uint64_t left,
                         std::uint64_t mid, std::uint64_t right);

template void mergeSort<int>(std::vector<int>& vec, std::uint64_t left,
                             std::uint64_t right);
