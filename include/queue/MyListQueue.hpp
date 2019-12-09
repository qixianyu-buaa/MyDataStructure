#ifndef MY_LIST_QUEUE_HPP
#define MY_LIST_QUEUE_HPP
#include "queue/MyQueue.hpp"
#include "list/MyLinkedList.hpp"

//  涉及到 first ++  or last++  取%操作

template <typename T>
class MyListQueue : public MyQueue<T>
{
private:
        MyLinkedList<T> *list_;

public:
        MyListQueue()
        {
                list_ = new MyLinkedList<T>;
        }
        ~MyListQueue()
        {
                delete list_;
                list_ = nullptr;
        }

        void enQueue(T e) // O(n)
        {
                list_->addLast(e);
        }
        T deQueue() // O(1)
        {
                return list_->removeFirst();
        }
        T getFront() // O(1)
        {

                return list_->getFirst();
        }
        int getSize() // O(1)
        {
                return list_->getSize();
        }
        bool isEmpty() // O(1)
        {
                return list_->isEmpty();
        }

        void print()
        {
                std::cout << "Queue: size = " << getSize() << std::endl;
                std::cout << "front [";
                list_->toPrint();
        }
};

#endif