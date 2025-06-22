#include "solution.hpp"
#include <stack>
#include <vector>

std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
    std::vector<int> result(temperatures.size(), 0);
    std::stack<int> stack;
    
    for (int i = 0; i < temperatures.size(); ++i) {
        while (!stack.empty() && temperatures[i] > temperatures[stack.top()]) {
            int idx = stack.top();
            stack.pop();
            result[idx] = i - idx;
        }
        stack.push(i);
    }
    return result;
}