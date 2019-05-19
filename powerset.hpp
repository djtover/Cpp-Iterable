
#pragma once

#include <iostream>

namespace itertools
{
template <typename T>
class PowerSet
{
private:
    T set;

public:
    PowerSet( T &input) : set(input) {}

    class iterator
    {
        std::pair<T, uint> p; // uint - save the bits we need to print

    public:
        iterator(std::pair<T, uint> input) : p(input) {}

        std::pair<T, uint> &operator*()
        {
            return p;
        }

        // bool operator==(const iterator &input) const
        // {
        //     return p.second == input.p.second;
        // }

        bool operator!=(const iterator &input) const
        {
            return p.second != input.p.second;
        }

        // iterator &operator=(const iterator &input)
        // {
        //     p.first = input.p.first;
        //     p.second = input.p.second;
        //     return *this;
        // }

        // ++i;
        iterator &operator++()
        {
            ++p.second;
            return *this;
        }

        // i++;
        // const iterator operator++(int)
        // {
        //     iterator tmp = *this;
        //     p.second++;
        //     return tmp;
        // }
    };

public:
    iterator begin() 
    {
        return iterator(std::pair<T, uint>(set, 0));
    }

    iterator end() 
    {
        int i = 1;
        auto iter = set.begin();
        while (iter != set.end())
        {
            i = i << 1;
            ++iter;
        }
        return iterator(std::pair<T, uint>(set, i));
    }
};

template <typename T>
PowerSet<T> powerset(T input)
{
    return PowerSet<T>(input);
}

} // namespace itertools

// insert to ostream the correct set by bits
template <typename U>
std::ostream &operator<<(std::ostream &os, std::pair<U, uint> &a)
{
    os << "{";
    auto curr = a.first.begin();
    auto end = a.first.end();
    int i = 1;
    bool inFirst = true;
    while (curr != end) 
    {
        if (i & a.second)
        {
            if (!inFirst)
                os << ",";
                
            os << *curr;
            inFirst = false;
        }
        ++curr;
        i = i << 1;
    }
    os << "}";
    return os;
}