#ifndef MY_ARRAY_HPP
#define MY_ARRAY_HPP
#include <iostream>
#include <cassert>

// 数组的特点，具有随机访问的能力，并且最好应用于索引有语义的情况
// MyArray封装了c++中的原生数组，实现了增删改查的功能。
// 此外，该数组如std::vector<>一样，也可以动态变化；值得注意的是，该类还实现了容量的缩小，
// 为了解决复杂度震荡问题，采用了size == capacity /4 时，才把capacity/2的 lazy策略
//  复杂度分析：
//  addFirst : O (n)
//  addLast: O (1)
//  add: O(n)
//  remove: O(n)
//  removeLast: O(1)
//  remove: O(n)
//  contains: O(n)
//  find: O(n)
//  resize: O(n)

template <typename T>
class MyArray
{
private:
        // data member and resize method
        T *data_;
        int size_;
        int capacity_;

        void resize(int new_capacity)
        {
                T *new_data = new T[new_capacity];
                for (int i = 0; i < size_; ++i)
                {
                        new_data[i] = data_[i];
                }

                T *temp;
                temp = data_;
                data_ = new_data;
                delete temp;

                capacity_ = new_capacity;
        }

public:
        MyArray(int capacity = 10) : capacity_(capacity), size_(0)
        {
                data_ = new T[capacity];
        }

        void add(int index, T e) // O(n)
        {
                assert(index >= 0 && index <= size_); // [0, size] 为插入的区间
                if (size_ >= capacity_)
                {
                        resize(2 * capacity_);
                }

                for (int i = size_ - 1; i >= index; --i) // 注意为 [SIZE -1 , INDEX ] 的元素
                {
                        data_[i + 1] = data_[i];
                }

                data_[index] = e;
                size_++;
        }

        void addFirst(T e) // O(n)
        {
                add(0, e);
        }
        void addLast(T e) // O(1)
        {
                add(size_, e);
        }

        T remove(int index) // O(n)
        {
                assert(index >= 0 && index < size_);
                T ret = data_[index];
                for (int i = index + 1; i < size_; ++i) // [index+1 , size_-1] ,  [index, size_-1) 循环不变量，还是考虑要移动元素的区间比较好理解
                {
                        data_[i - 1] = data_[i];
                }

                size_--;

                if (size_ == capacity_ / 4 && capacity_ / 2 != 0)
                        resize(capacity_ / 2);

                return ret;
        }

        T removeFirst() // O(n)
        {
                return remove(0);
        }
        T removeLast() // O(1)
        {
                return remove(size_ - 1);
        }
        void removeElement(T e) // O(n)
        {
                int index = find(e);
                if (index != -1)
                {
                        remove(index);
                }
        }

        void set(int index, T e) // O(1)
        {
                assert(index >= 0 && index < size_);
                data_[index] = e;
        }

        T get(int index) const // O(1)
        {
                assert(index >= 0 && index < size_);
                return data_[index];
        }

        T getLast() const // O(1)
        {
                return get(size_ - 1);
        }
        T getFirst() const // O(1)
        {
                return get(0);
        }

        int find(int e) const // O(n)
        {
                for (int i = 0; i < size_; ++i)
                {
                        if (e == data_[i])
                                return i;
                }
                return -1;
        }

        bool contains(T e) const // O(n)
        {
                return find(e) == -1;
        }

        int getCapacity() const // O(1)
        {
                return capacity_;
        }
        int getSize() const // O(1)
        {
                return size_;
        }
        bool isEmpty() const // O(1)
        {
                return size_ == 0;
        }

        void print()
        {
                std::cout << "Array: size = " << getSize() << ", capacity = " << getCapacity() << std::endl;
                toPrint();
                std::cout << std::endl;
        }

        void toPrint()
        {
                std::cout << "[";
                for (int i = 0; i < size_; ++i)
                {
                        std::cout << data_[i];
                        if (i != size_ - 1)
                        {
                                std::cout << ", ";
                        }
                }
                std::cout << "]";
        }

        void swap(int i, int j)
        {
                assert(i >= 0 && i < size_ && j >= 0 && j < size_);
                T t = data_[i];
                data_[i] = data_[j];
                data_[j] = t;
        }

        T &operator[](int index)
        {
                return data_[index];
        }

        void clear()
        {
                size_ = 0;
        }

        // bool operator< (const MyArray& rhs )
        // {
        //         return this

        // }
};

#endif