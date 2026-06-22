#include "heap_sort.hpp"

#include <tuple>

std::tuple<int, int> GetChildren(int idx) { return {2 * idx + 1, 2 * idx + 2}; }

int GetMaxChildIdx(int idx, int end, const std::vector<int>& vec) {
  auto [left, right] = GetChildren(idx);

  bool has_left = left < end;
  bool has_right = right < end;

  if (!has_left && !has_right) return -1;
  if (!has_right || (has_left && vec[left] > vec[right])) return left;
  return right;
}

void SiftDown(int begin, int end, std::vector<int>& vec) {
  int iter = begin;
  while (true) {
    int child = GetMaxChildIdx(iter, end, vec);
    if (child == -1) break;

    if (vec[child] > vec[iter]) {
      std::swap(vec[child], vec[iter]);
      iter = child;
      continue;
    }
    break;
  }
}

std::vector<int> ConstructHeap(const std::vector<int>& vec) {
  std::vector<int> heap = vec;
  for (int i{static_cast<int>(heap.size()) / 2 - 1}; i >= 0; --i)
    SiftDown(i, heap.size(), heap);
  return heap;
}

std::vector<int> HeapSort(const std::vector<int>& vec) {
  if (vec.empty()) return {};

  auto heap = ConstructHeap(vec);
  for (std::size_t i{heap.size() - 1}; i != 0; --i) {
    std::swap(heap[i], heap[0]);
    SiftDown(0, i, heap);
  }
  return heap;
}