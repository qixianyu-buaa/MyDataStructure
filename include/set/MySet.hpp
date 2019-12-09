#ifndef MY_SET_HPP
#define MY_SET_HPP

template <typename T>
class MySet
{
public:
        virtual void add(T val) = 0;
        virtual void remove(T val) = 0;
        virtual bool contains(T val) = 0;
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void  print() = 0;
};

#endif