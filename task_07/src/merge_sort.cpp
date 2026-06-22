#include "merge_sort.hpp"

static void MergeSortImpl(std::vector<int>& values, std::vector<int>& buffer,
                          int left, int right) {
  if (right - left <= 1) {
    return;
  }

  const int middle = left + (right - left) / 2;
  MergeSortImpl(values, buffer, left, middle);
  MergeSortImpl(values, buffer, middle, right);

  int first = left;
  int second = middle;
  int position = left;
  while (first < middle || second < right) {
    if (second == right ||
        (first < middle && values[first] <= values[second])) {
      buffer[position++] = values[first++];
    } else {
      buffer[position++] = values[second++];
    }
  }

  for (int index = left; index < right; ++index) {
    values[index] = buffer[index];
  }
}

void MergeSort(std::vector<int>& values) {
  std::vector<int> buffer(values.size());
  MergeSortImpl(values, buffer, 0, static_cast<int>(values.size()));
}
