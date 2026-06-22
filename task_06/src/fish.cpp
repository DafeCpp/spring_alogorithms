#include "fish.hpp"
#include <deque>

long long minFishCost(const std::vector<int>& prices, int K) {
    int n = prices.size();
    long long totalCost = 0;
    std::deque<int> dq;
    
    for (int i = 0; i < n; ++i) {
        while (!dq.empty() && prices[dq.back()] >= prices[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        
        if (dq.front() < i - K + 1) {
            dq.pop_front();
        }
        
        totalCost += prices[dq.front()];
    }
    
    return totalCost;
}