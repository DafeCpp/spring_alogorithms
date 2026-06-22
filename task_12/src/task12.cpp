#include "task12.hpp"

#include <algorithm>
#include <vector>

int least_amount(int S, int N, const std::vector<int>& values) {
  std::vector<int> amounts(S + 1, S + 10);
  amounts[0] = 0;
  for (int s = 1; s < S + 1; s++) {
    for (int i = 0; i < N; i++) {
      if (values[i] <= s) {
        amounts[s] = std::min(amounts[s], amounts[s - values[i]] + 1);
      }
    }
  }

  if (amounts[S] == S + 10) {
    return -1;
  }

  return amounts[S];
}
