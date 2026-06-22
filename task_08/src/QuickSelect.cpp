#include "QuickSelect.h"

#include <cstdlib>
#include <random>
#include <vector>
namespace {
int Partition(std::vector<int>& arr, int left, int right) {
  static thread_local std::mt19937 rng(std::random_device{}());
  std::uniform_int_distribution<int> dist(left, right);
  int pivot_index = dist(rng);
  std::swap(arr[pivot_index], arr[right]);

  int pivot = arr[right];
  int i = left;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      std::swap(arr[i], arr[j]);
      i++;
    }
  }
  std::swap(arr[i], arr[right]);
  return i;
}

int QuickSelectImpl(std::vector<int>& arr, int left, int right, int N) {
  if (left == right) return arr[left];

  int pivot_index = Partition(arr, left, right);

  if (pivot_index == N)
    return arr[pivot_index];
  else if (pivot_index > N)
    return QuickSelectImpl(arr, left, pivot_index - 1, N);
  else
    return QuickSelectImpl(arr, pivot_index + 1, right, N);
}
}  // namespace

int QuickSelect(int K, std::vector<int>& arr) {
  return QuickSelectImpl(arr, 0, (int)arr.size() - 1, K - 1);
}