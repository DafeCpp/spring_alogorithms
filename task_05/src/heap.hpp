#ifndef HEAP_HPP
#define HEAP_HPP

#include<vector>
#include<stdexcept>
#include <algorithm>

template <typename T>
class Heap
{
public:
    Heap(std::vector<T> list){for (auto c: list){append_element(c);}}
    T pop_min();
    void append_element(T element);
private:
    std::vector<T> tree;

    void siftup();
    void siftdown();

    int parent_index(int index_of_element){return (index_of_element - 1)/2;}
    int left_child_index(int index_of_element){return 2*index_of_element+1;}
    int right_child_index(int index_of_element){return 2*index_of_element+2;}
};


template<typename T>
T Heap<T>::pop_min()
{
    if (tree.empty()) {throw std::runtime_error("heap is empty");}
    T min_elem = tree[0];
    siftdown();
    return min_elem;
}


template<typename T>
void Heap<T>::append_element(T element)
{
    tree.push_back(element);
    siftup();
}


template<typename T>
void Heap<T>::siftup()
{
    int index = tree.size() - 1;
    while (index != 0)
    {
        int p_ind = parent_index(index);
        if (tree[p_ind] > tree[index])
        {
            T bufer = tree[index];
            tree[index] = tree[p_ind];
            tree[p_ind] = bufer;
        }
        index = p_ind;
    }
}


template<typename T>
void Heap<T>::siftdown()
{
    if (tree.empty()) return;
    tree[0] = tree.back();
    tree.pop_back();
    int index{0};
    while(left_child_index(index) < tree.size()) //существует хотя бы 1 потомок. Если левого потомка нет, то и правого тоже быть не может
    {
        int l_c_ind = left_child_index(index);
        int r_c_ind = right_child_index(index);
        if (r_c_ind >= tree.size()) //проверка на существование правого потомка
        {
            if (tree[l_c_ind]<tree[index])
            {
                std::swap(tree[index], tree[l_c_ind]);
                index = l_c_ind;
                continue;
            }
            break;
        }
        int ind_of_min_elem = tree[l_c_ind]<tree[r_c_ind]?l_c_ind:r_c_ind;
        if(tree[index] > tree[ind_of_min_elem])
        {
            std::swap(tree[index], tree[ind_of_min_elem]);
        }
        index = ind_of_min_elem;
    }
}



template <typename T>
std::vector<T> Heap_sort(std::vector<T> list)
{
    std::vector<T> return_vector;
    Heap<T> heap = Heap(list);
    while(return_vector.size() != list.size())
    {
        return_vector.push_back(heap.pop_min());
    }
    return return_vector;
}

#endif //HEAP_HPP