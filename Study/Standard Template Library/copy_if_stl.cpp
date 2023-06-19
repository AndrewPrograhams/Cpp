#include <algorithm>
#include <list>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    list<string> L;
    list<string> L2;

    L.push_back("hello");
    L.push_back(" ");
    L.push_back("World");

    L2.push_back("foo");
    L2.push_back(",");
    L2.push_back("goo");

    auto has_whitespace = [](string str) {return (str.find(' ') == std::string::npos); };

    copy_if(L.begin(),L.end(),L2.begin(),has_whitespace);

    for(auto Iter = L2.begin(); Iter!= L2.end(); Iter++)
        cout << *Iter << endl;

}