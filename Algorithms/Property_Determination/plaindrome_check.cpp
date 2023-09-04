#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int palindrome_check(string a)
{
    string b = a;
    reverse(b.begin(),b.end());
    return b == a;
}

int main()
{
    string a = "raceczr";

    cout << palindrome_check(a);
}