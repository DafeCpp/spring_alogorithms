#include <vector>

struct Answer {
    int lhs, rhs;
    bool have_answer;
    Answer(): have_answer(false) {}
    Answer(int l, int r): lhs(l), rhs(r), have_answer(true) {}
    bool operator==(const Answer other) {
        if (!have_answer && !other.have_answer) {
            return true;
        }
        return have_answer == other.have_answer && lhs == other.lhs && rhs == other.rhs;
    }
};

Answer SumOfTwo(std::vector<int> arr, int summ);
