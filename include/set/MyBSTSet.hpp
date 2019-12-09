#ifndef MY_BST_SET_HPP
#define MY_BST_SET_HPP
#include "tree/MyBST.hpp"
#include "set/MySet.hpp"

//  集合 去重，快速查找

template <typename T>
class MyBSTSet : public MySet<T>
{
private:
        MyBST<T> *bst_;

public:
        MyBSTSet()
        {
                bst_ = new MyBST<T>();
        }
        ~MyBSTSet()
        {
                delete bst_;
        }
        void add(T val)
        {
                if (contains(val))
                        return;
                bst_->add(val);
        }
        void remove(T val)
        {
                if (isEmpty())
                        return;
                bst_->remove(val);
        }
        bool contains(T val)
        {
                return bst_->contains(val);
        }
        int getSize()
        {
                return bst_->getSize();
        }
        bool isEmpty()
        {
                return bst_->isEmpty();
        }
        void print()
        {
                bst_->inOrder();
        }
};

#endif