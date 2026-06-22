
#include <iostream>
#include <vector>

#include "MergeSort.h"

int main() {
  int n;
  if (!(std::cin >> n)) return 0;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) std::cin >> a[i];
  MergeSort(a);
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << a[i];
  }
  if (n > 0) std::cout << '\n';
  return 0;
}
