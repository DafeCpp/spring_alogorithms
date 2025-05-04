#include <algorithm>

#include "sorting.hpp"

void MergeSort(std::vector<int>& array) {
  int n = array.size();
  std::vector<int> buffer(n);

  for (int slice = 1; slice < n; slice *= 2) {
    for (int left = 0; left < n; left += 2 * slice) {
      int mid = std::min(left + slice, n);
      int right = std::min(left + 2 * slice, n);

      int i = left, j = mid;
      int k = left;
      while (i < mid && j < right) {
        buffer[k++] = array[i] <= array[j] ? array[i++] : array[j++];
      }
      while (i < mid) buffer[k++] = array[i++];
      while (j < right) buffer[k++] = array[j++];

      std::copy(buffer.begin() + left, buffer.begin() + right,
                array.begin() + left);
    }
  }
}