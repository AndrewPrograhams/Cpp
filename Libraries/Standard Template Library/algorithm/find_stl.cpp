#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> L = {"foo", "blah", "blarg", "yoke", "beep"};

    auto Iter = find(L.begin(),L.end(), "MASH");

    cout << distance(L.begin(), Iter) << endl;

    Iter = find(L.begin(), L.end(), "yoke");

    cout << distance(L.begin(), Iter) << endl;

    cout << *Iter;

}