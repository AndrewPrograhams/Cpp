#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * Reflection:
 * 
 *      1. I tried two separate approaches that did not work before I asked GPT for guidance.
 *      2. These two solutions were over complicated, taking too many parameters into consideration.
 *      3. These other solutions tried to be iterative, working with two indexes to create sub arrays.
 *      4. I was under the false notion that a subsequence had to be consequtive. I can move forward by understanding terms better.
 *      5. I am frustrated, but as I gain more exposure to recursive algorithms I will improve.
 *      6. When you have branching possibilities, you might have to create recursive calls that traverse those branches.
 *      7. When finding the largest anything, you probably have to do max(recurse(),recurse()) or something like that. 
*/

//Explore every single subsequence. This should be n^2 time.
int longest_increasing_subsequence(vector<int>& arr, int i, int v){

    if(i==arr.size())
        return 0;

    else if(i==0 || arr[i] > v){
        return 1 + 
            max(
                longest_increasing_subsequence(arr,i+1,arr[i+1]), // the LIS including the element i + 1 (If we include it, v becomes it)
                longest_increasing_subsequence(arr,i+1,arr[i]) // the LIS excluding the element i (if we exclude, v remains the same)
         );
    }

    else
        return longest_increasing_subsequence(arr,i+1,arr[i]);
}

int main(){

    vector<int> test = {1,4,2,4,4};
    cout << longest_increasing_subsequence(test,0,test[0]);

}

/**
 * if(j >= arr.size())
        return 0;
    
    if(v < arr[j]){
        return 1 + longest_increasing_subsequence(arr,i,j+1,arr[j]);
    }

    return longest_increasing_subsequence(arr,i+1,j, arr[i+1]);
*/


/*
    //base case
    if(j - i <= 0)
        return 0;

    //if we are at size one.
    else if( j - i == 1){
        if(arr[i] < arr[j]){
            return 1 + longest_increasing_subsequence(arr,i+1,j+1,arr[j]);
        }
    }   
    else{
        return longest_increasing_subsequence(arr,i,j-1,v);
    } 
*/