#include <iostream>
#include <vector>
#include "util.hpp";
using namespace std;


int main()
{
    vector<int> vec = {1, 2, 4, 5, 7};
    pair<int, int> result = func(9, vec);
    cout << result.first << " " << result.second;
}
