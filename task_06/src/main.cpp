#include <iostream>

int findOrderStat(int[] arr, int k) {
  int l= 0, r = arr.length;
  while (true) {
    int m = partition(arr, l, r);

    if (m == k) {
      return arr[m];
    }
    else if (k < m) {
      r = m;
    }
    else {
      l = m + 1;
    }
  }
}

int main() { return 0; }
