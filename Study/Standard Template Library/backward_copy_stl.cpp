#include <vector>
#include <algorithm>
#include <iostream>

int main()
{
    using namespace std;
    vector<int> v1, v2;
    vector<int>::iterator Iter1, Iter2;

    for(int i=0;i<10;i++)
        v1.push_back(i*3);
    
    for(int i=0;i<15;i++)
        v2.push_back(i*4);
    
    //copy elements 4-7 into positions 9 through 7 in v2
    copy_backward(v1.begin()+3,v1.begin() +7, v2.begin()+9);

    for(Iter1 = v2.begin(); Iter1 != v2.end(); Iter1++)
    {
        cout << *Iter1 << " ";
    }


}