#include <list>
#include <iostream>
#include <algorithm>
#include <vector>
#include "../../DevTools/devtools.cpp"


using namespace std;

int main()
{
    list<int> L;
    list<int>::iterator iter;
    vector<int> a;
    
    for(int i=1; i<16; i+=2)
        L.push_back(i);

    cout << "L = (";
    printListCSV<int>(L);
    cout << ")" << endl;
    auto is_odd = [](int elem) { return (elem%2!=0); };
    auto is_even = [](int elem) { return (elem%2==0); };

    bool isodd = all_of(L.begin(), L.end(), is_odd);
    bool iseven = all_of(L.begin( ), L.end(), is_even);

    cout << isodd << endl;
    cout << iseven << endl;

}