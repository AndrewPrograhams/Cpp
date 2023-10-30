#include <algorithm>
#include <iostream>
#include <vector>

int longestIncreasingSubsequence(std::vector<int> arr)
{
    int arr_length = arr.size();
    std::vector<int> sequence_array(arr_length,1);
    
    for(int i=0;i<arr_length;i++)
    {
        int largest = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && largest < sequence_array[j] + 1)
            {
                sequence_array[i] = sequence_array[j] + 1;
                largest = sequence_array[j] + 1;
            }       
        }
        sequence_array[i] = largest;
    }

    
    return *std::max_element(sequence_array.begin(),sequence_array.end());
}

int main()
{
    std::cout << longestIncreasingSubsequence(std::vector<int>({1,2,3,4})) << std::endl;
}