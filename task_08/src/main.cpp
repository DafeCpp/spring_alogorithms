#include <iostream>
#include <vector>

#include "task8.hpp"

int main() {
  int N, K;
  std::cin >> N >> K;

  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  int result = findKthOrderStatistic(arr, K);
  std::cout << result << std::endl;

  return 0;
}