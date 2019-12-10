#include "tree/MySegmentTree.hpp"
#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
        Node() : isUsed_(false)
        {
        }
        Node(T val) : val_(val), isUsed_(true) {}

        bool isUsed_;
        T val_;
};

template <typename Node>
class Merger
{
public:
        Node operator()(Node &lhs, Node &rhs)
        {
                if (lhs.isUsed_ && rhs.isUsed_)
                        return Node(lhs.val_ + rhs.val_);

                if (lhs.isUsed_)
                        return lhs;

                if (rhs.isUsed_)
                        return rhs;

                return Node();
        }
};

int main()
{
        int arr[] = {1, 3, 5};
        std::vector<int> v(begin(arr), end(arr));
        std::cout << v.size() << std::endl;
        MySegmentTree<int, Node, Merger> seg_tree(v);
        seg_tree.print();

        std::cout << seg_tree.query(0, 1) << std::endl; //4

        seg_tree.set(2, 10);
        seg_tree.print();
}