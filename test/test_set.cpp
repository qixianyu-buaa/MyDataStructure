#include "set/MyListSet.hpp"
#include "set/MyBSTSet.hpp"
#include <iostream>
using namespace std;

int main()
{

        MyListSet<int> list_set;
        cout << "add" << endl;
        for (int i = 0; i < 10; ++i)
        {
                list_set.add(i);
                list_set.print();
        }
        cout << "remove" << endl;
        for (int i = 10; i > 5; --i)
        {
                list_set.remove(i);
                list_set.print();
        }

        cout << "bst set" << endl;
        MyBSTSet<int> bst_set;
        cout << "add" << endl;
        for (int i = 0; i < 10; ++i)
        {
                bst_set.add(i);
                bst_set.print();
        }
        cout << "remove" << endl;
        for (int i = 10; i > 5; --i)
        {
                bst_set.remove(i);
                bst_set.print();
        }
}