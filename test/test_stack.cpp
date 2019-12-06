#include "stack/MyArrayStack.hpp"

int main()
{
        MyArrayStack<int> *stack = new MyArrayStack<int>;

        for(int i = 0 ; i < 10 ; ++i)
        {
                stack->push(i);
        }
        stack->print();

        return 0;
}