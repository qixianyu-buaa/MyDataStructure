#ifndef MY_BINARY_HEAP_HPP
#define MY_BINARY_HEAP_HPP
#include "array/MyArrary.hpp"
#include <cassert>
#include <iostream>
//  二叉堆是：1）一棵完全二叉树 2）孩子小于 或者大于父亲
//  在堆操作中需要维护这两个性质
//  父亲和孩子的关系  左侧 =2*i +1,其余的可以推出来
// 添加的时候，上浮要判断不是根节点
// 删除的时候，只能删除最大或者最小的元素，下沉要找孩子中最大/最小的元素交换

//  与树相关的操作: O(logn)
//  heapify: O(n)

template <typename T>
class MyBinaryHeap
{
        MyArray<T> *array_;

public:
        MyBinaryHeap()
        {
                array_ = new MyArray<T>;
        }

        ~MyBinaryHeap()
        {
                delete array_;
        }

        int getSize()
        {
                return array_->getSize();
        }
        bool isEmpty()
        {
                return array_->isEmpty();
        }

        int getParent(int i)
        {
                assert(i > 0);
                return (i - 1) / 2;
        }

        int getLeftChild(int i)
        {
                assert(i >= 0);
                return 2 * i + 1;
        }

        int getRightChild(int i)
        {
                assert(i >= 0);
                return 2 * i + 2;
        }

        //  在数组尾部添加节点,然后执行sitfUp操作
        void add(T val)
        {
                array_->addLast(val);
                siftUp(getSize() - 1);
        }

        //  如果不是根节点,并且比爹大,上浮
        void siftUp(int k)
        {
                while (k > 0 && (*array_)[getParent(k)] < (*array_)[k]) // k>0 保证不是根节点
                {
                        array_->swap(getParent(k), k);
                        k = getParent(k);
                }
        }

        T getMax()
        {
                assert(!isEmpty());
                return (*array_)[0];
        }

        //  把根节点替换为最后一个节点,然后siftDown
        T removeMax()
        {
                assert(!isEmpty());
                T res = getMax();
                array_->swap(0, getSize() - 1);
                array_->removeLast();

                siftDown(0);
                return res;
        }

        void siftDown(int k)
        {
                while (getLeftChild(k) < getSize()) //  如果有右孩子，肯定有左孩子,所以判断左孩子即可
                {
                        int j = getLeftChild(k);
                        if (j + 1 < getSize() && (*array_)[j] < (*array_)[j + 1])
                                j = j + 1;

                        if ((*array_)[j] <= (*array_)[k])
                        {
                                break;
                        }

                        array_->swap(k, j);
                        k = j;
                }
        }

        void print()
        {
                array_->print();
        }

        T replace(T val)
        {
                T res = getMax();
                array_->set(0, val);
                siftDown(0);
                return res;
        }

        void heapify(MyArray<T> &array) // O(n)
        {
                array_->clear();
                for (int i = 0; i < array.getSize(); ++i)
                {
                        array_->addLast(array[i]);
                }
                // 找最后一个节点的父节点, 然后依次siftDown
                int last = array.getSize() - 1;
                int last_parent = getParent(last);
                while (last_parent >= 0)
                {
                        siftDown(last_parent);
                        last_parent--;
                }
        }
};

#endif