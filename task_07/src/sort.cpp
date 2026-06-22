#include "sort.hpp"

void SelectionSort(std::vector<int>& data) {
    for (int bord = 0; bord < data.size(); ++bord) {
        int min_index = bord;
        for (int j = bord + 1; j < data.size(); ++j) {
            if (data[j] < data[min_index]) {
                min_index = j;
            }
        }
        std::swap(data[min_index], data[bord]);
    }
}