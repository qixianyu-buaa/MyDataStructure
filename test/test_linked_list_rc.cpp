#include "list/MyLinkedListRC.hpp"

int main()
{
        MyLinkedListRC<int> *list = new MyLinkedListRC<int>;

        for (int i = 0; i < 10; ++i)
        {
                list->addLast(i % 5);
                list->print();
        }

        int val = list->removeFirst();
        std::cout << "remove " << val << std::endl;
        list->print();

        val = list->removeLast();
        std::cout << "remove " << val << std::endl;
        list->print();

        val = 1;
        list->removeAllElement(val);
        std::cout << "remove all val=" << val << std::endl;
        list->print();

        std::cout << list->contains(val) << std::endl;
        std::cout << list->contains(val + 1) << std::endl;

        list->set(val, 1);
        list->print();

        val = list->get(1);
        std::cout << val << std::endl;

        std::cout << "first= " << list->getFirst() << std::endl;
        std::cout << "last= " << list->getLast() << std::endl;

        delete list;
        return 0;
}