#include "merge_sort.h"

std::vector<int> merge(std::vector<int> &arr, int l, int mid, int r) {
  int i = 0;
  int j = 0;

  std::vector<int> res;

  while (i + l < mid && j + mid < r) {
    if (arr[l + i] < arr[mid + j]) {
      res.push_back(arr[l + i]);
      i++;
    } else {
      res.push_back(arr[mid + j]);
      j++;
    }
  }
  while (j + mid < r) {
    res.push_back(arr[mid + j]);
    j++;
  }
  while (i + l < mid) {
    res.push_back(arr[l + i]);
    i++;
  }
  return res;
}

void mergeSort(std::vector<int> &arr, int l, int r) {
  if (l + 1 >= r) return;
  int mid = (l + r) / 2;
  mergeSort(arr, l, mid);
  mergeSort(arr, mid, r);

  std::vector<int> merged = merge(arr, l, mid, r);
  for (int i = 0; i < merged.size(); i++) {
    arr[l + i] = merged[i];
  }
}
