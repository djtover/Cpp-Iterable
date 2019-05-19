#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class Zip
{

private:
    pair<T,U> first;
    pair<T,U> second;

public:
    Zip(pair<T, U> &input1, pair<T, U> &input2) : first(input1), second(input2) {}

    class iterator
    {
    private:
        pair<T, U> it;

    public:
        iterator(pair<T, U> &input) : it(input) {}

        pair<T, U> &operator*()
        {
            return it;
        }
        // bool operator==(const iterator &input) const
        // {
        //     return it.first == input.it.first;
        // }
        bool operator!=(const iterator &input) const
        {
            return it.first != input.it.first;
        }
        // iterator &operator=(const iterator &input)
        // {
        //     this->it.first = input.it.first;
        //     this->it.second = input.it.second;
        //     return *this;
        // }
        iterator &operator++() 
        {
            ++it.first;
            ++it.second;
            return *this;
        }
        // const iterator operator++(int) 
        // {
        //     iterator tmp = *this;
        //     it.first++;
        //     it.second++;
        //     return tmp;
        // }
    };

public:
    iterator begin()
    {
        return iterator(first);
    }
    iterator end()
    {
        return iterator(second);
    }
};

template <typename T, typename U>
auto zip(T firstP, U secondP)
{
    pair first(firstP.begin(), secondP.begin());
    pair second(firstP.end(),secondP.end());
    return Zip(first, second);
}

} // namespace itertools

template <typename T, typename U>
ostream &operator<<(ostream &os, std::pair<T, U> &p)
{
    os << *p.first<< ","<< *p.second;
    return os;
}
