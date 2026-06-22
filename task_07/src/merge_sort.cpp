#include "merge_sort.hpp"

#include <vector>

std::vector<int> Merge(const std::vector<int>& arr1,
                       const std::vector<int>& arr2) {
  std::vector<int> result;

  result.resize(arr1.size() + arr2.size());
  int i = 0;
  int LeftIndex = 0;
  int RightIndex = 0;
  while (LeftIndex < arr1.size() && RightIndex < arr2.size()) {
    if (arr1[LeftIndex] < arr2[RightIndex]) {
      result[i] = arr1[LeftIndex];
      LeftIndex++;
    } else {
      result[i] = arr2[RightIndex];
      RightIndex++;
    }
    i++;
  }
  while (LeftIndex < arr1.size()) {
    result[i] = arr1[LeftIndex];
    LeftIndex++;
    i++;
  }
  while (RightIndex < arr2.size()) {
    result[i] = arr2[RightIndex];
    RightIndex++;
    i++;
  }
  return result;
}

std::vector<int> MergeSort(const std::vector<int>& arr) {
  if (arr.size() <= 1) {
    return arr;
  }
  int half = arr.size() / 2;
  std::vector<int> arr1(arr.begin(), arr.begin() + half);
  std::vector<int> arr2(arr.begin() + half, arr.end());
  arr1 = MergeSort(arr1);
  arr2 = MergeSort(arr2);
  return Merge(arr1, arr2);
}