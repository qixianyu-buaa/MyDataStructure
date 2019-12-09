#include "tree/MyBST.hpp"
using namespace std;
int main()
{
        int arr[] = {1, 3, 2, 4, 0, 9};
        std::vector<int> v(begin(arr), end(arr));
        MyBST<int> *bst = new MyBST<int>(v);

        bst->preOrder();
        bst->preOrderWithStack();
        bst->inOrder();
        bst->postOrder();
        bst->levelOrderWithQueue();

        std::cout << "Size=" << bst->getSize() << std::endl;
        std::cout << bst->contains(1) << std::endl;
        std::cout << bst->contains(11) << std::endl;
        std::cout << bst->getMaxVal() << std::endl;
        std::cout << bst->getMinVal() << std::endl;

        bst->levelOrderWithQueue();
        int min_val = bst->getMinVal();
        int max_val = bst->getMaxVal();

        bst->remove(3);
        // std::cout << "Remove max=" << bst->removeMax() << std::endl;
        std::cout << "Remove 3:" << std::endl;
        std::cout << "Size=" << bst->getSize() << std::endl;

        bst->inOrder();
        bst->preOrder();

        // bst->remove(min_val);
        // std::cout << "Remove min=" << bst->removeMin() << std::endl;
        // std::cout << "Remove min:" << std::endl;
        // std::cout << "Size=" << bst->getSize() << std::endl;

        bst->inOrder();
        bst->preOrder();

        delete bst;
}