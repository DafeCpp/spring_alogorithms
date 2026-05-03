#include "topology_sort.hpp"



std::vector<int> daysToTemp(std::vector<int> &temps){
    int n = temps.size();
    std::vector<int> result(n, 0);
    std::stack<int> s;
    for (int i = 0; i < n; i++){
        while (!s.empty() && temps[i] > temps[s.top()]){
            int index = s.top();
            s.pop();
            result[index] = i - index;
        }
        s.push(i);
    } 
    return result;
}