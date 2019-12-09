#ifndef MY_BST_MAP_HPP
#define MY_BST_MAP_HPP
#include "map/MyMap.hpp"
#include <iostream>
#include <cassert>

template <typename Key, typename T>
class MyBSTMap : public MyMap<Key, T>
{
private:
        class MyNode
        {
        public:
                MyNode(Key key, T val) : key_(key), val_(val), left_child_(nullptr), right_child_(nullptr)
                {
                }
                MyNode *left_child_;
                MyNode *right_child_;
                T val_;
                Key key_;
        };

        MyNode *root_;
        int size_;

public:
        MyBSTMap()
        {
                root_ = new MyNode(Key(), T());
                size_ = 0;
        }
        ~MyBSTMap()
        {
                delete root_;
        }

        void add(Key key, T val)
        {
                root_ = add(root_, key, val);
        }

        MyNode *add(MyNode *node, Key key, T val)
        {
                if (node == nullptr)
                {
                        MyNode *new_node = new MyNode(key, val);
                        size_++;
                        return new_node;
                }
                if (key < node->key_)
                {
                        node->left_child_ = add(node->left_child_, key, val);
                }
                else if (key > node->key_)
                {
                        node->right_child_ = add(node->right_child_, key, val);
                }
                else
                {
                        // do nothing
                }
                return node;
        }

        MyNode *getMin()
        {
                assert(!isEmpty());
                return getMin(root_);
        }

        MyNode *getMin(MyNode *node)
        {
                if (node->left_child_ == nullptr)
                {
                        return node;
                }
                else
                {
                        return getMin(node);
                }
        }

        void removeMin()
        {
                assert(!isEmpty());
                root_ = removeMin(root_);
        }

        MyNode *removeMin(MyNode *node)
        {
                if (node->left_child_ == nullptr)
                {
                        MyNode *right_child = node->right_child_;
                        delete node;
                        size_--;
                        return right_child;
                }
                else
                {
                        node->left_child_ = removeMin(node->left_child_);
                        return node;
                }
        }

        MyNode *remove(MyNode *node, Key key)
        {
                if (node == nullptr)
                        return nullptr;

                if (key == node->key_)
                {
                        // 没有左孩子
                        if (node->left_child_ == nullptr)
                        {
                                MyNode *right_child = node->right_child_;
                                delete node;
                                size_--;
                                return right_child;
                        }
                        //  没有右孩子
                        else if (node->right_child_ == nullptr)
                        {
                                MyNode *left_child_ = node->left_child_;
                                delete node;
                                size_--;
                                return left_child_;
                        }
                        else
                        {
                                MyNode *successor = getMin(node->right_child_);
                                successor->left_child_ = node->left_child_;
                                successor->right_child_ = removeMin(successor->right_child_); //  size --
                                delete node;
                                return successor;
                        }
                }

                else if (key < node->key_)
                {
                        node->left_child_ = remove(node->left_child_, key);
                        return node;
                }

                else
                {
                        node->right_child_ = remove(node->right_child_, key);
                        return node;
                }
        }

        void remove(Key key)
        {
                assert(!isEmpty());
                root_ = remove(root_, key);
        }

        void set(Key key, T val)
        {
                set(root_, key, val);
        }

        MyNode *set(MyNode *node, Key key, T val)
        {
                if (node == nullptr)
                        return nullptr;

                if (node->key_ == key)
                {
                        node->val_ = val;
                        return node;
                }

                else if (key < node->key_)
                {
                        node->left_child_ = set(node->left_child_, key, val);
                }

                else
                {
                        node->right_child_ = set(node->right_child_, key, val);
                }
                return node;
        }

        T get(Key key)
        {
                T res;
                root_ = get(root_, key, res);
                return res;
        }

        MyNode *get(MyNode *node, Key key, T &val)
        {
                if (node == nullptr)
                        return nullptr;

                if (node->key_ == key)
                {
                        val = node->val_;
                }
                else if (key < node->key_)
                {
                        node->left_child_ = get(node->left_child_, key, val);
                }
                else
                {
                        node->right_child_ = get(node->right_child_, key, val);
                }

                return node;
        }

        bool contains(Key key)
        {
                return contains(root_, key);
        }

        bool contains(MyNode *node, Key key)
        {
                if (node == nullptr)
                        return false;
                if (node->key_ == key)
                        return true;
                else if (key < node->key_)
                        return contains(node->left_child_, key);
                else
                {
                        return contains(node->right_child_, key);
                }
        }

        int getSize()
        {
                return size_;
        }
        bool isEmpty()
        {
                return size_ == 0;
        }

        void InOrder()
        {

                InOrder(root_);
                std::cout << std::endl;
        }

        void InOrder(MyNode *node)
        {
                if (node == nullptr)
                        return;

                else
                {
                        InOrder(node->left_child_);
                        std::cout << "{ " << node->key_ << ", " << node->val_ << "} ";
                        InOrder(node->right_child_);
                }
        }

        void print()
        {
                InOrder();
        }
};

#endif