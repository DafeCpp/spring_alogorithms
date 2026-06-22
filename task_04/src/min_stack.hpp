#include <algorithm>

class MinStack {
public:
    void Push(int value);
    int Pop();
    int GetMin();
    MinStack();
    ~MinStack();
private:
    struct MinNode {
        int value;
        int min;
        MinNode *prev;
    };
    MinNode *head;
};