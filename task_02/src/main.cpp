#include <iostream>
#include <vector>
#include "finder.hpp"

int main() {
    int N;
    std::cin >> N;
    std::vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> arr[i];
    }
    int idx = FindIdOfBounder(N, arr.data());
    std::cout << idx << std::endl;
    return 0;
}