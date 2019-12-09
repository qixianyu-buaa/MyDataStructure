// 2019-12-08  by qixianyu
#ifndef MY_BST_HPP
#define MY_BST_HPP
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <cassert>
//  大部分递归实现的二叉搜索树
//  增删改查的复杂度为O(h),其中h为树的高度,最坏情况下,退化为链表,复杂度为O(n)

template <typename T>
class MyBST
{
private:
        class MyNode
        {
        public:
                MyNode(T val) : val_(val), left_child_(nullptr), right_child_(nullptr)
                {
                }
                MyNode *left_child_;
                MyNode *right_child_;
                T val_;
        };

        MyNode *root_;
        int size_;

public:
        MyBST() : root_(nullptr), size_(0)
        {
        }

        MyBST(std::vector<T> &e) : root_(nullptr), size_(0)
        {
                for (auto iter = e.begin(); iter != e.end(); ++iter)
                        add(*iter);
        }

        int getSize()
        {
                return size_;
        }

        bool isEmpty()
        {
                return root_ == nullptr;
        }

        void add(T val)
        {
                root_ = add(root_, val);
        }

        MyNode *add(MyNode *node, T val)
        {
                //  1. 基本问题
                if (node == nullptr)
                {
                        MyNode *add_node = new MyNode(val);
                        size_++;
                        return add_node;
                }
                //  2. 分解问题
                if (node->val_ == val) // 不支持添加相同的元素
                {
                }
                else if (val < node->val_)
                {
                        node->left_child_ = add(node->left_child_, val);
                }
                else //  val > node->val_
                {
                        node->right_child_ = add(node->right_child_, val);
                }
                return node;
        }

        void preOrder()
        {
                std::cout << "Pre-order:[ ";
                preOrder(root_);
                std::cout << "]" << std::endl;
        }

        void preOrderWithStack()
        {
                std::stack<MyNode *> s;
                if (root_)
                        s.push(root_);
                std::cout << "Pre-order with stack:[ ";
                while (!s.empty())
                {
                        MyNode *cur = s.top();
                        std::cout << cur->val_ << " ";
                        s.pop();
                        if (cur->right_child_)
                                s.push(cur->right_child_);
                        if (cur->left_child_)
                                s.push(cur->left_child_);
                }
                std::cout << "]" << std::endl;
        }

        void preOrder(MyNode *node)
        {
                if (node == nullptr)
                        return;

                std::cout << node->val_ << " ";
                preOrder(node->left_child_);
                preOrder(node->right_child_);
        }

        void inOrder()
        {
                std::cout << "In-order:[ ";
                inOrder(root_);
                std::cout << "]" << std::endl;
        }

        void inOrder(MyNode *node)
        {
                if (node == nullptr)
                        return;

                inOrder(node->left_child_);
                std::cout << node->val_ << " ";
                inOrder(node->right_child_);
        }

        void postOrder()
        {
                std::cout << "Post-order:[ ";
                postOrder(root_);
                std::cout << "]" << std::endl;
        }

        void postOrder(MyNode *node)
        {
                if (node == nullptr)
                        return;

                postOrder(node->left_child_);
                postOrder(node->right_child_);
                std::cout << node->val_ << " ";
        }

        void levelOrderWithQueue()
        {
                std::cout << "Level-order with queue:[ ";

                std::queue<MyNode *> q;
                if (root_ == nullptr)
                        return;
                q.push(root_);
                while (!q.empty())
                {
                        MyNode *cur = q.front();
                        q.pop();
                        std::cout << cur->val_ << " ";
                        if (cur->left_child_)
                                q.push(cur->left_child_);
                        if (cur->right_child_)
                                q.push(cur->right_child_);
                }
                std::cout << "]" << std::endl;
        }

        bool contains(T val)
        {
                return contains(root_, val);
        }

        bool contains(MyNode *node, T val) // O(lgn)
        {
                if (node == nullptr)
                        return false;
                if (val == node->val_)
                        return true;
                if (val < node->val_)
                {
                        return contains(node->left_child_, val);
                }
                else
                {
                        return contains(node->right_child_, val);
                }
        }

        T removeMax()
        {
                assert(!isEmpty());
                T res;
                root_ = removeMax(root_, res);
                return res;
        }

        MyNode *removeMax(MyNode *node, T &val) // 把最大值的左子树挂接到删除节点前驱的右子树上
        {
                if (node->right_child_ == nullptr)
                {
                        MyNode *left_child = node->left_child_;
                        val = node->val_;
                        delete node;
                        size_--;
                        return left_child;
                }
                node->right_child_ = removeMax(node->right_child_, val);
                return node;
        }

        T removeMin()
        {
                assert(!isEmpty());
                T res;
                root_ = removeMin(root_, res);
                return res;
        }

        MyNode *removeMin(MyNode *node, T &val)
        {
                if (node->left_child_ == nullptr)
                {
                        MyNode *right_child = node->right_child_;
                        val = node->val_;
                        delete node;
                        size_--;
                        return right_child;
                }

                node->left_child_ = removeMin(node->left_child_, val);
                return node;
        }

        T getMinVal()
        {
                return getMin()->val_;
        }

        T getMaxVal()
        {
                return getMax()->val_;
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
                return getMin(node->left_child_);
        }

        MyNode *getMax()
        {
                assert(!isEmpty());
                return getMax(root_);
        }

        MyNode *getMax(MyNode *node)
        {
                if (node->right_child_ == nullptr)
                {
                        return node;
                }
                return getMax(node->right_child_);
        }

        //  删除只有左孩子的节点，删除只有右孩子的节点，删除有左右孩子的节点
        //  Hibbard Deletion

        void remove(const T & val)
        {
                assert(!isEmpty());
               root_ =  remove(root_,val);
        }

        MyNode *remove(MyNode *node, const T &val)
        {
                if (node == nullptr)
                {
                        return nullptr;
                }
                if (val == node->val_)
                {
                        //  只有右孩子
                        if (node->left_child_ == nullptr)
                        {
                                MyNode *right_child = node->right_child_;
                                delete node;
                                size_--;
                                return right_child;
                        }
                        //  只有左孩子
                        if (node->right_child_ == nullptr)
                        {
                                MyNode *left_child = node->left_child_;
                                delete node;
                                size_--;
                                return left_child;
                        }
                        //  两个孩子都有
                        MyNode *successor = new MyNode(getMin(node->right_child_)->val_);
                        T t;
                        successor->right_child_ = removeMin(node->right_child_,t); // 在此处size--了
                        successor->left_child_ = node->left_child_;
                        delete node;
                        return successor;
                }

                if (val < node->val_)
                {

                        node->left_child_ = remove(node->left_child_, val);
                        return  node;
                }
                else //  (val > node->val_)
                {
                        node->right_child_ = remove(node->right_child_,val);
                        return node;
                }
        }
};

#endif