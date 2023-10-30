#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>

using namespace std;

/**
 * Reflection
 * 
 * 1. Forgot how to initialize a copy of the array from a given starting point to a given end. Reviewed syntax.
 * 
 * 2. Some hesitation around i,j,k variables in merge function. Eventually figured it out. (j should be (mid-start)+1)
 * 
 * 3. Mixed up end-start expression in while loop of merge function. Did end-mid. Fixed in review.
 * 
 * 4. Base case for mergeSortHelper function was wrong. I did it based on array size but I should do it based on 
 *    end and start of the function. 
 * 
 * 5. The partition was incorrectly calculated. I did it based on array size but I should have done it based on end and
 *    start of the function. start + (end-start)/2;
 * 
 * 6. Arguments passed to merge function were incorrect in the left hand case. Should partition the right array with a mid of
 *    partition + 1, because the left array is partitioned until partition. 
 * 
 * 7. merge_sort function was called using arr.size() but should use arr.size() - 1 for the end value. This is because we are passing
 *    indexes to the helper function.
*/

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> aux(arr.begin()+start, arr.begin() + end + 1);

    int i = 0;
    int j = (mid-start)+1;
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
        i++;
        k++;
    }
    while(j <= end-start)
    {
        arr[k] = aux[j];
        j++;
        k++;
    }
}

void mergeSortHelper(vector<int>& arr, int start, int end)
{

    if(end-start <= 0)
        return;
    
    int partition = start + (end-start)/2;

    mergeSortHelper(arr,start,partition);
    mergeSortHelper(arr,partition+1,end);

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