#ifndef MY_LIST_MAP_HPP
#define MY_LIST_MAP_HPP
#include "map/MyMap.hpp"
#include <iostream>

template <typename Key, typename T>
class MyListMap : public MyMap<Key, T>
{
private:
        struct MyNode
        {

                MyNode(Key k, T v) : key(k), val(v), next(nullptr)
                {
                }
                Key key;
                T val;
                MyNode *next;
        };

        MyNode *dummy_head_; //  采用一个哑节点，统一了在任意位置插入和删除元素的逻辑
        int size_;

public:
        MyListMap()
        {
                dummy_head_ = new MyNode(Key(), T());
                size_ = 0;
        }
        ~MyListMap()
        {
                delete dummy_head_;
        }
        void add(Key key, T val)
        {
                if (contains(key))
                        return;
                MyNode *node = new MyNode(key, val);
                node->next = dummy_head_->next;
                dummy_head_->next = node;
                size_++;
        }
        void remove(Key key)
        {
                MyNode *prev = dummy_head_;
                while (prev->next)
                {
                        if (prev->next->key == key)
                        {
                                MyNode *del_node = prev->next;
                                prev->next = del_node->next;
                                delete del_node;
                                size_--;
                                return;
                        }
                        prev = prev->next;
                }
        }
        void set(Key key, T val)
        {
                MyNode *prev = dummy_head_;
                while (prev->next)
                {
                        if (prev->next->key == key)
                        {
                                prev->next->val = val;
                                return;
                        }
                        prev = prev->next;
                }
        }
        T get(Key key)
        {
                MyNode *prev = dummy_head_;
                while (prev->next)
                {
                        if (prev->next->key == key)
                        {
                                return prev->next->val;
                        }
                        prev = prev->next;
                }
        }

        bool contains(Key key)
        {
                MyNode *prev = dummy_head_;
                while (prev->next)
                {
                        if (prev->next->key == key)
                        {
                                return true;
                        }
                        prev = prev->next;
                }
                return false;
        }
        int getSize()
        {
                return size_;
        }
        bool isEmpty()
        {
                return size_ == 0;
        }
        void print()
        {
                MyNode *prev = dummy_head_;
                while (prev->next)
                {
                        std::cout << prev->next->val << " ";
                        prev = prev->next;
                }
                std::cout << std::endl;
        }
};

#endif