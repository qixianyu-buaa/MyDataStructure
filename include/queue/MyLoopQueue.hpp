#ifndef MY_LOOP_QUEUE_HPP
#define MY_LOOP_QUEUE_HPP
#include "queue/MyQueue.hpp"
#include "array/MyArrary.hpp"

//  涉及到 first ++  or last++  取%操作

template <typename T>
class MyLoopQueue : public MyQueue<T>
{
private:
        T *queue_;
        int first_;
        int last_;
        int capacity_;

        void resize(int new_capacity)
        {
                assert(getSize() < new_capacity + 1);

                T *new_queue = new T[new_capacity + 1];

                int i = 0;
                while ((i + first_) % capacity_ != last_)
                {
                        new_queue[i] = queue_[(i + first_) % capacity_];
                        ++i;
                }

                T *temp = queue_;
                queue_ = new_queue;
                delete temp;

                capacity_ = new_capacity;
                last_ = i;
                first_ = 0;
        }

public:
        MyLoopQueue(int capacity = 10) : capacity_(capacity)
        {
                queue_ = new T[capacity + 1];
                first_ = last_ = 0;
        }
        ~MyLoopQueue()
        {
                delete queue_;
                queue_ = nullptr;
        }

        void enQueue(T e) // O(1)
        {
                if (isFull())
                        resize(2 * capacity_);

                queue_[last_] = e;
                last_ = (last_ + 1) % capacity_;
        }
        T deQueue() // O(1)
        {
                assert(!isEmpty());
                T ret = queue_[first_];
                first_ = (first_ + 1) % capacity_;

                if (getSize() == capacity_ / 4 && capacity_ / 2 != 0)
                        resize(capacity_ / 2);
        }
        T getFront() // O(1)
        {
                assert(!isEmpty());
                return queue_[first_];
        }
        int getSize() // O(1)
        {
                return (last_ - first_ + capacity_) % capacity_;
        }
        bool isEmpty() // O(1)
        {
                return first_ == last_;
        }
        bool isFull() //  O(1)
        {
                return ((last_ + 1) % capacity_ == first_);
        }

        int getCapacity() //  O(1)
        {
                return capacity_;
        }

        void print()
        {
                std::cout << "Queue: size = " << getSize() << ", capacity = " << capacity_ << std::endl;
                std::cout << "front [";
                for (int i = first_; i != last_; i = (i + 1) % capacity_)
                {
                        std::cout << queue_[i];
                        if ((i + 1) % capacity_ != last_)
                        {
                                std::cout << ", ";
                        }
                }
                std::cout << "] tail" << std::endl;
        }
};

#endif