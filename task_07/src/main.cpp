#include <iostream>

#include "../header/mergeSort.h"

int main() {
  int N;
  std::cin >> N;

  std::vector<int> v;

  for (int i = 0; i < N; i++) {
    int x;
    std::cin >> x;
    v.push_back(x);
  }

  if (!v.empty()) {
    mergeSort<int>(v, 0, static_cast<std::uint64_t>(N - 1));
  }

  for (const auto x : v) {
    std::cout << x << " ";
  }

  return 0;
}
