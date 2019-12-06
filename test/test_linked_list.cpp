#include "list/MyLinkedList.hpp"

int main()
{
        MyLinkedList<int> *list = new MyLinkedList<int>;

        for (int i = 0; i < 10; ++i)
        {
                list->addLast(i);
                list->print();
        }

        list->removeFirst();
        list->print();
        list->removeLast();
        list->print();

        list->setFirst(100);
        list->print();

        list->setLast(101);
        list->print();

        delete list;
        return 0;
}