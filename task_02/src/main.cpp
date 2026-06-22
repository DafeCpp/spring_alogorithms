#include "solution.hpp"
#include <iostream>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }

    std::cout << FindBorder(arr);
}
