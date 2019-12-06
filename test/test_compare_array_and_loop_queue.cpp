#include <iostream>
#include "queue/MyArrayQueue.hpp"
#include "queue/MyLoopQueue.hpp"

template <typename T>
double testQueue(T *queue, int opCount)
{
        clock_t startTime = clock();
        srand(66);
        for (int i = 0; i < opCount; ++i)
        {
                queue->enQueue(rand());
        }
        for (int j = 0; j < opCount; ++j)
        {
                queue->deQueue();
        }
        clock_t endTime = clock();
        return double(endTime - startTime) / CLOCKS_PER_SEC;
}

int main()
{
        int opCount = 100000;
        MyArrayQueue<int> *arrayQueue = new MyArrayQueue<int>;
        std::cout << "ArrayQueue time: " << testQueue(arrayQueue, opCount) << " s" << std::endl;
        MyLoopQueue<int> *loopQueue = new MyLoopQueue<int>;
        std::cout << "LoopQueue time: " << testQueue(loopQueue, opCount) << " s" << std::endl;
        return 0;
}