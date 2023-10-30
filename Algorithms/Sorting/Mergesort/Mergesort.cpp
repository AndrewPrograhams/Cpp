#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

/**
 * 
 *  The merge sort algorithm takes the problem of sorting and sub-divides it into many problems of the simplest form.
 * 
 *  Desirable properties arise when a problem is broken down into subproblems that are of the simplest form. 
 *  In merge sort's case, the desireable property that arises is a result of three factors.
 * 
 *  1. After the base case is solved, the sub array is sorted.
 *  2. Both of the arrays that are passed to the merge function are sorted.
 *  3. Merging the two sorted arrays into a single array is done in linear time. 
 * 
 *  These factors combined give mergesort the desirable O(nlog(n)) runtime. The first factor gives rise
 *  to the possibility of conceiving the second factor, which gives rise to the possibility of conceiving the third.
 * 
 *  There is no guarantee that a programmer will have the insight to understand that certain properties of the
 *  base case might give rise to clever recursive solutions, however the following line of thinking might be helpful.
 * 
 *  State the property of the base case then add the phrase "therefore" to the end of it.
 *  
 *  "After the base case is solved the sub arrays are sorted, therefore..." 
 * 
 *   Exploit the information you know about the algorithm. We know that we need to merge the subarrays of
 *   the base cases together. Connect the dots between what you know needs to happen and the properties of the base case.
 * 
 *  "After the base case is solved the sub arrays are sorted, therefore when they are passed to the merge function
 *   they are sorted, therefore..."
 *  
 *  This can prime the mind to begin thinking divergently. Take a hypothesis and analyze it. This is where intuition and
 *  the ability to come up with various creative possibilities is used. Consider possibilities. Consider what it would mean
 *  if you were able to spend some resources to maintain the the desirable property of the base case during recursion.
 *     
 *   "After the base case is solved the sub arrays are sorted, therefore when they are passed to the merge function
 *   they are sorted, therefore combining the two arrays into a single sorted array can be done in linear time."
 *  
 * 
 *  ""
*/

void swap(vector<int> &arr)
{
    int temp = arr[1];
    arr[1] = arr[0];
    arr[0] = temp;
}

/**
 * The merge function takes advantage of the fact that the conceptual "two arrays" are sorted. It does not perform checks between
 * elements that are in the same array. It creates a new array and, step by step, fills it with the values in order. In doing so,
 * the number of operations performed by the merge function becomes n, where n is start-n. 
*/
void merge(vector<int>& arr, int start,int mid, int end)
{
    vector<int> aux(arr.begin()+start,arr.begin()+end+1); //n time

    int i = 0; // if we want to access items in the first array, we need an iterator that will start from zero and progress toward the end.
    int j = mid-start+1; // j represents the index to start at *for the second array* we are merging.
    int k = start; // k is where in the main array we are placing the elements we are merging.

    // i <= mid-start specifies where in the first array we 

    while(i <=mid-start && j <= end-start) 
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

    while(i <= mid - start)
    {
        arr[k] = aux[i];
        i++;
        k++;
    }

    while(j <= end - start)
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


    mergeSortHelper(arr,start,partition); // Sort the left side
    mergeSortHelper(arr,partition+1,end); // Sort the right side

    merge(arr,start,partition,end); //merge them

}

void merge_sort(vector<int> &arr)
{
    mergeSortHelper(arr,0,arr.size()-1);
}


int main(int argc, char *argv[])
{
    vector<int> test = {6,5,4,3,2,1,7};
    merge_sort(test);
    for(int i=0;i<test.size();i++)
    {
        cout << test[i] << endl;
    }
}






