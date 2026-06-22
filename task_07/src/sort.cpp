#include <vector>
#include "sort.hpp"


void QuickSort(int length, std::vector<int> &data, int start)
{
    int end = length - 1;
    if (start >= end)
    {
        return;
    }
    int pivot = data[(start + end) / 2];
    int i = start;
    int j = end;
    while (i <= j)
    {
        while (data[i] < pivot)
        {
            i++;
        }
        while (data[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            std::swap(data[i], data[j]);
            i++;
            j--;
        }
    }
    if (start < j)
    {
        QuickSort(j + 1, data, start);
    }
    if (i < end)
    {
        QuickSort(end + 1, data, i);
    }
}