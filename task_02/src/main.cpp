#include <iostream>
#include <vector>
#include "task2.hpp"

int main() {
    int n;
    if (!(std::cin >> n) || n <= 1) {
        return 0; 
    }

    std::vector<int> vec(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::cout << FindPair(vec) << std::endl;

    return 0;
} 
