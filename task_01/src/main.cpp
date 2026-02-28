#include <iostream>
#include <vector>

#include <findeq.hpp>

using namespace std;


int main() {

    size_t length{0};
    int goal{0};
    cin >> goal;
    cin >> length;
    vector<int> cont(length);
    for (int i{0}; i < length; i++){
        cin >> cont[i];
    }
    auto result = findeq(goal,length,cont);
    cout << result.first << " "<< result.second;
     return 0; }
