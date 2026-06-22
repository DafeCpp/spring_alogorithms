#include <iostream>
#include <vector>

#include "task1.hpp"

int main() {
  int S, N;
  std::cin >> S;
  std::cin >> N;

  std::vector<int> arr(N);
  for (int i = 0; i < N; i++) {
    std::cin >> arr[i];
  }

  std::pair<int, int> result = func(arr, S);

  if (result.first == -1 && result.second == -1) {
    std::cout << -1 << std::endl;
  } else {
    std::cout << result.first << " " << result.second << std::endl;
  }

  return 0;
}