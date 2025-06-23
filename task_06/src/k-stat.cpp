#include "k-stat.hpp"

#include <stack>

inline void sort3(int& A, int& B, int& C) {
  if (A > B) std::swap(A, B);
  if (B > C) std::swap(B, C);
  if (A > B) std::swap(A, B);
}
inline int median3(int A, int B, int C) {
  sort3(A, B, C);
  return B;
}

int KOrdinalStatistics(std::vector<int> data, int k) {
  struct Segment {
    int L;
    int R;
  };

  Segment segment{0, static_cast<int>(data.size() - 1)};

  while (segment.L < segment.R) {
    auto [L, R] = segment;
    int M = median3(data[L], data[(L + R) / 2], data[R]);
    while (true) {
      while (data[L] < M) L += 1;
      while (data[R] > M) R -= 1;
      if (L < R)
        std::swap(data[L++], data[R--]);
      else
        break;
    }
    if (k <= R)
      segment.R = R;
    else if (k > R)
      segment.L = R + 1;
  }
  return data[k];
}
