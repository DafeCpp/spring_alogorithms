#include "search.hpp"


int search(std::vector<int> cont){
    int left = 0;
    int right = size(cont) - 1;
    while (left <= right){
        int middle = left + (right - left) /2;
        if (cont[middle] == 0 && cont[middle + 1] == 1){
            return middle;
        }
        else if (cont[middle] == 1 && cont[middle - 1] == 0){
            return middle - 1;
        }
        else if(cont[middle] == 1){
            right = middle -1;
        }
        else{
            left = middle + 1;
        }
    }
    return 0; //function shouldnt reach here but just in case
}