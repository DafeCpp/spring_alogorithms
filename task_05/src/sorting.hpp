#pragma once

#include <vector>

namespace sortings {

std::vector<int> qsort(std::vector<int> arr);
std::vector<int>& qsort_inplace(std::vector<int>& arr);

std::vector<int> heapsort(std::vector<int> arr);
std::vector<int>& heapsort_inplace(std::vector<int>& arr);

}  // namespace sortings
