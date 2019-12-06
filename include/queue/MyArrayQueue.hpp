#ifndef MY_ARRAY_QUEUE_HPP
#define MY_ARRAY_QUEUE_HPP
#include "queue/MyQueue.hpp"
#include "array/MyArrary.hpp"
template <typename T>
class MyArrayQueue : public MyQueue<T>
{
private:
        MyArray<T> *queue_;

public:
        MyArrayQueue(int capacity = 10)
        {
                queue_ = new MyArray<T>(capacity);
        }
        ~MyArrayQueue()
        {
                delete queue_;
                queue_ = nullptr;
        }

        void enQueue(T e) // O(1)
        {
                queue_->addLast(e);
        }
        T deQueue() // O(n)!!!!
        {
                return queue_->removeFirst();
        }
        T getFront() // O(1)
        {
                return queue_->getFirst();
        }
        int getSize() // O(1)
        {
                return queue_->getSize();
        }
        bool isEmpty() // O(1)
        {
                return queue_->isEmpty();
        }
        int getCapacity()
        {
                return queue_->getCapacity();
        }

        void print()
        {
                std::cout << "Queue: size = " << queue_->getSize() << ", capacity = " << queue_->getCapacity() << std::endl;
                std::cout << "front ";
                queue_->toPrint();
                std::cout << " tail" << std::endl;
        }
};

#endif