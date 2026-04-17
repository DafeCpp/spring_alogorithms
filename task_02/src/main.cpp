#include <iostream>
#include <vector>
#include "./find_zero_one_pair.h"

int main() {
  int N;
  std::cin >> N;

  if (N <= 1) {
    return 0;
  }

  std::vector<int> A(N);
  for (int i = 0; i < N; i++) {
    std::cin >> A[i];
  }

  std::cout << FindZeroOnePair(A);

  return 0;
}
