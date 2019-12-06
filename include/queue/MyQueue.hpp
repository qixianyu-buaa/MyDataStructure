#ifndef MY_QUEUE_HPP
#define MY_QUEUE_HPP

//  先进先出

template <typename T>
class MyQueue
{
public:
        virtual void enQueue(T e) = 0;
        virtual T deQueue() = 0;
        virtual T getFront() = 0;

        virtual int getSize() = 0;
        virtual bool isEmpty() = 0;
        virtual void print() = 0;
        int getCapacity(){

        };

        virtual ~MyQueue()
        {
        }
};

#endif