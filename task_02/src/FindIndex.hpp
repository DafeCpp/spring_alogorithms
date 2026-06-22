#include <vector>



int FindIndex(std::vector<int> vec){
    int left = 0;
    int right = vec.size() - 1;

    while(left < right){
        if(left - right == -1){
            return left;
        }

        int mid = (left + right)/2;

        if(vec[mid] == 0){
            left = mid;
        }

        if(vec[mid] == 1){
            right = mid;
        }
    }
    return left;
}