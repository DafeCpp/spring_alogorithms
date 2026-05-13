class Stack {
public:
    void Push(int value);
    int Pop();
    Stack();
    ~Stack();
private:
    struct Node {
        int value;
        int min;
        Node *prev;
    };
    Node *head;
};