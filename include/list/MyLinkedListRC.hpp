#ifndef MY_LINKED_LIST_RC_HPP
#define MY_LINKED_LIST_RC_HPP
#include <cassert>
#include <iostream>
//  采用递归方法实现的链表
//  优点：真正动态
//  缺点：没有随机访问能力
//  与数组不同，在头部插入为O(1)，在尾部插入为O(n)
template <typename T>
class MyLinkedListRC
{
private:
        struct MyNode
        {
                MyNode(T v) : val_(v), next_(nullptr)
                {
                }
                T val_;
                MyNode *next_;
        };

        MyNode *head_;
        int size_;

public:
        MyLinkedListRC()
        {
                head_ = nullptr;
                size_ = 0;
        }

        //  在 index的位置插入元素, index \in [0,size]
        void add(int index, T val)
        {
                assert(index >= 0 && index <= size_); // 可以在尾部插入
                head_ = add(head_, index, val);
        }

        MyNode *add(MyNode *node, int index, T val)
        {
                if (index == 0)
                {
                        MyNode *cur = new MyNode(val);
                        cur->next_ = node;
                        size_++;
                        return cur;
                }

                node->next_ = add(node->next_, --index, val);
                return node;
        }

        void addFirst(T val)
        {
                add(0, val);
        }
        void addLast(T val)
        {
                add(size_, val);
        }

        T remove(int index)
        {
                assert(index >= 0 && index < size_);
                T res;
                head_ = remove(head_, index, res);
                return res;
        }

        MyNode *remove(MyNode *node, int index, T &val)
        {
                if (index == 0)
                {
                        val = node->val_;
                        MyNode *res = node->next_;
                        delete node;
                        size_--;
                        return res;
                }
                node->next_ = remove(node->next_, --index, val);

                return node;
        }

        T removeFirst()
        {
                return remove(0);
        }
        T removeLast()
        {
                return remove(size_ - 1);
        }
        void removeAllElement(T val)
        {
                head_ = removeAllElement(head_, val);
        }

        MyNode *removeAllElement(MyNode *node, T val)
        {
                // basic problem
                if (node == nullptr)
                        return node;

                // 子问题
                MyNode *res = removeAllElement(node->next_, val);

                if (node->val_ == val)
                {
                        delete node;
                        size_--;
                        return res;
                }

                else
                {
                        node->next_ = res;
                        return node;
                }
        }

        int getSize()
        {
                return size_;
        }

        bool isEmpty()
        {
                return head_ == nullptr;
        }

        bool contains(T val)
        {
                return contains(head_, val);
        }
        bool contains(MyNode *node, T val)
        {
                if (node == nullptr)
                        return false;
                if (node->val_ == val)
                        return true;

                return contains(node->next_, val);
        }

        void print()
        {
                std::cout << "LinkedList: size = " << getSize() << std::endl;
                std::cout << "Head ";
                toPrint();
        }

        void toPrint()
        {
                MyNode *cur = head_;
                for (int i = 0; i < size_; ++i)
                {
                        std::cout << cur->val_;
                        cur = cur->next_;
                        if (i < size_ - 1)
                        {
                                std::cout << "->";
                        }
                }
                std::cout << "->nullptr " << std::endl;
        }

        void set(int index, T val)
        {
                assert(index >= 0 && index < size_);
                set(head_, index, val);
        }
        void setFirst(T val)
        {
                set(0, val);
        }
        void setLast(T val)
        {
                set(size_ - 1, val);
        }

        MyNode *set(MyNode *node, int index, T val)
        {
                if (index == 0)
                {
                        node->val_ = val;
                        return node;
                }
                node->next_ = set(node->next_, --index, val);

                return node;
        }

        T get(int index)
        {
                assert(index >= 0 && index < size_);
                T res;
                head_ = get(head_, index, res);
                return res;
        }

        T getFirst()
        {
                return get(0);
        }
        T getLast()
        {
                return get(size_ - 1);
        }

        MyNode *get(MyNode *node, int index, T &val)
        {
                if (index == 0)
                {
                        val = node->val_;
                        return node;
                }
                node->next_ = get(node->next_, --index, val);
                return node;
        }
}

;

#endif
