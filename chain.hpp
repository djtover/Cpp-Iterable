#pragma once
#include <iostream>
using namespace std;
namespace itertools
{
template <typename T, typename U>
class Chain
{

private:
     pair<T,T> first;
     pair<U,U> second;

public:
    Chain(pair<T,T> input1, pair<U,U> input2) : first(input1), second(input2){}

    class iterator
    {
    private:
        bool inFirst;
        pair<T,T> firstP;
        pair<U,U> secondP;

    public:
        iterator(pair<T,T> input1, pair<U,U> input2, bool flag) : firstP(input1), secondP(input2), inFirst(flag){};

        auto &operator*()
        {
            if (inFirst){
                return *firstP.first;
            }
            return *secondP.first;
        }

        // bool operator==(const iterator &input) const
        // {
        //     if (inFirst){
        //         return firstP.first == input.firstP.second;
        //     }
        //     return secondP.first == input.secondP.second;
        // }

        

        // iterator &operator=(const iterator &input)
        // {
        //     firstP = input.firstP;
        //     secondP = input.secondP;
        //     inFirst = input.inFirst;
        //     return *this;
        // }

        bool operator!=(const iterator &input) const
        {

            if (inFirst){
                return firstP.first != input.firstP.second;

            }
            return secondP.first != input.secondP.second;
        }
        iterator &operator++()
        {
            if (inFirst)
            {
                if (!(++firstP.first != firstP.second)){
                    inFirst = false;
                }

                return *this;
            }
            ++secondP.first;
            return *this;
        }
        // const iterator operator++(int)
        // {
        //     iterator temp = *this;
        //     if (inFirst)
        //     {
        //         if (++firstP.first == firstP.second)
        //             inFirst = false;
        //         return *this;
        //     }
        //     secondP.first++;
        //     return temp;
        // }
    };
public:
    iterator begin() 
    {
        return iterator{first, second, true};
    }

    iterator end() 
    {
        return iterator{first, second, false};
    }
};

template <typename T, typename U>
auto chain(T first, U second)
{
    pair firstP(first.begin(),first.end());
    pair secondP(second.begin(), second.end());

    return Chain (firstP,secondP);
}

} // namespace itertools
