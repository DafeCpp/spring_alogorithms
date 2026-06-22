#include <iostream>
#include <vector>
#include "FindIndex.hpp"


int main() {
    int n;
    if (!(std::cin >> n)) return 0;

    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
    }


    int result = FindIndex(a);
    std::cout << result << "\n";
    
    
    return 0; }
