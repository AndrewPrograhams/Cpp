#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
 * Reflection:
 * 
 * 1. When writing the merge function, I forgot to start by making the copy of the array. I fixed it when I realized.
 *    This is a minor mishap.
 * 
 * 2. When working the problem I was able to use my understanding of the algorithm to discern the proper values for
 *    various variables and loop conditions.
*/

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> aux(arr.begin() + start, arr.begin() + end + 1);

    int i = 0;
    int j = mid-start+1; // This represents the index we will start at for the second array.
    int k = start;

    while(i <= mid-start && j <= end-start)
    {
        if(aux[i] < aux[j])
        {
            arr[k] = aux[i];
            i++;
        }
        else
        {
            arr[k] = aux[j];
            j++;
        }
        k++;
    }
    while(i <= mid-start)
    {
        arr[k] = aux[i];
        k++;
        i++;
    }
    while(j <= end-start)
    {
        arr[k] = aux[j];
        k++;
        j++;
    }
}

void mergeSortHelper(vector<int>& arr, int start, int end)
{
    if(end-start <= 0)
        return;
    
    int partition = start + (end-start)/2;

    mergeSortHelper(arr, start, partition);
    mergeSortHelper(arr, partition+1, end);

    merge(arr,start,partition,end);
}

void merge_sort(vector<int>& arr)
{
    mergeSortHelper(arr,0,arr.size()-1);
}

int main()
{
    vector<int> test_array = {6,3,2,1,6,7,8};
    merge_sort(test_array);
    for(int a: test_array)
        cout << a;
}