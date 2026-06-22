#include "findindex.hpp"

int FindIndex(int size, const std::vector<int>& binar_numbers) {
    int left = 0;
    int right = size - 1;
    int result = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (binar_numbers[mid] == 0) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    if (result == -1 || result == static_cast<int>(binar_numbers.size()) - 1) {
        return -1;
    }
    
    if (binar_numbers[result] == 0 && binar_numbers[result + 1] == 1) {
        return result;
    }
    
    return -1;
}