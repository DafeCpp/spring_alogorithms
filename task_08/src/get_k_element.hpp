#include <random>
#include <vector>

using namespace std;

int get_k_element(vector<int> v, int K, int left, int right) {
  int pivot = right;

  for (int i = left; i < right; ++i) {
    if (pivot > i) {
      if (v[i] > v[pivot]) {
        swap(v[i], v[pivot]);
        pivot = i;
      }
    } else {
      if (v[i] < v[pivot]) {
        swap(v[i], v[pivot]);
        pivot = i;
      }
    }
  }

  if (pivot + 1 == K) return v[pivot];
  if (pivot + 1 > K)
    return get_k_element(v, K, left, pivot - 1);
  else
    return get_k_element(v, K, pivot + 1, right);
}