
#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename T, typename U>
class productIt
{

private:
    pair<T, U> first; 
    pair<T, U> second;

public:
    productIt(pair<T, U> &a, pair<T, U> &b) : first(a), second(b) {}

    class iterator
    {
    private:
        pair<T, U> firstP;
        pair<U, U> secondP;

    public:
        iterator(pair<T, U> a, pair<U, U> b) : firstP(a), secondP(b) {}

        pair<T, U> &operator*()
        {
            return firstP;
        }

        bool operator==(const iterator &other) const
        {
            return firstP.first == other.firstP.first;
        }

        bool operator!=(const iterator &other) const
        {
            return firstP.first != other.firstP.first;
        }

        iterator &operator=(const iterator &other)
        {
            this->firstP.first = other.firstP.first;
            this->firstP.second = other.firstP.second;
            this->secondP.first = other.secondP.first;
            this->secondP.second = other.secondP.second;
            return *this;
        }

        iterator &operator++()
        {
            firstP.second++;
            if (firstP.second == secondP.second)
            {
                firstP.first++;
                firstP.second = secondP.first;
            }
            return *this;
        }

        const iterator operator++(int)
        {
            iterator temp = *this;
            firstP.second++;
            if (firstP.second == secondP.second)
            {
                firstP.first++;
                firstP.second = secondP.first;
            }
            return temp;
        }
    };

public:
    auto begin()
    {
        return iterator(first, pair<U, U>(first.second, second.second));
    }

    auto end()
    {
        return iterator(pair<T, U>(second.first, second.second), pair<U, U>(first.second, second.second));
    }
};

template <typename T, typename U>
auto product(T TProduct, U UProduct)
{
    pair first(TProduct.begin(),UProduct.begin());
    pair second (TProduct.end(), UProduct.end());

    return productIt(first,second);
}

} // namespace itertools