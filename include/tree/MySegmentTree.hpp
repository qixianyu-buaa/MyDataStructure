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

template <typename T, typename Merger>
class MySegmentTree
{
public:
        struct Node
        {
                Node() : isUsed_(false)
                {
                }
                Node(T val) : val_(val), isUsed(true) {}

                bool isUsed_;
                T val_;
        };
private:
        std::vector<Node> tree_;
        std::vector<Node> array_;

public:
        MySegmentTree(std::vector<T> &v)
        {
                array_.reserve(v.size());
                for (int i = 0; i < v.size(); ++i)
                {
                        array_.push_back(Node(v.at(i)));
                }

                tree_.reserve(4 * v.size());
                buildSegmentTree(0, 0, array_.size() - 1);
        }

        int getLeftChild(int index)
        {
                return 2 * i + 1;
        }

        int getRightChild(int index)
        {
                return 2 * i + 2;
        }

        int getParent(int index)
        {
                assert(index > 0);
                return (i - 1) / 2;
        }

        //  在index位置,创建表示[l,r]的线段树
        void buildSegmentTree(int index, int l, int r)
        {
                if (l == r)
                {
                        tree_.at(index) = array_.at(index);
                        return;
                }
                int left = getLeftChild(index);
                int right = getRightChild(index);

                int mid = left + (right - left) / 2;

                buildSegmentTree(left, left, mid);
                buildSegmentTree(right, mid + 1, right);

                tree_.at(index) = Merger(tree_.at(left), tree_.at(right));
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
                        if (tree_[i].isUsed)
                        {
                                std::cout << tree[i];
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