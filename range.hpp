

#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename T>
class Range
{
private:
    T _begin;
    T _end;

public:
    Range(T &input1, T &input2) : _begin(input1), _end(input2){};

    class iterator
    {
    private:
        T valuePtr;

    public:
        iterator(T ptr)
        {
            this->valuePtr = ptr;
        }

        T &operator*()
        {
            return valuePtr;
        }
        // bool operator==(const iterator &input) const
        // {
        //     return valuePtr == input.valuePtr;
        // }
        bool operator!=(const iterator &input) const
        {
            return valuePtr != input.valuePtr;
        }

        // iterator &operator=(const iterator &input)
        // {
        //     valuePtr = input.valuePtr;
        //     return *this;
        // }
        // const iterator operator++(int)
        // {
        //     iterator tmp = *this;
        //     valuePtr++;
        //     return tmp;
        // }
        iterator &operator++()
        {
            ++valuePtr;
            return *this;
        }
    };

    iterator begin()
    {
        return iterator{_begin};
    }

    iterator end()
    {
        return iterator{_end};
    }
};

template <typename T>
Range<T> range(T s, T e)
{
    return Range<T>(s, e);
}

} // namespace itertools
