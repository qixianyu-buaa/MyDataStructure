// 2019-12-09 by qixianyu
#ifndef MY_SEGMENT_HPP
#define MY_SEGMENT_HPP
#include <iostream>
#include <cassert>
#include <vector>
// 区间是固定的,所以使用静态数组即可
// 更新和查询  O(logn)
// 采用线性数组遍历一次的需要O(n)的复杂度

//  是一个二叉树,非满非完全,但是是平衡二叉树
//  但是可以看做一个满二叉树,然后采用数组表示
//  满二叉树,最后一层的节点数,大致等于所有前层的和, 采用4n的空间肯定能存下
// e.g.
// 区间操作: 染色和查询
// 区间的统计查询

template <typename T>
struct Node;

template <typename T, template <typename U> class Node, template <typename N> class Merger>
class MySegmentTree
{
public:
private:
        std::vector<Node<T>> tree_;
        std::vector<Node<T>> array_;

public:
        MySegmentTree(std::vector<T> &v)
        {
                array_.reserve(v.size());
                for (int i = 0; i < v.size(); ++i)
                {
                        array_.push_back(Node<T>(v.at(i)));
                }

                tree_.reserve(4 * v.size());
                for (int i = 0; i < 4 * v.size(); ++i)
                {
                        tree_.push_back(Node<T>());
                }
                buildSegmentTree(0, 0, array_.size() - 1);
        }

        int getLeftChild(int i)
        {
                return 2 * i + 1;
        }

        int getRightChild(int i)
        {
                return 2 * i + 2;
        }

        int getParent(int i)
        {
                assert(i > 0);
                return (i - 1) / 2;
        }

        //  在index位置,创建表示[l,r]的线段树
        void buildSegmentTree(int index, int l, int r)
        {
                if (l == r)
                {
                        tree_.at(index) = array_.at(l);
                        return;
                }
                int left_child = getLeftChild(index);
                int right_child = getRightChild(index);

                int m = l + (r - l) / 2;

                // 递归到底
                buildSegmentTree(left_child, l, m);
                buildSegmentTree(right_child, m + 1, r);

                //  向上合并
                tree_.at(index) = Merger<Node<T>>()(tree_.at(left_child), tree_.at(right_child));
        }

        T query(int query_l, int query_r)
        {
                return query(0, 0, array_.size() - 1, query_l, query_r);
        }

        T query(int tree_index, int l, int r, int query_l, int query_r)
        {
                if (query_l == l && query_r == r)
                {
                        return tree_.at(tree_index).val_;
                }

                int left_child = getLeftChild(tree_index);
                int right_child = getRightChild(tree_index);

                int mid = l + (r - l) / 2; // mid 为树表示的区间的中点

                //  只需要查找右侧
                if (query_l >= mid + 1)
                        return query(right_child, mid + 1, r, query_l, query_r);

                //  只需要查找左侧
                if (query_r <= mid)
                        return query(left_child, l, mid, query_l, query_r);

                T l_val = query(left_child, l, mid, query_l, mid);
                T r_val = query(right_child, mid, r, mid, query_r);
                Node<T> left_node = Node<T>(l_val);
                Node<T> right_node = Node<T>(r_val);
                Node<T> res = Merger<Node<T>>()(left_node, right_node);
                return res.val_;
        }

        void set(int index, T val)
        {
                array_.at(index).val_ = val;
                set(0, 0, array_.size() - 1, index, val);
        }

        void set(int tree_index, int l, int r, int index, T val)
        {
                if (l == r)
                {
                        tree_.at(tree_index).val_ = val;
                        return;
                }

                int mid = l + (r - l) / 2;
                int left_child = getLeftChild(tree_index);
                int right_child = getRightChild(tree_index);

                if (index >= mid + 1)
                        set(right_child, mid + 1, r, index, val);

                if (index <= mid)
                        set(left_child, l, mid, index, val);

                Node<T> res = Merger<Node<T>>()(tree_.at(left_child), tree_.at(right_child));
                tree_.at(tree_index) = res;
        }

        T get(int index)
        {
                return array_.at(index);
        }

        int getSize()
        {
                return array_.size();
        }

        void print()
        {
                std::cout << "[";
                for (int i = 0; i < tree_.size(); ++i)
                {
                        if (tree_[i].isUsed_)
                        {
                                std::cout << tree_[i].val_;
                        }
                        else
                        {
                                std::cout << "NULL";
                        }
                        if (i != tree_.size() - 1)
                        {
                                std::cout << ", ";
                        }
                }
                std::cout << "]" << std::endl;
        }
};

#endif