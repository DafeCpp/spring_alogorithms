#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

template <typename type_ar> 
int part(type_ar *ar, int l, int r) {
  type_ar v = ar[(l + r) / 2];
  int i = l;
  int j = r;
  while (i <= j) {
    while (ar[i] < v) {
      i++;
    }
    while (ar[j] > v) {
      j--;
    }
    if (i >= j) {
      break;
    }
    swap(ar[i++], ar[j--]);
  }
  return j;
}

template <typename type_arrr> 
void q_sort(type_arrr *arrr, int l, int r) {
  if (l < r) {
    int q = part(arrr, l, r);
    q_sort(arrr, l, q);
    q_sort(arrr, q + 1, r);
  }
}