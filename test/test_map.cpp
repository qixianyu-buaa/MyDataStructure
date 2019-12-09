#include "map/MyListMap.hpp"
#include "map/MyBSTMap.hpp"
#include <iostream>
using namespace std;

int main()
{

        MyListMap<int, int> list_map;
        cout << "add" << endl;
        for (int i = 0; i < 10; ++i)
        {
                list_map.add(i, i);
                list_map.print();
        }
        cout << "remove" << endl;
        for (int i = 10; i > 5; --i)
        {
                list_map.remove(i);
                list_map.print();
        }

        cout << "bst map" << endl;
        MyBSTMap<int, int> bst_map;
        cout << "add" << endl;
        for (int i = 0; i < 10; ++i)
        {
                bst_map.add(i, i);
                bst_map.print();
        }
        cout << "remove" << endl;
        for (int i = 10; i > 5; --i)
        {
                bst_map.remove(i);
                bst_map.print();
        }
}