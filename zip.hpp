#pragma once
#include <iostream>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class zipIt
{

private:
    pair<T,U> first;
    pair<T,U> second;

public:
    zipIt(pair<T, U> &a, pair<T, U> &b) : first(a), second(b) {}

    class iterator
    {
    private:
        pair<T, U> it;

    public:
        iterator(pair<T, U> &other) : it(other) {}

        pair<T, U> &operator*()
        {
            return it;
        }
        bool operator==(const iterator &other) const
        {
            return it.first == other.it.first;
        }
        bool operator!=(const iterator &other) const
        {
            return it.first != other.it.first;
        }
        iterator &operator=(const iterator &other)
        {
            this->it.first = other.it.first;
            this->it.second = other.it.second;
            return *this;
        }
        iterator &operator++() 
        {
            it.first++;
            it.second++;
            return *this;
        }
        const iterator operator++(int) 
        {
            iterator tmp = *this;
            it.first++;
            it.second++;
            return tmp;
        }
    };

public:
    auto begin()
    {
        return iterator(first);
    }
    auto end()
    {
        return iterator(second);
    }
};

template <typename T, typename U>
auto zip(T firstP, U secondP)
{
    pair first(firstP.begin(), secondP.begin());
    pair second(firstP.end(),secondP.end());
    return zipIt(first, second);
}

} // namespace itertools

template <typename T, typename U>
ostream &operator<<(ostream &os, std::pair<T, U> &p)
{
    os << *p.first<< ","<< *p.second;
    return os;
}
