#ifndef MY_LINKED_LIST_HPP
#define MY_LINKED_LIST_HPP
#include <cassert>
#include <iostream>
//  优点：真正动态
//  缺点：没有随机访问能力
//  与数组不同，在头部插入为O(1)，在尾部插入为O(n)
template <typename T>
class MyLinkedList
{
private:
        struct MyNode
        {
                MyNode(T v) : val(v), next(nullptr)
                {
                }
                T val;
                MyNode *next;
        };

        MyNode *dummy_head_; //  采用一个哑节点，统一了在任意位置插入和删除元素的逻辑
        int size_;

        MyNode *movePrevious(int index)
        {
                MyNode *prev = dummy_head_;
                for (int i = 0; i < index; ++i) // 从头结点的前一个元素移动，所以移动index次
                {
                        prev = prev->next;
                }

                return prev;
        }

        MyNode *moveTo(int index)
        {
                MyNode *prev = movePrevious(index);
                return prev->next;
        }

public:
        MyLinkedList()
        {
                dummy_head_ = new MyNode(-1);
                dummy_head_->next = nullptr;
                size_ = 0;
        }

        //  在 index的位置插入元素
        void add(int index, T val)
        {
                assert(index >= 0 && index <= size_); // 可以在尾部插入
                MyNode *prev = movePrevious(index);
                MyNode *new_node = new MyNode(val);
                new_node->next = prev->next;
                prev->next = new_node;
                size_++;
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
                MyNode *prev = movePrevious(index);
                T ret = prev->next->val;

                MyNode *delete_MyNode = prev->next;
                prev->next = delete_MyNode->next;
                delete delete_MyNode;

                size_--;

                return ret;
        }

        T removeFirst()
        {
                return remove(0);
        }
        T removeLast()
        {
                return remove(size_ - 1);
        }
        void removeElement(T val)
        {
                MyNode *prev = dummy_head_;
                while (prev->next != nullptr)
                {
                        if (prev->next->val == val)
                        {
                                MyNode *delete_MyNode = prev->next;
                                prev->next = delete_MyNode->next;
                                delete delete_MyNode;
                                size_--;
                                break;
                        }
                        prev = prev->next;
                }
        }

        void removeAllElement(T val)
        {
                MyNode *prev = dummy_head_;
                while (prev->next != nullptr)
                {
                        if (prev->next->val == val)
                        {
                                MyNode *delete_MyNode = prev->next;
                                prev->next = delete_MyNode->next;
                                delete delete_MyNode;
                                size_--;
                        }
                        else
                        {
                                prev = prev->next;
                        }
                }
        }

        void set(int index, T val)
        {
                assert(index >= 0 && index < size_);
                MyNode *cur = moveTo(index);
                cur->val = val;
        }

        void setFirst(T val)
        {
                set(0, val);
        }

        void setLast(T val)
        {
                set(size_ - 1, val);
        }

        T get(int index)
        {
                assert(index >= 0 && index < size_);
                MyNode *cur = moveTo(index);
                return cur->val;
        }
        T getFirst()
        {
                assert(size_ > 0);
                return dummy_head_->next->val;
        }
        T getLast()
        {
                assert(size_ > 0);
                MyNode *cur = movePrevious(size_);
                return cur->val;
        }

        int getSize()
        {
                return size_;
        }

        bool isEmpty()
        {
                return dummy_head_->next == nullptr;
        }

        bool contains(T val)
        {
                MyNode *prev = dummy_head_;
                while (prev->next != nullptr)
                {
                        if (prev->next->val == val)
                                return true;
                        prev = prev->next;
                }
                return false;
        }

        void print()
        {
                std::cout << "LinkedList: size = " << getSize() << std::endl;
                std::cout << "Head ";
                toPrint();
        }

        void toPrint()
        {
                MyNode *cur = dummy_head_->next;
                for (int i = 0; i < size_; ++i)
                {
                        std::cout << cur->val;
                        cur = cur->next;
                        if (i < size_ - 1)
                        {
                                std::cout << "->";
                        }
                }
                std::cout << "->nullptr " << std::endl;
        }
}

;

#endif
