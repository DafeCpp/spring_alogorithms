#include <findeq.hpp>

pair<int , int> findeq(int goal,int length,vector<int> cont){
    int left{0};
    int right = cont.size() - 1;
    while (left < right){
        int target_sum = cont[left] + cont[right];
        
        if (target_sum == goal){
            return {cont[left],cont[right]};
        }
        else if (target_sum < goal){
            left++;
        }
        else{
            right--;
        }
        
    }
    return {-1,-1};
}
