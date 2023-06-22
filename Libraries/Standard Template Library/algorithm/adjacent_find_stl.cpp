#include <algorithm>
#include <iostream>
#include <list>
#include "../../DevTools/devtools.cpp"

using namespace std;

bool is_thrice (int elem1, int elem2)
{
    return elem1*3 == elem2;
}

int main()
{
    list<int> list1;
    list<int>::iterator Iter;
    list<int>::iterator result1, result2, result3;

    list1.push_back(50);
    list1.push_back(15);
    list1.push_back(45);
    list1.push_back(17);
    list1.push_back(24);
    list1.push_back(24);
    list1.push_back(5);

    cout << "list1 = ( ";

    for(Iter=list1.begin(); Iter != list1.end(); Iter++)
        cout << *Iter << " ";
    
    cout << ")" << endl;

    result1 = adjacent_find(list1.begin(), list1.end());

    if(result1 == list1.end())
        cout << "There are not two adjacent elements that are equal." << endl;
    
    else
    {
        int index = distance(list1.begin(), result1);
        cout << "There are two adjacent values that are equal and they have a value of: " << *( result1 ) << ". "
            << "Their indecies are " << index << " and " << index+1 << endl;
    }

    result2 = adjacent_find(list1.begin(),list1.end(), is_thrice);

    if(result2 == list1.end())
        cout << "There are not two adjacent elements that are thrice each other." << endl;
    
    else
    {
        int index = distance(list1.begin(), result2);
        cout << "There are two adjacent values that are thrice and they have a value of: " << * ( result2) << " and " << *(next(result2))
            << " Their indecies are " << index << " and " << index + 1 << endl;
    }
    
    list1.sort();

    cout << "Sorted list1 = (";
    printListCSV(list1);
    cout << ")" << endl;

    result3 = adjacent_find(list1.begin(),list1.end(), is_thrice);

    

    if(result3 == list1.end())
        cout << "There are not two adjacent elements in the sorted list that are thrice each other." << endl;

    else
    {
        int index = distance(list1.begin(), result3);
        cout << "There are two adjacent elements in the sorted list that are thrice each other." <<
            " They have a value of " << *(result3) << " and " << *(next(result3)) << "." <<
            " Their indecies are at " << index << " and " << index+1 << endl;
    }
}
