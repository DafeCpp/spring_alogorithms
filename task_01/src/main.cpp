#include <iostream>
#include "./task_01.h"

int main() {
  int S, N;

  std::cin >> S;
  std::cin >> N;

  std::vector<int> A(N);
  for (int i=0; i<N; i++) {
    std::cin >> A[i];
  }

  std::pair <int,int> res = FindValues(S, N, A);
  if (res.first == -1 && res.second == -1) {
    std::cout << -1 << std::endl;
  }
  else {
    std::cout << res.first << " " << res.second << std::endl;
  }
  return 0;
}
