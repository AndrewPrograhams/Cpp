#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> v = {"foo", "blah", "blarg", "yoke", "beep"};

    for(auto Iter: v)
        cout << Iter << " ";
    
    cout << endl;

    fill_n(v.begin(), 2, "bloke");

    for(auto Iter:v)
        cout << Iter << " ";
    
    
    
}