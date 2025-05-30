#pragma once

#include <vector>
#include <functional>


template<typename T>
class hashtable final
{
private:
    struct Node
    {
        bool full;
        T value;
        Node(T value) : full(true), value(value) {}
    };

    size_t buffer_size = 64;
    size_t size = 0;
    size_t active_size = 0;
    std::vector<Node*> buffer{buffer_size, nullptr};

    std::function<size_t(T)> beginHash, stepHash;


public:
    hashtable(std::function<size_t(T)> beginHash, std::function<size_t(T)> stepHash) : beginHash(beginHash), stepHash(stepHash) {};
    bool find(T value)
    {
        size_t begin = beginHash(value);
        size_t step = stepHash(value);

        size_t i = 0;
        while (buffer[begin] != nullptr || i++ < buffer_size)
        {
            if (buffer[begin]->value == value)
                return true;
            begin = (begin + step) % buffer_size;
        }
        return false;
    }

    void resize()
    {
        buffer_size *= 2;
        std::vector<Node*> old_buffer{buffer_size, nullptr};
        std::swap(buffer, old_buffer);
        
        for (size_t i = 0; i < old_buffer.size(); ++i)
        {
            if (old_buffer[i] != nullptr)
            {
                if (old_buffer[i]->full)
                    add(old_buffer[i]->value);
                
                delete old_buffer[i];
            }
        }
    }

    void rehash()
    {
        std::vector<Node*> old_buffer{buffer_size, nullptr};
        std::swap(buffer, old_buffer);
        
        for (size_t i = 0; i < old_buffer.size(); ++i)
        {
            if (old_buffer[i] != nullptr)
            {
                if (old_buffer[i]->full)
                    add(old_buffer[i]->value);
                
                delete old_buffer[i];
            }
        }
    }
    
    bool add(T value)
    {
        if (active_size + 1 > int(0.75 * buffer_size)) resize();
        if (size > 2 * active_size) rehash();

        size_t begin = beginHash(value);
        size_t step = stepHash(value);

        size_t i = 0;
        size_t new_elem = -1;
        while (buffer[begin] != nullptr || i++ < buffer_size)
        {
            if (buffer[begin]->value == value)
                return false;
            
            if (!buffer[begin] && !buffer[begin]->full)
                new_elem = begin;
            begin = (begin + step) % buffer_size;
        }
        
        if (new_elem == -1)
        {
            buffer[begin] = new Node(value);
            ++active_size;
        }
        else
        {
            buffer[begin]->value = value;
            buffer[begin]->full = true;
        }

        ++size;
        return true;
    }

    bool remove(T value)
    {
        size_t begin = beginHash(value);
        size_t step = stepHash(value);

        size_t i = 0;
        while (buffer[begin] != nullptr || i++ < buffer_size)
        {
            if (buffer[begin]->value == value)
            {
                buffer[begin]->full = false;
                return true;
            }

            begin = (begin + step) % buffer_size;
        }
        return false;
    }
};
