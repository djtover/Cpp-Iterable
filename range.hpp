

#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename T>
class rangeIt
{
private:
    T _begin;
    T _end;

public:
    rangeIt(T &a, T &b) : _begin(a), _end(b){};

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
        bool operator==(const iterator &other) const
        {
            return valuePtr == other.valuePtr;
        }
        bool operator!=(const iterator &other) const
        {
            return valuePtr != other.valuePtr;
        }

        iterator &operator=(const iterator &other)
        {
            valuePtr = other.valuePtr;
            return *this;
        }
        const iterator operator++(int)
        {
            iterator tmp = *this;
            valuePtr++;
            return tmp;
        }
        iterator &operator++()
        {
            valuePtr++;
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
rangeIt<T> range(T s, T e)
{
    return rangeIt<T>(s, e);
}

} // namespace itertools
