#ifndef MY_MAP_HPP
#define MY_MAP_HPP

template <typename Key, typename T>
class MyMap
{
public:
        virtual void add(Key key, T val) = 0;
        virtual void remove(Key key) = 0;
        virtual void set(Key key, T val) = 0;
        virtual  T get(Key key) = 0;

        virtual bool contains(T val) = 0;
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
};

#endif