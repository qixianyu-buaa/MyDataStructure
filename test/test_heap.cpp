#include "heap/MyBinaryHeap.hpp"
#include <iostream>
using namespace std;

int main()
{

        MyArray<int>  array;
        for(int i = 0; i <  10; ++i)
        {
                array.addFirst(i);

        }
        MyBinaryHeap<int> heap;
        heap.heapify(array);
        heap.print();
        // cout << "add" << endl;
        // for (int i = 0; i < 10; ++i)
        // {
        //         heap.add(i);
        //         heap.print();
        // }
        // cout << "remove" << endl;
        // for (int i = 10; i > 5; --i)
        // {
        //         std::cout << " remove max =" <<heap.removeMax() <<std::endl;
        //         heap.print();
        // }



}