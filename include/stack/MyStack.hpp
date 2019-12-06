#ifndef MY_STACK_HPP
#define MY_STACK_HPP
//  栈：先进后出
// 应用：撤销、系统调用栈、括号匹配等
//  具有多种不同的实现，C++标准库中也叫作容器适配器

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