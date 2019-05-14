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
