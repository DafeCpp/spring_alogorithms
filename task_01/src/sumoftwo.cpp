#include "sumoftwo.hpp"
#include <vector>
#include <utility>

std::pair<int,int> SumOfTwo(int k, int size, const std::vector<int>& numbers){
  int i = 0;
  int j = size-1;
    while(j>i){
      if(numbers[i]+numbers[j]==k){
          std::pair<int,int> ans = {numbers[i],numbers[j]};
          return ans;
      }
      else if(numbers[i]+numbers[j]<k){
        ++i;
      }
      else{
        --j;
      }
    }
    std::pair<int,int> ans = {-1, -1};
    return ans;
}