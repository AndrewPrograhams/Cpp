#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

vector<int> merge(vector<int> left, vector<int> right)
{
    vector<int> result;
    while(left.size() > 0 && right.size() > 0)
    {
        if(left[0] <= right[0])
        {
            result.push_back(left[0]);
            left.erase(left.begin());
        }
        else
        {
            result.push_back(right[0]);
            right.erase(right.begin());
        }
    }
    if(left.size() > 0)
        result.insert(result.end(),left.begin(),left.end());
    if(right.size() > 0)
        result.insert(result.end(),right.begin(),right.end());

    return result;
}

vector<int> merge_sort(vector<int> arr)
{
    vector<int> left;
    vector<int> right;
    if(arr.size() <= 1)
        return arr;

    int middle = arr.size()/2;
    for(int i=0;i<middle;i++)
        left.push_back(arr[i]);
    
    for(int i = middle;i<arr.size();i++)
        right.push_back(arr[i]);

    left = merge_sort(left);
    right = merge_sort(right);

    return merge(left, right);

}




int main(int argc, char *argv[])
{
    vector<int> test = {6,5,4,3,2,1,7};
    test = merge_sort(test);
    for(int i=0;i<test.size();i++)
    {
        cout << test[i] << endl;
    }
}






