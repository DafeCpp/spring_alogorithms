#include <vector>

using namespace std;

vector<int> MergingArrays(const std::vector<int>& v1_sorted,
                          const std::vector<int>& v2_sorted) {
  // Слияние
  vector<int> v_sorted;
  size_t ptr1 = 0, ptr2 = 0;

  while (ptr1 < v1_sorted.size() && ptr2 < v2_sorted.size()) {
    if (v1_sorted[ptr1] > v2_sorted[ptr2]) {
      v_sorted.push_back(v2_sorted[ptr2]);
      ++ptr2;
    } else {
      v_sorted.push_back(v1_sorted[ptr1]);
      ++ptr1;
    }
  }

  // Добавление оставшихся элементов
  while (ptr1 < v1_sorted.size()) {
    v_sorted.push_back(v1_sorted[ptr1]);
    ++ptr1;
  }

  while (ptr2 < v2_sorted.size()) {
    v_sorted.push_back(v2_sorted[ptr2]);
    ++ptr2;
  }
  return v_sorted;
}

vector<int> MergeSort(vector<int> v) {
  int n = v.size();
  if (n == 1 || n == 0) return v;

  // Деление на две части
  vector<int> v1(v.begin(), v.begin() + n / 2);
  vector<int> v2(v.begin() + n / 2, v.end());

  vector<int> v1_sorted = MergeSort(v1);
  vector<int> v2_sorted = MergeSort(v2);

  return MergingArrays(v1_sorted, v2_sorted);
}