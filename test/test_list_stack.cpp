#include "stack/MyListStack.hpp"

int main()
{
        MyListStack<int> *stack = new MyListStack<int>;
        for (int i = 0; i < 10; ++i)
        {
                stack->push(i);
                stack->print();
        }

        for (int i = 0; i < 10; ++i)
        {
                stack->pop();
                stack->print();
        }

        delete stack;
        return 0;
}