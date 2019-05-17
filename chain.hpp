#pragma once
#include <iostream>
using namespace std;
namespace itertools
{
template <typename T, typename U>
class chainIt
{

private:
    const pair<T,T> first;
    const pair<U,U> second;

public:
    chainIt(pair<T,T> a, pair<U,U> b) : first(a), second(b){}

    class iterator
    {
    private:
        bool inFirst;
        pair<T,T> firstP;
        pair<U,U> secondP;

    public:
        iterator(pair<T,T> a, pair<U,U> b, bool flag) : firstP(a), secondP(b), inFirst(flag){};

        auto &operator*()
        {
            if (inFirst){
                return *firstP.first;
            }
            return *secondP.first;
        }

        bool operator==(const iterator &other) const
        {
            if (inFirst){
                return firstP.first == other.firstP.second;
            }
            return secondP.first == other.secondP.second;
        }

        

        iterator &operator=(const iterator &other)
        {
            firstP = other.firstP;
            secondP = other.secondP;
            inFirst = other.inFirst;
            return *this;
        }

        bool operator!=(const iterator &other) const
        {

            if (inFirst){
                return firstP.first != other.firstP.second;

            }
            return secondP.first != other.secondP.second;
        }
        iterator &operator++()
        {
            if (inFirst)
            {
                if (++firstP.first == firstP.second){
                    inFirst = false;
                }

                return *this;
            }
            secondP.first++;
            return *this;
        }
        const iterator operator++(int)
        {
            iterator temp = *this;
            if (inFirst)
            {
                if (++firstP.first == firstP.second)
                    inFirst = false;
                return *this;
            }
            secondP.first++;
            return temp;
        }
    };
public:
    auto begin() 
    {
        return iterator{first, second, true};
    }

    auto end() 
    {
        return iterator{first, second, false};
    }
};

template <typename T, typename U>
auto chain(T first, U second)
{
    pair<decltype(first.begin()), decltype(first.end())> firstP(first.begin(), first.end());
    pair<decltype(second.begin()), decltype(second.end())> secondP(second.begin(), second.end());

    return chainIt<decltype(first.begin()), decltype(second.begin())>(firstP, secondP);
}

} // namespace itertools
