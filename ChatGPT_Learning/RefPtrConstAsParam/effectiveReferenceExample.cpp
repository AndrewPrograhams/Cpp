#include <vector>
#include <iostream>

using namespace std;

template <typename T>
void printVector(vector<T>& vec)
{
    for(auto& element: vec)
        cout << element << " ";   
}
int main()
{
    vector<int> v = {1,2,3,4,5};
    printVector(v);
}