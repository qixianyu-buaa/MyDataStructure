#ifndef MY_LIST_STACK_HPP
#define MY_LIST_STACK_HPP
#include "list/MyLinkedList.hpp"
#include "stack/MyStack.hpp"
#include <cassert>
#include <iostream>

template <typename T>
class MyListStack : public MyStack<T>
{
private:
        MyLinkedList<T> *list_;

public:
        MyListStack()
        {
                list_ = new MyLinkedList<T>;
        }
        ~MyListStack()
        {
                delete list_;
        }
        void push(T e)
        {
                list_->addFirst(e);
        }
        T pop()
        {
                return list_->removeFirst();
        }
        T peek()
        {
                return list_->getFirst();
        }
        int getSize()
        {
                return list_->getSize();
        }
        bool isEmpty()
        {
                return list_->isEmpty();
        }
        void print()
        {
                std::cout << "ListStack: size = " << getSize() << std::endl;
                std::cout << "top ";
                list_->toPrint();
        }
};

#endif
