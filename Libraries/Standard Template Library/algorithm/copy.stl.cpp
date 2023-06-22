#include <algorithm>
#include <list>
#include <vector>
#include "../../DevTools/devtools.cpp"

using namespace std;

int main()
{
    list<int> l1,l2;
    vector<int>::iterator Iter1, iter2;
    vector<int> v1, v2;

    for(int i=0;i<15;i++)
    {
        l1.push_back(i);
        v1.push_back(i);
    }

    for(int i=0;i<15;i++)
    {
        l2.push_back(0);
        v2.push_back(0);
    }
    copy(l1.begin(),l1.end(),l2.begin());

    copy(v1.begin(),v1.end(),v2.begin());

    printListCSV(l2);
    cout << endl;

    for(Iter1 = v1.begin(); Iter1!= v1.end(); Iter1++)
    {
        cout << *Iter1 << " ";
    }

    cout << endl;

    for(Iter1 = v2.begin(); Iter1!= v2.end(); Iter1++)
    {
        cout << *Iter1 << " ";
    }
    
}