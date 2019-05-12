#include <iostream>
using namespace std;

namespace itertools
{
template <typename T>
class range
{

private:
    class iterator
    {

    private:
        T value;

    public:
        iterator(int v) : value(v) {}
        T operator*()
        {
            return value;
        }
        bool operator==(iterator &other)
        {
            return value == other.value;
        }
        bool operator!=(iterator &other)
        {
            return !(value == other.value);
        }
        iterator operator++(int)
        {
            iterator temp = *this;
            value++;
            return temp;
        }
        iterator operator++()
        {
            value++;
            return *this;
        }
    };
 T _begin;
    T _end;
public:
    
    range(T a, T b)
    {
        _begin = a;
        _end = b;
    }
    range(range &r)
    {
        _begin = r.begin();
        _end = r.end();
    }
    iterator begin()
    {
        return iterator(_begin);
    }
    iterator end()
    {
        return iterator(_end);
    }
};
}; // namespace itertools