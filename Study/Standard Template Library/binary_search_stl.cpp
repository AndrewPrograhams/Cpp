#include <algorithm>
#include <list>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

bool mod_lesser(int elem1, int elem2)
{
    if(elem1 < 0)
        elem1 = -elem1;
    if(elem2 < 0)
        elem2 = -elem2;
    
    return elem1 < elem2;
}

int main()
{


    list<int> List1;

    List1.push_back(50);
    List1.push_back(10);
    List1.push_back(30);
    List1.push_back(25);
    List1.push_back(5);

    List1.sort();

    cout << "List1 = ( ";
    for(auto Iter: List1)
        cout << Iter << " ";
    
    cout << ")" << endl;

    if(binary_search(List1.begin(),List1.end(),10))
        cout << "List1 contains the element 10" << endl;
    else   
        cout << "List1 does not contain the element 10";
    
    List1.sort(greater<int>());

    if( binary_search(List1.begin(), List1.end(), 10, greater<int>()))
        cout << "There is an element with value greater than 10 in List1" << endl ;
    else
        cout << "There is no such element with value greater than 10 in List1" << endl;
    
    vector<int> v1;

    for (auto i = -2; i<= 4 ; ++i)
    {
        v1.push_back(i);
    }

    sort(v1.begin(),v1.end(),mod_lesser);

    cout << "Ordered using mod_lesser, vector v1 = ( ";
    for (auto Iter : v1)
        cout << Iter << " ";
    cout << ")" << endl;

    if (binary_search(v1.begin(),v1.end(), -3, mod_lesser))
        cout << "There is an element with a value equivalent to -3 using mod_lesser.";
    else
        cout << "There is no element with a value equivalent to -3 using mod_lesser.";


}

