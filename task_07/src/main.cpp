#include <iostream>
#include "sort.hpp"

int main() {
    int n;
    std::cin >> n;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> arr[i];
    }
    SelectionSort(arr);
    for (int i = 0; i < n; ++i) {
        std::cout << arr[i] << " ";
    }
}