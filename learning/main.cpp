#include <iostream>
#include "safe_int_array.h"


int main()
{
    safe_int_array arr1(4);

    arr1.set_value(0, 12);
    arr1.set_value(1, 13);
    arr1.set_value(2, 14);

    arr1.print(std::cout);

    safe_int_array arr2(arr1);

    arr2.print(std::cout);

    safe_int_array arr3(4);
    arr3 = arr1;

    arr3.print(std::cout);

    arr1.set_value(3, 15);

    arr1.print(std::cout);
    arr3.print(std::cout);

    return 0;
}
