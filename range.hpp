#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T>
class range
{

private:
    class iterator
    {

    private:
        T value;

    public:
        iterator(T v) : value(v) {}
        T &operator*()
        {
            return value;
        }
        bool operator==(const iterator &other)const
        {
            return value == other.value;
        }
        bool operator!=(const iterator &other) const
        {
            return (this->value != other.value);
        }
        iterator &operator++(int dc)
        {
            iterator temp = *this;
            this->value++;
            return temp;
        }
        iterator &operator++()
        {
            value++;
            return *this;
        }
    };
    T _begin;
    T _end;
public:
    
    range(T a, T b)
    {
        this->_begin = a;
        this->_end = b;
    }
    range(range &r)
    {
        _begin = r._begin;
        _end = r._end;
    }
    iterator begin()
    {
        return iterator(this->_begin);
    }
    iterator end()
    {
        return iterator(this->_end);
    }
};
}; // namespace itertools
