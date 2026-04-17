#include "../heared/mergeSort.h"

template <typename T>
void merge(
  std::vector<int>& data,
  const uint64_t left,
  const uint64_t mid,
  const uint64_t right
  ) {
  std::vector<T> temp;
  uint64_t i = left;
  uint64_t j = mid + 1;

  while (i <= mid && j <= right) {
    if (data[i] <= data[j]) {
      temp.push_back(data[i++]);
    }
    else {
      temp.push_back(data[j++]);
    }
  }

  while (i <= mid) {temp.push_back(data[i++]); }
  while (j <= right) {temp.push_back(data[j++]); }

  for (uint32_t k = 0; k < temp.size(); ++k) {
    data[left + k] = temp[k];
  }

}

template <typename T>
void mergeSort(std::vector<T>& vec, uint64_t left, uint64_t right) {
  if (left >= right) return;

  uint64_t mid = left + (right - left) / 2;
  mergeSort<T>(vec, left, mid);
  mergeSort<T>(vec, mid + 1, right);
  merge<T>(vec, left, mid, right);
}
