#include <algorithm>
#include <iostream>

#include "sorting.hpp"

// std::vector<int> United(std::vector<int> first, std::vector<int> second) {
//   std ::vector<int> ans{};
//   if ((first.size() == 1) && (second.size() == 1)) {
//     ans.push_back(std::min(first[0], second[0]));
//     ans.push_back(std::max(first[0], second[0]));
//   } else if (first.size() == 1)
//     return ans;
// }

void MergeSort(std ::vector<int>& array) {
  int i{0}, j{1};
  int slice{1};
  while ((j != array.size() - 1) && (i != 0)) {
    while (i != j) {
      if (array[i] > array[j]) {
        iter_swap(array.begin() + i, array.begin() + j);
        std ::cout << "SWAP";
        ++j;
      } else
        ++i;
      if ((j - i > slice) || (i == j)) {
        i = j;
        j = i + slice;
      }
    }
    slice *= 2;
    slice > array.size() ? j = array.size() - 1 : j = slice;
    i = 0;
  }
}