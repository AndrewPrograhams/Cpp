#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<string> li = {"hello", "world", "foo", "new"};
    vector<string> le = {"konichiwa", "sekai", "furu", "atarashii"};

    for(auto Iter = li.begin(); Iter!=li.end();Iter++)
        cout << *Iter << " ";
    
    cout << endl;

    copy_n(li.begin(),2,le.begin());

        for(auto Iter = le.begin(); Iter!=le.end();Iter++)
        cout << *Iter << " ";

}