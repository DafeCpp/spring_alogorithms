#include <iostream>
#include <vector>

#include "merge_sort.h"

int main() {
  std::cout << "Enter the size of an array:\n";
  int N;
  std::cin >> N;

  std::cout << "Enter an array:\n";
  std::vector<int> A(N);
  for (int i{0}; i < N; i++) std::cin >> A[i];

  mergeSort(A, 0, A.size());

  for (int i{0}; i < N; i++) {
    std::cout << A[i] << " ";
  }

  return 0;
}