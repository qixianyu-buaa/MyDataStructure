#ifndef MY_ARRAY_STACK_HPP
#define MY_ARRAY_STACK_HPP
#include "array/MyArrary.hpp"
#include "stack/MyStack.hpp"

//  利用数组在尾部插入和删除为O(1)的时间复杂度，所以动态数组栈的复杂度为O(1)
template <typename T>
class MyArrayStack : public MyStack<T>
{
private:
        MyArray<T> *stack_;

public:
        MyArrayStack(int capacity = 10)
        {
                stack_ = new MyArray<T>(capacity);
        }

        ~MyArrayStack()
        {
                delete stack_;
                stack_ = nullptr;
        }

        void push(T e)
        {
                stack_->addLast(e);
        }

        T pop()
        {
                stack_->removeLast();
        }
        T peek()
        {
                return stack_->getLast();
        }
        int getSize()
        {
                return stack_->getSize();
        }
        bool isEmpty()
        {
                return stack_->isEmpty();
        }

        //打印数组的所有元素
        void print()
        {
                std::cout << "Stack: size = " << stack_->getSize() << ", capacity = " << stack_->getCapacity() << std::endl;
                std::cout << "bottom ";
                stack_->toPrint();
                std::cout << " top" << std::endl;
        }
};

#endif