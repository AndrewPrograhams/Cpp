#include <map>
#include <set>
#include <unordered_set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <assert.h>


int largest(std::vector<int> array)
{
    int size = array.size();
    if(size == 0)
    {
        std::cout << "Array size is zero" << std::endl;
    }
    if(size == 1)
    {
        std::cout << "Array size is one" << std::endl;
    }

    int largest = array[0]; //use integer minimum
    int secondLargest = -100000; //assuming we aren't out of bounds

    for(int i=1;i<array.size();i++)
    {
        if(array[i] > largest)
            largest = array[i];

        if(array[i] > secondLargest && array[i] < largest)
        {
            std::cout << "Considering second largest element is: " << array[i] << std::endl;
            secondLargest = array[i];  
        }
    }

    return secondLargest;

}

int main()
{
    std::vector<int> test;

    for(int i=0;i<1000;i++)
        test.push_back(i);
    
    test.push_back(1001);
    
    std::cout << largest(test) << std::endl;
}