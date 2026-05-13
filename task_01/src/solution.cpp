#include "solution.hpp"

// bool operator==(const Answer& lhs, const Answer& rhs) {
//     if (!lhs.have_answer && !rhs.have_answer) {
//         return true;
//     }
//     return lhs.have_answer == rhs.have_answer &&  lhs.lhs == rhs.lhs && lhs.rhs == rhs.rhs;
// }

Answer SumOfTwo(std::vector<int> arr, int summ) {
    int i = 0, j = arr.size() - 1;
    while (i < j) {
        int cur_summ = arr[i] + arr[j];
        if (cur_summ == summ) {
            return Answer(arr[i], arr[j]);
        }
        if (cur_summ < summ) {
            i++;
        } else {
            j--;
        }
    }
    return Answer();
}
