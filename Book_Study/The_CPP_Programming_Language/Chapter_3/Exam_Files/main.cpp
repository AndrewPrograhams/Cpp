#include "Vector_test.h"
#include <iostream>

main()
{
    Vector v(5);
    for(int i=0;i!=v.size();i++){
        v[i] = i;
        std::cout << v[i] << std::endl;
    }

}