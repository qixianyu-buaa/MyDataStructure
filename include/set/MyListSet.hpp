#ifndef MY_LIST_SET_HPP
#define MY_LIST_SET_HPP
#include "set/MySet.hpp"
#include "list/MyLinkedList.hpp"

template <typename T>
class MyListSet : public MySet<T>
{
private:
        MyLinkedList<T> *list_;

public:
        MyListSet()
        {
                list_ = new MyLinkedList<T>();
        }
        ~MyListSet()
        {
                delete list_;
        }
        void add(T val)
        {
                if (contains(val))
                        return;
                list_->addFirst(val);
        }
        void remove(T val)
        {
                if(isEmpty())
                        return ;
                list_->removeElement(val);
        }
        bool contains(T val)
        {
                return list_->contains(val);
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
                list_->print();
        }
};

#endif