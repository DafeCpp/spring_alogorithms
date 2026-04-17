#include "../heared/mergeSort.h"

int main() {
  int N;
  std::cin >> N;

  std::vector<int> v;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    v.push_back(x);
  }

  mergeSort<>(v, 0, N - 1);

  for (const auto x : v) {
    std::cout << x << " ";
  }

  return 0;
}
