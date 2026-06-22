#include <vector>

int KSelect(std::vector<int>& array, int left, int right, int k) {
  if (left >= right) {
    return array[left];
  }

  int i = left;
  int j = right;

  int pivot = array[(left + right) / 2];
  while (i <= j) {
    while (array[i] < pivot) {
      i++;
    }

    while (array[j] > pivot) {
      j--;
    }

    if (i <= j) {
      std::swap(array[i], array[j]);
      i++;
      j--;
    }
  }

  if (k <= j && left < j) {
    return KSelect(array, left, j, k);
  }
  if (k >= i && i < right) {
    return KSelect(array, i, right, k);
  }
  return array[k];
}

int Select(std::vector<int>& array, int left, int right, int k) {
  return Select(array, left, right, k - 1);
}
