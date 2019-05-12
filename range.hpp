#include <iostream>
#include <iterator>
using namespace std;

namespace itertools{
template <typename T>class range{


private:
class myiter{

    private:
    int value;

    public:
    myiter(int v): value(v){}
     T operator*(){
        return value;
    }
    bool operator== (myiter& other){
        return value == other.value;
    }
    bool operator!= (myiter& other){
        return !(value == other.value);
    }
    myiter operator++(int){
        T v = value;
        ++value;
        return myiter(v);
    }
    myiter operator++(){
        ++value;
        return *this;
    }
};

public:
T _begin;
T _end;
    range(T a, T b){
        _begin = a;
        _end =b;
    }
    range(range &r){
        _begin = r->begin();
        _end = r->end();
    }
    myiter begin(){
        return myiter(_begin);
    }
    myiter end(){
        return myiter(_end);
    }




};
};