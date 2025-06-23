#include "sorting.hpp"

#include <sys/types.h>

#include <cstdio>
#include <stack>
#include <utility>
#include <vector>

using namespace sortings;

inline void sort2(int& A, int& B) {
  if (A > B) std::swap(A, B);
}
inline void sort3(int& A, int& B, int& C) {
  sort2(A, B);
  sort2(B, C);
  sort2(A, B);
}

inline int median3(int A, int B, int C) {
  sort3(A, B, C);
  return B;
}

std::vector<int> sortings::qsort(std::vector<int> arr) {
  return qsort_inplace(arr);
}
std::vector<int>& sortings::qsort_inplace(std::vector<int>& arr) {
  struct Interval {
    int L;
    int R;
  };

  std::stack<Interval, std::vector<Interval>> stack;
  stack.push(Interval{0, static_cast<int>(arr.size() - 1)});

  while (not stack.empty()) {
    auto bounds = stack.top();
    stack.pop();

    if (bounds.R - bounds.L < 1) {
      continue;
    }
    if (bounds.R - bounds.L == 1) {
      sort2(arr[bounds.L], arr[bounds.R]);
      continue;
    }
    if (bounds.R - bounds.L == 2) {
      sort3(arr[bounds.L], arr[bounds.L + 1], arr[bounds.L + 2]);
      continue;
    }

    auto [L, R] = bounds;
    int M = median3(arr[L], arr[(L + R) / 2], arr[R]);
    while (true) {
      while (arr[L] < M) L += 1;
      while (arr[R] > M) R -= 1;
      if (L < R)
        std::swap(arr[L++], arr[R--]);
      else
        break;
    }
    stack.push(Interval{bounds.L, R});
    stack.push(Interval{R + 1, bounds.R});
  }

  return arr;
}

std::vector<int> sortings::heapsort(std::vector<int> arr) {
  return heapsort_inplace(arr);
}

inline void heapify(std::vector<int>& arr, uint I, uint L) {
  uint next = I;
  do {
    I = next;
    // (i+1)*2-1 = 2*i + 2 - 1 = 2*i-1
    // (i+1)*2+1-1 = 2*i+2
    if (2 * I + 1 < L && arr[2 * I + 1] > arr[next]) next = 2 * I + 1;
    if (2 * I + 2 < L && arr[2 * I + 2] > arr[next]) next = 2 * I + 2;
    if (next != 0) std::swap(arr[I], arr[next]);
  } while (next != I);
}

std::vector<int>& sortings::heapsort_inplace(std::vector<int>& arr) {
  if (arr.size() == 1) return arr;
  // build heap
  for (int i = arr.size() / 2; i >= 0; --i) {
    heapify(arr, i, arr.size());
  }
  for (int L = arr.size() - 1; L >= 1; --L) {
    std::swap(arr[0], arr[L]);
    heapify(arr, 0, L);
  }
  return arr;
}
