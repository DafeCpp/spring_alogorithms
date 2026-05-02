#include <random>
#include <vector>

int OrderStatistic(std::vector<int> array, int K, int left, int right) {
  if (left >= right) return array[left];
  int pivot = right;
  int border = left;

  for (int i = left; i < right; ++i) {
    if (array[i] <= array[pivot]) {
      std::swap(array[i], array[border]);
      ++border;
    }
  }
  std::swap(array[border], array[pivot]);
  pivot = border;

  if (pivot + 1 == K) return array[pivot];
  if (pivot + 1 > K)
    return OrderStatistic(array, K, left, pivot - 1);
  else
    return OrderStatistic(array, K, pivot + 1, right);
}