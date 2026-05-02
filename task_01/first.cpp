#include <iostream>
#include <vector>
using namespace std;

pair<int, int> func(int sum, const vector<int> &vec)
{
    int l = 0;
    int r = vec.size() - 1;
    while ((vec[r] + vec[l]) != sum and l < r)
    {
        if (vec[r] + vec[l] > sum)
            r -= 1;
        else
            l += 1;
    }
    return make_pair(vec[l], vec[r]);
}

int main()
{
    vector<int> vec = {1, 2, 4, 5, 7};
    pair<int, int> result = func(9, vec);
    cout << result.first << " " << result.second;
}