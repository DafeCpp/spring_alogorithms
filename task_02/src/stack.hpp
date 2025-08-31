#ifndef STACK_H
#define STACK_H

#include <stack>
#include <vector>

#include<vector>
#include<stdexcept>

template <typename T>
class Stack
{
public:
    void push_element(T elem);
    T pop_element();
    bool is_empty(){return value_list.size() == 0;}
private:
    std::vector<T> value_list;
};

template<typename T>
void Stack<T>::push_element(T elem)
{
  value_list.push_back(elem);
}

template<typename T>
T Stack<T>::pop_element()
{
    if (value_list.empty()){
        throw std::runtime_error("stack is empty");
    }
    T last_element = value_list.back();
    value_list.pop_back();
    return last_element;
}




template <typename T>
class MinStack
{
public:
    void push_element(T elem);
    T pop_element();
    T get_min();
    bool is_empty(){return value_list.size() == 0;}
private:
    std::vector<T> value_list;
    std::vector<T> min_list;
};


template<typename T>
void MinStack<T>::push_element(T elem)
{
    value_list.push_back(elem);
    if (min_list.empty() || elem < min_list.back())
    {
        min_list.push_back(elem);
    }
}

template<typename T>
T MinStack<T>::pop_element()
{
    if (value_list.empty()){
        throw std::runtime_error("stack is empty");
    }
    if (value_list.back() == min_list.back()){
        min_list.pop_back();
    }
    T last_element = value_list.back();
    value_list.pop_back();
    return last_element;
}

template<typename T>
T MinStack<T>::get_min()
{
    if (min_list.empty()){
        throw std::runtime_error("stack is empty");
    }
    return min_list.back();
}

#endif //STACK_H