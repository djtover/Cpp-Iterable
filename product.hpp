#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class product
{
private:
    T first;
    U second;
    class iterator
    {
    private:
        T first;
        U second;

    public:
        iterator(T a, U b) : first(a), second(b) {}
       
    };

public:
    product(T a, U b) : first(a), second(b)
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
