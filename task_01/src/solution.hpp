#ifndef SOLUTION_HPP
#define SOLUTION_HPP

#include <utility>
#include <vector>

std::pair<int, int> FindPairMatchSum(const std::vector<int>& arr, int target);
int BinarySearchGEQ(const std::vector<int>& arr, int target, int left,
                    int right);

#endif
