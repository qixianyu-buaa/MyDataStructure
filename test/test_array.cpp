#include "array/MyArrary.hpp"

int main()
{
        MyArray<int> array;

        for (int i = 0; i < 10; ++i)
        {
                array.addLast(i);
        }
        int i = array.find(9);
        std::cout << i << std::endl;

        array.remove(0);

        array.print();

        return 0;
}