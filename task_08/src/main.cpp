#include <iostream>
#include "solution.hpp"


int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) std::cin >> arr[i];
    
    int result = quickSelect(arr, 0, n - 1, k - 1);

    std::cout << result  << std::endl;

    return 0;
}