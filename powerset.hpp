#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T>
class powerset
{
private:
    T first;
    // U second;
    class iterator
    {
    private:
        T first;
        // U second;

    public:
        iterator(T a) : first(a) {}
        //     auto operator*()
        //     {
        //         if (TStart != TEnd)
        //         {
        //             return TStart;
        //         }
        //         return UStart;
        //     }
        //     bool operator==(iterator &other)
        //     {
        //         return (TStart == other.TStart) && (UStart == other.UStart);
        //     }
        //     bool operator!=(iterator &other)
        //     {
        //         return !((TStart == other.TStart) && (UStart == other.UStart));
        //     }
        //     iterator operator++()
        //     {
        //         if (TStart != TEnd)
        //         {
        //             TStart++;
        //         }
        //         else
        //         {
        //             UStart++;
        //         }
        //         return *this;
        //     }
        //     iterator operator++(int)
        //     {
        //         iterator temp = *this;
        //         ++*this;
        //         return temp;
        //     }
    };

public:
    powerset(T a) : first(a)
    {
    }
    auto begin()
    {
        return first.begin();
    }
    auto end()
    {
        return first.begin();
    }
};

}; // namespace itertools
