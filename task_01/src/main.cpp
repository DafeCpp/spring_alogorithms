#include <iostream>
#include <vector>

#include "task1.h"

int main() {
  int S = 5;
  int N = 5;
  std::vector<int> vec = {1, 2, 3, 4, 5};
  std::vector<int> res = sum_of_two(S, N, vec);

  for (int u : res) {
    std::cout << u << " ";
  }
  return 0;
}
