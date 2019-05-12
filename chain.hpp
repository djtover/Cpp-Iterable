#include <iostream>
using namespace std;

namespace itertools
{
template <typename T, typename U>
class chain
{
private:
    T _begin;
    U _end;

    class iterator
    {
    private:
        T TStart;
        T TEnd;
        U UStart;
        U UEnd;

    public:
        iterator(T aStart, T aEnd, T bStart) : TStart(aStart), TEnd(aEnd), UStart(bStart) {}
        auto operator*()
        {
            if (TStart != TEnd)
            {
                return TStart;
            }
            return UStart;
        }
        bool operator==(iterator &other)
        {
            return (*TStart == *other.TStart) && (*UStart == *other.UStart);
        }
        bool operator!=(iterator &other)
        {
            return !((*TStart == *other.TStart) && (*UStart == *other.UStart));
        }
        iterator operator++()
        {
            if (TStart != TEnd)
            {
                TStart++;
            }
            else
            {
                UStart++;
            }
            return *this;
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            ++*this;
            return temp;
        }
    };

public:
    chain(T a, U b)
    {
        _begin = a;
        _end = b;
    }
    iterator begin()
    {
        
    }
    iterator end()
    {
       
    }
};

}; // namespace itertools
