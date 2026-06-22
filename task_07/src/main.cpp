#include <iostream>
#include <vector>
#include "sort.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }
    QuickSort(N, nums);
    for (auto i = 0; i < nums.size(); ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << nums[i];
    }
    std::cout << std::endl;
    return 0;
}