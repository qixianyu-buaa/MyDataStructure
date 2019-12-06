#ifndef MY_STACK_HPP
#define MY_STACK_HPP

template <typename T>
class MyStack
{
public:
        virtual void push(T e) = 0;
        virtual T pop() = 0;
        virtual T peek() = 0;
        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        virtual ~MyStack()
        {}
};

#endif