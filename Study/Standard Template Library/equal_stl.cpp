#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    vector<int> v = {1,2,3,4,5};
    list<int> l = {2,4,6,8,10};

    vector<int>::iterator viter;
    list<int>::iterator liter;

    bool all_elem_are_twice = equal(v.begin(),v.end(),l.begin(),[](int elem1, int elem2) { return elem1*2 == elem2; });

    if(all_elem_are_twice)
        cout << "All elements in list l are twice the value of elements in vector v";
    else
        cout << "Not all elements in list l are twice the value of elements in vector v";

}