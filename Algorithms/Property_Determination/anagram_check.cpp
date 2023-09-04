#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int anagram_check(string a, string b)
{
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a == b;
}

int main()
{
    cout << anagram_check("hello_world", "world_ello");
}