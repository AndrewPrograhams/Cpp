#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> v;

    for(int i=0;i<10;i++)
        v.push_back(i);

    int num = count_if(v.begin(),v.end(),[](int elem) { return elem%2==0;});

    cout << "There are " << num << " even numbers in the vector v.";

}