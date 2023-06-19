#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    vector<string> li = {"hello", "hello", "world", "furu", "foo"};
    cout << count(li.begin(), li.end(), "hello");
}