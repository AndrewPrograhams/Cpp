#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<string> l = {"foo", "blarg", "hello", "zebra", "dash"};
    sort(l.begin(),l.end());
    cout << is_sorted(l.begin(),l.end());
}