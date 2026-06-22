#include <iostream>
#include <vector>
#include "search.hpp"   

int main() {
    int S, N;
    std::cin >> S;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    auto result = FindTwoSum(S, N, arr.data());
    if (result.first == -1 && result.second == -1) {
        std::cout << -1 << std::endl;
    } else {
        std::cout << result.first << ' ' << result.second << std::endl;
    }
}