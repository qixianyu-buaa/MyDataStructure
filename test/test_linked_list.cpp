#include "list/MyLinkedList.hpp"

int main()
{
        MyLinkedList<int> *list = new MyLinkedList<int>;

        for (int i = 0; i < 10; ++i)
        {
                list->addLast(i);
                list->print();
        }

        int val = list->removeFirst();
        std::cout << "remove " << val << std::endl;
        list->print();
        
        list->removeLast();
        std::cout << "remove " << val << std::endl;
        list->print();

        list->setFirst(100);
        list->print();

        list->setLast(101);
        list->print();

        delete list;
        return 0;
}