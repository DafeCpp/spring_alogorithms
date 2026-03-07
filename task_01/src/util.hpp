#pragma once

#include <iostream>
#include <vector>
using namespace std;

pair<int, int> func(int sum, const vector<int> &vec)
{
    if (vec.size() < 2)
        return make_pair(0, 0);
    int l = 0;
    int r = vec.size() - 1;
    while (l < r)
    {
        if (vec[r] + vec[l] == sum)
            return make_pair(vec[l], vec[r]);
        if (vec[r] + vec[l] > sum)
            r -= 1;
        else
            l += 1;
    }
    return make_pair(-1, -1);
}

