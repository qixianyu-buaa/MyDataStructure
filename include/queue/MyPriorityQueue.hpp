#ifndef MY_PROPRITY_QUEUE_HPP
#define MY_PROPRITY_QUEUE_HPP
#include "queue/MyQueue.hpp"
#include "heap/MyBinaryHeap.hpp"
template <typename T>
class MyPriorityQueue : public MyQueue<T>
{
private:
        MyBinaryHeap<T> *queue_;

public:
        MyPriorityQueue()
        {
                queue_ = new   MyBinaryHeap<T>;
        }
        ~MyPriorityQueue()
        {
                delete queue_;
                queue_ = nullptr;
        }

        void enQueue(T e) // O(1)
        {
                queue_->add(e);
        }
        T deQueue() // O(n)!!!!
        {
                return queue_->removeMax();
        }
        T getFront() // O(1)
        {
                return queue_->getMax();
        }
        int getSize() // O(1)
        {
                return queue_->getSize();
        }
        bool isEmpty() // O(1)
        {
                return queue_->isEmpty();
        }
 
        void print()
        {
                queue_->print();
        }
};

#endif