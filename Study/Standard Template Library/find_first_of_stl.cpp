#include <algorithm>
#include <list>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

void gen_windows(string str, vector<string> *windows)
{
    while(str.length() >= 2)
    {
        windows->push_back(str.substr(0,2));
        str.erase(0,1);
    }
}

bool contains_at_least_two_adj(string one, string two)
{
    vector<string> windows;
    vector<string> *windowsPtr = &windows;
    gen_windows(two,windowsPtr);

    for(string s: windows)
    {
        cout << s << " ";
    }

    for(string s: windows)
    {
        cout << "window is " << s << endl;
        cout << "word is " << one << endl;
        if(one.find(s)!=string::npos)
        {
            cout << one << " contains substr " + s << endl;
            return true;
        }
            
    }

    return false;
}

int main()
{
    vector<string> v = {"blah", "yoke", "beep", "fooe"};
    list<string> l =  {"ep","oe"};

    auto beginIter = find_first_of(v.begin(),v.end(),l.begin(),l.end(),contains_at_least_two_adj);

    cout << *beginIter << endl;

    vector<string> solution = {beginIter, beginIter+l.size()};

    cout << "Solution = (";

    for(auto i = solution.begin(); i!= solution.end(); ++i)
    {
        if(i==prev(solution.end()))
            cout << *i;
        else
            cout << *i << ",";    
    }

    cout << ")" << endl;
    

}