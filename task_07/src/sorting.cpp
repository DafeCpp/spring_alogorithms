#include <sorting.hpp>

void MergeSort(std::vector<int>& arr, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);
    merger(arr, left, right, mid);
  }
}

void merger(std::vector<int>& arr, int left, int right, int mid) {
  int length_1 = mid - left + 1;
  int length_2 = right - mid;
  std::vector<int> L(arr.begin() + left, arr.begin() + left + length_1);
  std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
  int i = 0;
  int j = 0;
  int k = left;
  while (i < length_1 && j < length_2) {
    if (L[i] <= R[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }
  while (i < length_1) {
    arr[k] = L[i];
    i++;
    k++;
  }
  while (j < length_2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}