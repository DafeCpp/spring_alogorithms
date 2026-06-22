#include "MergeSort.h"

#include <vector>

namespace {

void Merge(std::vector<int>& arr, std::vector<int>& buffer, int left, int mid,
           int right) {
  int it1 = left;
  int it2 = mid;
  int target = left;

  while (it1 < mid && it2 < right) {
    if (arr[it1] <= arr[it2]) {
      buffer[target++] = arr[it1++];
    } else {
      buffer[target++] = arr[it2++];
    }
  }

  while (it1 < mid) buffer[target++] = arr[it1++];

  while (it2 < right) buffer[target++] = arr[it2++];

  for (int i = left; i < right; ++i) {
    arr[i] = buffer[i];
  }
}

void MergeSortImpl(std::vector<int>& arr, std::vector<int>& buffer, int left,
                   int right) {
  if (right - left <= 1) return;

  int mid = left + (right - left) / 2;

  MergeSortImpl(arr, buffer, left, mid);
  MergeSortImpl(arr, buffer, mid, right);

  Merge(arr, buffer, left, mid, right);
}

}  // namespace

void MergeSort(std::vector<int>& arr) {
  if (arr.size() <= 1) return;

  // один раз созлаем buffer и работаем с ним вместо постоянного создания
  // векторов в merge :)
  std::vector<int> buffer(arr.size());
  MergeSortImpl(arr, buffer, 0, arr.size());
}