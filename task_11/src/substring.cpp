#include "substring.hpp"
#include <vector>

int findPermutationSubstring(const std::string& S, const std::string& P) {
    int n = S.length();
    int m = P.length();
    
    if (m > n) {
        return -1;
    }
    
    std::vector<int> target(26, 0);
    std::vector<int> window(26, 0);
    
    for (char c : P) {
        target[c - 'a']++;
    }
    
    for (int i = 0; i < m; ++i) {
        window[S[i] - 'a']++;
    }
    
    if (window == target) {
        return 1;
    }
    
    for (int i = m; i < n; ++i) {
        window[S[i] - 'a']++;
        window[S[i - m] - 'a']--;
        
        if (window == target) {
            return i - m + 2;
        }
    }
    
    return -1;
}