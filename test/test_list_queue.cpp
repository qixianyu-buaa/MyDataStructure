#include "queue/MyListQueue.hpp"

int main()
{
        MyListQueue<int> *list = new MyListQueue<int>;
        for (int i = 0; i < 10; ++i)
        {
                list->enQueue(i);
                list->print();
        }

        for (int i = 0; i < 10; ++i)
        {
                list->deQueue();
                list->print();
        }

        delete list;
        return 0;
}