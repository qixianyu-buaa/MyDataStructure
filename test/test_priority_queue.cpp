#include "queue/MyPriorityQueue.hpp"
#include "map/MyBSTMap.hpp"
#include <iostream>
using namespace std;

int main()
{
        MyPriorityQueue<int> q;
        for (int i = 0; i < 10; ++i)
        {
                q.enQueue(i);
                q.print();
        }

        for (int i = 0; i < 10; ++i)
        {
                std::cout << "remove max = " << q.deQueue() <<std::endl;
                q.print();
        }

        return 0;
}