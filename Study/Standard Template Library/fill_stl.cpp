#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> v = {"foo", "blah", "farb", "yoke", "dale"};

    for(auto Iter: v)
        cout << Iter << " ";
    
    cout << endl;

    fill(v.begin()+2, v.end(), "hello");

    for(auto Iter: v)
        cout << Iter << " ";

}