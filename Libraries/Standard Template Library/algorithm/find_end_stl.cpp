#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    vector<string> v1 = {"simpe", "beepi", "slag", "glarg", "yoke", "beepe"};
    list<string> l1 = {"margl","beep","yokee"};

    list<string>::iterator begin = l1.begin();
    //advance(begin,2);
    auto Iter = find_end(v1.begin(),v1.end(),l1.begin(),l1.end(),
    [](string elem1, string elem2) {
        return elem1.length() == elem2.length(); 
        });

    vector<string> solution = {Iter,Iter+(l1.size())};

    for(string s: solution)
        cout << s << " ";
}