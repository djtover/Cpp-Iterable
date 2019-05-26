
#pragma once
#include <iostream>
using namespace std;

namespace itertools
{

template <typename T, typename U>
class Product
{

private:
    pair<T, U> first; 
    pair<T, U> second;

public:
    Product(pair<T, U> &input1, pair<T, U> &input2) : first(input1), second(input2) {}

    class iterator
    {
    private:
        pair<T, U> firstP;
        pair<U, U> secondP;

    public:
        iterator(pair<T, U> input1, pair<U, U> input2) : firstP(input1), secondP(input2) {}

        pair<T, U> &operator*()
        {
            return firstP;
        }

        // bool operator==(const iterator &input) const
        // {
        //     return firstP.first == input.firstP.first;
        // }

        bool operator!=(const iterator &input) const
        {
            return firstP.first != input.firstP.first;
        }

        // iterator &operator=(const iterator &input)
        // {
        //     this->firstP.first = input.firstP.first;
        //     this->firstP.second = input.firstP.second;
        //     this->secondP.first = input.secondP.first;
        //     this->secondP.second = input.secondP.second;
        //     return *this;
        // }

        iterator &operator++()
        {
            firstP.second++;
            if (firstP.second == secondP.second)
            {
                ++firstP.first;
                firstP.second = secondP.first;
            }
            return *this;
        }

        // const iterator operator++(int)
        // {
        //     iterator temp = *this;
        //     firstP.second++;
        //     if (firstP.second == secondP.second)
        //     {
        //         firstP.first++;
        //         firstP.second = secondP.first;
        //     }
        //     return temp;
        // }
    };

public:
    iterator begin()
    {
        return iterator(first, pair<U, U>(first.second, second.second));
    }

    iterator end()
    {
        return iterator(pair<T, U>(second.first, second.second), pair<U, U>(first.second, second.second));
    }
};

template <typename T, typename U>
auto product(T TProduct, U UProduct)
{
    pair first(TProduct.begin(),UProduct.begin());
    pair second (TProduct.end(), UProduct.end());

    return Product(first,second);
}

} // namespace itertools